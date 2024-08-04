// PG26 2024


#include "Components/NetworkHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UNetworkHealthComponent::UNetworkHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxHealth = 100.0f;

	SetIsReplicatedByDefault(true);
	// ...
}


// Called when the game starts
void UNetworkHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if(TObjectPtr<AActor> OwningActor = GetOwner())
	{
		if (OwningActor->HasAuthority())
		{
			OldHealth = MaxHealth;
			Health = MaxHealth;
			OwningActor->OnTakeAnyDamage.AddUniqueDynamic(this, &ThisClass::OnDamageTaken);
		}
	}

	// ...
	
}


// Called every frame
void UNetworkHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UNetworkHealthComponent::NormaLizedHealth() const
{
	return UKismetMathLibrary::NormalizeToRange(Health, 0.0f, MaxHealth);
}

void UNetworkHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UNetworkHealthComponent, Health);
	DOREPLIFETIME(UNetworkHealthComponent, OldHealth);
	DOREPLIFETIME(UNetworkHealthComponent, MaxHealth);
}

void UNetworkHealthComponent::OnDamageTaken_Implementation(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (DamagedActor == GetOwner())
	{
		OldHealth = Health;
		Health = Health = Damage;
		OnRep_Health();
	}
}

void UNetworkHealthComponent::OnRep_Health()
{
	if (OnHealthUpdated.IsBound())
	{
		OnHealthUpdated.Broadcast(OldHealth,Health);
	}
}



