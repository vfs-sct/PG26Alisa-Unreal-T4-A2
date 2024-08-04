// PG26 2024


#include "Actors/PredatorBullet.h"
#include "DamageInterface.h"
#include "Actors/Alien.h"
#include "Actors/Predator.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
APredatorBullet::APredatorBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));

	if (IsValid(ProjectileMovementComponent))
	{
		ProjectileMovementComponent->InitialSpeed = 80.0f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	bNetLoadOnClient = true;
	SetReplicates(true);

}

// Called when the game starts or when spawned
void APredatorBullet::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddUniqueDynamic(this, &ThisClass::OnBulletHit);
}

// Called every frame
void APredatorBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APredatorBullet::OnBulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (SelfActor == OtherActor || Cast<APredator>(OtherActor))
	{
		return;
	}

	// only do damage to alien
	if (OtherActor->Implements<UDamageInterface>() && Cast<AAlien>(OtherActor))
	{
		IDamageInterface::Execute_DoDamage(OtherActor, 5.0f);
	}

	Destroy();
}

