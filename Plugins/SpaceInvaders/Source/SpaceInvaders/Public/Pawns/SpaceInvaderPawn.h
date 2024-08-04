// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/SL_DamageInterface.h"
#include "SpaceInvaderPawn.generated.h"

class USL_HealthComponent;

UCLASS()
class SPACEINVADERS_API ASpaceInvaderPawn : public APawn, public ISL_DamageInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceInvaderPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// override from Damage Interface
	void DoDamage_Implementation(float DamageAmount) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<USL_HealthComponent> HealthComponent;

	UFUNCTION()
	void OnHealthUpdated(float OldHealth, float NewHealth);

};
