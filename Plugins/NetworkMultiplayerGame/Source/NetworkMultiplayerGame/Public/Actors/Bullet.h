// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class NETWORKMULTIPLAYERGAME_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BulletMesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
