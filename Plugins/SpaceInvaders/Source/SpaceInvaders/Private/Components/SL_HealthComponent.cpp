// PG26 2024


#include "Components/SL_HealthComponent.h"

// Sets default values for this component's properties
USL_HealthComponent::USL_HealthComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void USL_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USL_HealthComponent::UpdateHealth(float Delta)
{
	const float OldHealth = Health;
	const float NewHealth = OldHealth - Delta;
	Health = NewHealth;
	OnHealthUpdated.Broadcast(OldHealth, NewHealth);
}


