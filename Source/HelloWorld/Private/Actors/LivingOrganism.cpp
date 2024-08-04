// PG26 2024


#include "Actors/LivingOrganism.h"
#include "Components/HealthComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Logging/StructuredLog.h"
#include "Components/ArrowComponent.h"
#include "TimerManager.h"

// Sets default values
ALivingOrganism::ALivingOrganism()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Living Organism Health Component"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Body"));
	
	SetRootComponent(Body);

	Nose = CreateDefaultSubobject<UArrowComponent>(TEXT("Nose"));
	Nose->SetupAttachment(RootComponent);

	// Simulate Physics Setup
	Body->SetSimulatePhysics(true);
	// this is telling the Static Mesh Component to react to collision events
	Body->SetNotifyRigidBodyCollision(true);
	// Constraint Plane
	Body->SetConstraintMode(EDOFMode::XYPlane);
}

// Called when the game starts or when spawned
void ALivingOrganism::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle CallEventHandle;
	GetWorld()->GetTimerManager().SetTimer(CallEventHandle, this, &ThisClass::CallEvents, 1.0f);

	if (IsValid(HealthComponent))
	{
		HealthComponent->OnHealthUpdated.AddUniqueDynamic(this, &ThisClass::OnHealthUpdated);
	}

	/*OnActorHit.AddUniqueDynamic(this, &ThisClass::OnLivingOrganismHit);*/
}

void ALivingOrganism::DoDamage_Implementation(float DamageAmount)
{
	if (IsValid(HealthComponent))
	{
		HealthComponent->UpdateHealth(DamageAmount);
	}
}

// Called every frame
void ALivingOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();
}

void ALivingOrganism::CallEvents()
{
	// executing the delegates


	SingleDelegate.ExecuteIfBound(25.0f);

	if (SingleReturnDelegate.IsBound())
	{
		UE_LOGFMT(LogTemp, Display, "Return Value form Delegate : {0}", SingleReturnDelegate.Execute());
	}

	MulticastDelegate.Broadcast();

	DynamicDelegateWithToParams.ExecuteIfBound(20.0f, true);

	if (DynamicDelegateWithRetValue.IsBound())
	{
		UE_LOGFMT(LogTemp, Display, "Return Value form Dynamic Delegate : {0}", DynamicDelegateWithRetValue.Execute(5, 10));
	}

	MyMulticastDynamicDelegate.Broadcast();
}

void ALivingOrganism::OnHealthUpdated(float OldHealth, float NewHealth)
{
	if (NewHealth <= 0.0f)
	{
		Destroy();
	}
}

void ALivingOrganism::Move_Implementation()
{
	UE_LOGFMT(LogTemp, Display, "Moving");

	const FVector Velocity = Nose->GetForwardVector() * MovementSpeed;
	Body->AddForce(Velocity * Body->GetMass(), NAME_None, true);
}

