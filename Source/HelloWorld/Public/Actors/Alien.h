// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/LivingOrganism.h"
#include "Alien.generated.h"


/**
 * 
 */
UCLASS()
class HELLOWORLD_API AAlien : public ALivingOrganism
{
	GENERATED_BODY()

public:

	AAlien();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
