#include "Components/HealthComponent.h"
#include "Logging/StructuredLog.h"


UHealthComponent::UHealthComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOGFMT(LogTemp, Display, "Health Component Begun Play");
}

void UHealthComponent::UpdateHealth(float Delta)
{
	const float OldHealth = Health;
	const float NewHealth = OldHealth - Delta;
	Health = NewHealth;
	OnHealthUpdated.Broadcast(OldHealth, NewHealth);
}
