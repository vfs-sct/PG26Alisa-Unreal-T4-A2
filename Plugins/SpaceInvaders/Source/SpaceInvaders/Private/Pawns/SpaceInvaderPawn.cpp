// PG26 2024


#include "Pawns/SpaceInvaderPawn.h"
#include "Components/SL_HealthComponent.h"
#include "Controllers/SpaceInvaderController.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ASpaceInvaderPawn::ASpaceInvaderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<USL_HealthComponent>(TEXT("Living Organism Health Component"));

}

// Called when the game starts or when spawned
void ASpaceInvaderPawn::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(HealthComponent))
	{
		HealthComponent->OnHealthUpdated.AddUniqueDynamic(this, &ThisClass::OnHealthUpdated);
	}
	
}

// Called every frame
void ASpaceInvaderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpaceInvaderPawn::DoDamage_Implementation(float DamageAmount)
{
	if (IsValid(HealthComponent))
	{
		HealthComponent->UpdateHealth(DamageAmount);
	}
}

// Called to bind functionality to input
void ASpaceInvaderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpaceInvaderPawn::OnHealthUpdated(float OldHealth, float NewHealth)
{
	if (NewHealth <= 0.0f)
	{
		Destroy();
		//quit game when lose
		FGenericPlatformMisc::RequestExit(false);
	}
}

