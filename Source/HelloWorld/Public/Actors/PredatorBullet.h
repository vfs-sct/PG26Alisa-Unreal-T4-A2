// PG26 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PredatorBullet.generated.h"

class UProjectileMovementComponent;

UCLASS()
class HELLOWORLD_API APredatorBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APredatorBullet();

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

	UFUNCTION()
	void OnBulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

};
