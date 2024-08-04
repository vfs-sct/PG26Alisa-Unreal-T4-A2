// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageInterface.h"
#include "LivingOrganism.generated.h"

class UHealthComponent;
class UStaticMeshComponent;
class UArrowComponent;


// Single Cast Delegates
DECLARE_DELEGATE_OneParam(FMySingleDelegateType, float);
DECLARE_DELEGATE_RetVal(bool, FMySingleDelegateWithReturnType);

// Multicast Delegates
DECLARE_MULTICAST_DELEGATE(FMyMulticastDelegate);

// Dynamic Delegates
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDynamicDelegateWithTwoParams, float, MyFloat, bool, MyBool);
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(int32, FDynamicDelegateRetValWithTwoParams, int32, MyFirstInt, int32, MySecondInt);

// Dynamic Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyDynamicMulticastDelegate);




UCLASS()
class HELLOWORLD_API ALivingOrganism : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingOrganism();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// override from Damage Interface
	void DoDamage_Implementation(float DamageAmount) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UArrowComponent> Nose;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Movement")
	float MovementSpeed;

	// required to implement in c++ with _Implementation
	UFUNCTION(BlueprintNativeEvent)
	void Move();

	// not required to implement in c++
	UFUNCTION(BlueprintImplementableEvent)
	void DoSomething();


	// Delegates
	FMySingleDelegateType SingleDelegate;

	FMySingleDelegateWithReturnType SingleReturnDelegate;

	FMyMulticastDelegate MulticastDelegate;

	UPROPERTY()
	FDynamicDelegateWithTwoParams DynamicDelegateWithToParams;
	UPROPERTY()
	FDynamicDelegateRetValWithTwoParams DynamicDelegateWithRetValue;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FMyDynamicMulticastDelegate MyMulticastDynamicDelegate;

	UFUNCTION()
	void CallEvents();

	UFUNCTION()
	void OnHealthUpdated(float OldHealth, float NewHealth);

	/*
	UFUNCTION()
	void OnLivingOrganismHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);*/
};
