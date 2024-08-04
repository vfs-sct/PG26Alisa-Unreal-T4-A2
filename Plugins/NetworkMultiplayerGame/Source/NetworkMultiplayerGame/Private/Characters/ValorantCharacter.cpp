// PG26 2024


#include "Characters/ValorantCharacter.h"
#include "Actors/Bullet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine.h"
#include "Components/NetworkHealthComponent.h"

// Sets default values
AValorantCharacter::AValorantCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NetHealthComponent = CreateDefaultSubobject<UNetworkHealthComponent>(TEXT("Health Component"));
}

void AValorantCharacter::Shoot_Implementation()
{
	FActorSpawnParameters SpawnParamters;
	SpawnParamters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (TObjectPtr<UWorld> World = GetWorld())
	{
		const FVector LoactionToSpawn = GetActorLocation() + BulletSpawnPoint;
		if (IsValid(BulletClassToSpawn))
		{
			World->SpawnActor<ABullet>(BulletClassToSpawn, LoactionToSpawn, GetActorRotation(), SpawnParamters);
		}
	}
}

void AValorantCharacter::PlayVFX_Implementation()
{
	PlayVFX_NetMulticast();
}

void AValorantCharacter::PlayVFX_NetMulticast_Implementation()
{
	OnVFXPlayed();
}

// Called when the game starts or when spawned
void AValorantCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AValorantCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AValorantCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

