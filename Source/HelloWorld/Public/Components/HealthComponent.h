#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthEvent, float, OldHealth, float, NewHealth);

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class HELLOWORLD_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// constructor
	UHealthComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 10.0f;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float Delta);

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthUpdated;
};
