// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "PredatorBullet.h"
#include "Actors/LivingOrganism.h"
#include "Predator.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class HELLOWORLD_API APredator : public ALivingOrganism
{
	GENERATED_BODY()

public:

	APredator();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CheckDelay;
	
	// Type of Class
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Spawn Parameters")
	TSubclassOf<APredatorBullet> BulletToSpawnClass;
	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TObjectPtr<USphereComponent> CollisionComp;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
public:
	UFUNCTION()
    void Fire(FRotator RotationToTarget, FVector LocationToSpawn);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	
	FTimerHandle CheckHandle;
	
};
