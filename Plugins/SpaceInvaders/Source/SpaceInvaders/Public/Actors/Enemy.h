// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/SL_DamageInterface.h"
#include "Enemy.generated.h"

class USL_HealthComponent;
class UStaticMeshComponent;
class UArrowComponent;

UCLASS()
class SPACEINVADERS_API AEnemy : public AActor, public ISL_DamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// override from Damage Interface
	void DoDamage_Implementation(float DamageAmount) override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<USL_HealthComponent> HealthComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UArrowComponent> Nose;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Movement")
	float MovementSpeed;

	// required to implement in c++ with _Implementation
	UFUNCTION(BlueprintNativeEvent)
	void Move();

	UFUNCTION()
	void OnHealthUpdated(float OldHealth, float NewHealth);

	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	

};
