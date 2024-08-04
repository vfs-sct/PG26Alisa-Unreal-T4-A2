// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ValorantCharacter.generated.h"


class ABullet;
class UNetworkHealthComponent;

UCLASS()
class NETWORKMULTIPLAYERGAME_API AValorantCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AValorantCharacter();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Shooting")
	TSubclassOf<ABullet> BulletClassToSpawn;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Shooting")
	FName SocketToSpawnBulletFrom;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shooting", meta = (MakeEditWidget))
	FVector BulletSpawnPoint;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Shoot();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void PlayVFX();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void PlayVFX_NetMulticast();


	UFUNCTION(BlueprintImplementableEvent)
	void OnVFXPlayed();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Health Component")
	TObjectPtr<UNetworkHealthComponent> NetHealthComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
