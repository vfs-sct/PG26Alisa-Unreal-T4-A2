// PG26 2024


#include "Actors/LivingOrganismSpawner.h"
#include "Actors/LivingOrganism.h"
#include "Logging/StructuredLog.h"


DEFINE_LOG_CATEGORY(LivingOrganismLog)

// Sets default values
ALivingOrganismSpawner::ALivingOrganismSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnDelay = 3.0f;

}

// Called when the game starts or when spawned
void ALivingOrganismSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnHandle, this, &ALivingOrganismSpawner::Spawn, SpawnDelay, true);
	
}

// Called every frame
void ALivingOrganismSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALivingOrganismSpawner::Spawn()
{
	// Spawning 

	if (!IsValid(OrganismToSpawnClass))
	{
		return;
	}
	TObjectPtr<UWorld> World = GetWorld();

	if (IsValid(World))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		
		TObjectPtr<ALivingOrganism> NewOrganism =  World->SpawnActor<ALivingOrganism>(OrganismToSpawnClass, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);
		if (IsValid(NewOrganism))
		{
			NewOrganism->Move();
			NewOrganism->DoSomething();

			// Binding Delegates

			/*NewOrganism->SingleDelegate.BindUObject(this, &ALivingOrganismSpawner::MyFloatFunction);
			NewOrganism->SingleReturnDelegate.BindUObject(this, &ThisClass::MyBoolRetFunction);*/
			NewOrganism->MulticastDelegate.AddUObject(this, &ThisClass::SpawnSFX);
			NewOrganism->MulticastDelegate.AddUObject(this, &ThisClass::SpawnVFX);
			/*NewOrganism->DynamicDelegateWithToParams.BindDynamic(this, &ThisClass::MyFloatBoolFunction);*/
			/*NewOrganism->DynamicDelegateWithRetValue.BindDynamic(this, &ThisClass::Add);*/
			NewOrganism->MyMulticastDynamicDelegate.AddUniqueDynamic(this, &ThisClass::PlayExplosion);
		}
	}
}

void ALivingOrganismSpawner::MyFloatFunction(float MyFloat)
{
	UE_LOGFMT(LivingOrganismLog, Display, "My Single Cast Delegate {0}", MyFloat);
}

bool ALivingOrganismSpawner::MyBoolRetFunction()
{
	UE_LOGFMT(LivingOrganismLog, Display, "My Single Cast Ret Value Delegate Called");

	return false;
}


void ALivingOrganismSpawner::MyFloatBoolFunction(float Param1, bool Param2)
{
	UE_LOGFMT(LivingOrganismLog, Display, "My Dynamic Delegate With Two Parameters Called {0} {1}", Param1, Param2);
}

int32 ALivingOrganismSpawner::Add(int32 Param1, int32 Param2)
{
	UE_LOGFMT(LivingOrganismLog, Display, "My Dynamic Delegate With Two Parameters and Ret Value Called {0} {1}", Param1, Param2);

	return Param1 + Param2;
}

