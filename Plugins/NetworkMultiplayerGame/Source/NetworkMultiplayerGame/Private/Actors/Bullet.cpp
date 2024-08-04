// PG26 2024


#include "Actors/Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));

	if (IsValid(ProjectileMovementComponent))
	{
		ProjectileMovementComponent->InitialSpeed = 800.0f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	bNetLoadOnClient = true;
	SetReplicates(true);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

