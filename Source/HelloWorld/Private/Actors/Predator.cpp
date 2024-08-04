// PG26 2024


#include "Actors/Predator.h"
#include "Actors/Alien.h"
#include "Actors/PredatorBullet.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"

APredator::APredator()
{
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collison Area"));
	CollisionComp->SetupAttachment(RootComponent);
	
}

void APredator::BeginPlay()
{
	Super::BeginPlay();
	CollisionComp->OnComponentBeginOverlap.AddUniqueDynamic(this, &APredator::OnOverlapBegin);
}

void APredator::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APredator::Fire(FRotator RotationToTarget, FVector LocationToSpawn)
{
	TObjectPtr<UWorld> World = GetWorld();

	if (IsValid(World))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		if (IsValid(BulletToSpawnClass))
		{
			TObjectPtr<APredatorBullet> NewBullet =  World->SpawnActor<APredatorBullet>(BulletToSpawnClass, LocationToSpawn, RotationToTarget, SpawnParams);
		}
	}
}

void APredator::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                               int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AAlien>(OtherActor))
	{
		FRotator RotationToTarget = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),OtherActor->GetActorLocation());
		const FVector LocationToSpawn =GetActorLocation()+(RotationToTarget.Vector() * 100);
		Fire(RotationToTarget, LocationToSpawn);
		
		//DrawDebugSphere(GetWorld(),OtherActor->GetActorLocation(), 32,32,FColor::Red, false, 1.0f);
	}
}


	
