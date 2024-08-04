// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LivingOrganismSpawner.generated.h"

class ALivingOrganism;

DECLARE_LOG_CATEGORY_EXTERN(LivingOrganismLog, Log, All)

UCLASS()
class HELLOWORLD_API ALivingOrganismSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingOrganismSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnDelay;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Type of Class
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Spawn Parameters")
	TSubclassOf<ALivingOrganism> OrganismToSpawnClass;

	void Spawn();


	UFUNCTION()
	void MyFloatFunction(float MyFloat);

	UFUNCTION()
	bool MyBoolRetFunction();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnSFX();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnVFX();

	UFUNCTION()
	void MyFloatBoolFunction(float Param1, bool Param2);

	UFUNCTION()
	int32 Add(int32 Param1, int32 Param2);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayExplosion();

private:

	FTimerHandle SpawnHandle;
};
