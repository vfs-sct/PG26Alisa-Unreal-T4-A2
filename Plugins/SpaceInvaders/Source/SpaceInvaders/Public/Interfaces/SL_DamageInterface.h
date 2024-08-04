// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SL_DamageInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USL_DamageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACEINVADERS_API ISL_DamageInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void DoDamage(float DamageAmount);
};
