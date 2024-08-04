// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceInvaderController.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;

UCLASS()
class SPACEINVADERS_API ASpaceInvaderController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void SetupInputComponent() override;


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerMovementMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	TObjectPtr<UInputAction> HorizontalMovementAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	TObjectPtr<UInputAction> VerticalMovementAction;

	UFUNCTION()
	void MoveHorizontal(const FInputActionValue& Value);	
	
	UFUNCTION()
	void MoveVertical(const FInputActionValue& Value);
	
};
