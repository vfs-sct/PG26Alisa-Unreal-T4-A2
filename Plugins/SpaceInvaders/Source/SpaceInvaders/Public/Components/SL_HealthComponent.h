// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SL_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthEvent, float, OldHealth, float, NewHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEINVADERS_API USL_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USL_HealthComponent(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 10.0f;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float Delta);

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthUpdated;

		
};
