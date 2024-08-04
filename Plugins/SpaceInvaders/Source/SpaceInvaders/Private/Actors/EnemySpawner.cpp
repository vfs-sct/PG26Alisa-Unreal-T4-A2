// PG26 2024


#include "Actors/EnemySpawner.h"

#include "Actors/Enemy.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnDelay = 3.0f;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnHandle, this, &AEnemySpawner::Spawn, SpawnDelay, true);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::Spawn()
{
	if (!IsValid(EnemyToSpawnClass))
	{
		return;
	}
	TObjectPtr<UWorld> World = GetWorld();

	if (IsValid(World))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		FVector PlayerLocation = World->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		FVector PlayerRotation = World->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
		FVector SpawnLocation = FVector(PlayerLocation.X + 1000, PlayerLocation.Y, PlayerLocation.Z);
		FRotator SpawnRotation = (PlayerRotation*-1).Rotation();
		
		TObjectPtr<AEnemy> NewEnemy =  World->SpawnActor<AEnemy>(EnemyToSpawnClass, SpawnLocation, SpawnRotation , SpawnParams);
		if (IsValid(NewEnemy))
		{
			NewEnemy->Move();
			
		}
	}
}

