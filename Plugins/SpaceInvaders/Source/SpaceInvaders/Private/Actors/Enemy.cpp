// PG26 2024


#include "Actors/Enemy.h"
#include "Components/ArrowComponent.h"
#include "Components/SL_HealthComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Logging/StructuredLog.h"
#include "TimerManager.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<USL_HealthComponent>(TEXT("Enemy Health Component"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Body"));
	
	SetRootComponent(Body);

	Nose = CreateDefaultSubobject<UArrowComponent>(TEXT("Nose"));
	Nose->SetupAttachment(RootComponent);

	// Simulate Physics Setup
	Body->SetSimulatePhysics(true);
	// this is telling the Static Mesh Component to react to collision events
	Body->SetNotifyRigidBodyCollision(true);
	// Constraint Plane
	Body->SetConstraintMode(EDOFMode::XYPlane);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(HealthComponent))
	{
		HealthComponent->OnHealthUpdated.AddUniqueDynamic(this, &ThisClass::OnHealthUpdated);
	}

	OnActorHit.AddUniqueDynamic(this, &ThisClass::OnHit);
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();

}

void AEnemy::DoDamage_Implementation(float DamageAmount)
{
	if (IsValid(HealthComponent))
	{
		HealthComponent->UpdateHealth(DamageAmount);
	}
}


void AEnemy::OnHealthUpdated(float OldHealth, float NewHealth)
{
	if (NewHealth <= 0.0f)
	{
		Destroy();
	}
}

void AEnemy::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOGFMT(LogTemp, Display, "bumppppp");
	if (SelfActor == OtherActor)
	{
		return;
	}

	if (OtherActor->Implements<USL_DamageInterface>() && OtherActor->GetComponentByClass(USL_HealthComponent::StaticClass()))
	{
		UE_LOGFMT(LogTemp, Display, "bumppppp");
		ISL_DamageInterface::Execute_DoDamage(OtherActor, 5.0f);
	}

	Destroy();
}

void AEnemy::Move_Implementation()
{
	const FVector Velocity = Nose->GetForwardVector() * MovementSpeed;
	Body->AddForce(Velocity * Body->GetMass(), NAME_None, true);
}

