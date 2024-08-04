// PG26 2024

#include "Actors/Alien.h"

#include "Actors/Predator.h"
#include "Components/ArrowComponent.h"
#include "Components/HealthComponent.h"

AAlien::AAlien()
{
}

void AAlien::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddUniqueDynamic(this, &ThisClass::OnHit);
}

void AAlien::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAlien::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (SelfActor == OtherActor)
	{
		return;
	}

	if (OtherActor->Implements<UDamageInterface>() && Cast<APredator>(OtherActor))
	{
		IDamageInterface::Execute_DoDamage(OtherActor, 5.0f);
	}
}