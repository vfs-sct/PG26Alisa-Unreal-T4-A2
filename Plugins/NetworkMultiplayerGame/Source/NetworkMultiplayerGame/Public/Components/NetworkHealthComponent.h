// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NetworkHealthComponent.generated.h"

class UDamageType;
class AController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthEventSignature, float, OldHealth, float, NewHealth);
UCLASS( ClassGroup=(StatComponents),Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class NETWORKMULTIPLAYERGAME_API UNetworkHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNetworkHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Health Component")
	float Health;

	UPROPERTY(BlueprintReadOnly, Replicated ,EditAnywhere, Category = "Health Component")
	float OldHealth;
	UPROPERTY(BlueprintReadOnly, Replicated , EditAnywhere, Category = "Health Component")
	float MaxHealth;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float NormaLizedHealth() const;
	// Required for Networked Properties
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION(BlueprintNativeEvent)
	void OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	UFUNCTION()
	void OnRep_Health();

	UPROPERTY(BlueprintAssignable, BlueprintReadOnly, Category="Health Component")
	FHealthEventSignature OnHealthUpdated;

		
};
