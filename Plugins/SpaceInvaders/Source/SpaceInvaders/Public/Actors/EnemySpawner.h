// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AEnemy;

UCLASS()
class SPACEINVADERS_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnDelay;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Spawn Parameters")
	TSubclassOf<AEnemy> EnemyToSpawnClass;

	void Spawn();

private:

	FTimerHandle SpawnHandle;

};
