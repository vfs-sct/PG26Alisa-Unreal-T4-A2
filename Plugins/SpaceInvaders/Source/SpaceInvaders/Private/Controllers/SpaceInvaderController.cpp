// PG26 2024


#include "Controllers/SpaceInvaderController.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"

void ASpaceInvaderController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IsValid(InputComponent))
	{
		TObjectPtr<UEnhancedInputLocalPlayerSubsystem> EnhancedInputLocalPlayerSubsystem 
		= GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		
		if (IsValid(EnhancedInputLocalPlayerSubsystem))
		{
			// adds my Character Movement Mapping Context
			EnhancedInputLocalPlayerSubsystem->AddMappingContext(PlayerMovementMappingContext, 0);
		}

		if (TObjectPtr<UEnhancedInputComponent> EnhancedInputComp = Cast<UEnhancedInputComponent>(InputComponent))
		{
			if (IsValid(HorizontalMovementAction))
			{
				EnhancedInputComp->BindAction(HorizontalMovementAction, ETriggerEvent::Triggered, this, &ThisClass::MoveHorizontal);
			}
			if (IsValid(VerticalMovementAction))
			{
				EnhancedInputComp->BindAction(VerticalMovementAction, ETriggerEvent::Triggered, this, &ThisClass::MoveVertical);
			}
		}
	}
}

void ASpaceInvaderController::MoveHorizontal(const FInputActionValue& Value)
{
	const float AxisValue = Value.Get<float>();

	if (TObjectPtr<APawn> ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput({0.0f,1.0f,0.0f}, AxisValue);
	}
}

void ASpaceInvaderController::MoveVertical(const FInputActionValue& Value)
{
	const float AxisValue = Value.Get<float>();

	if (TObjectPtr<APawn> ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput({ 1.0f,0.0f,0.0f }, AxisValue);
	}
}
