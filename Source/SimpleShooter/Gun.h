// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere) USceneComponent* Root;
	UPROPERTY(VisibleAnywhere) USkeletalMeshComponent* Mesh;
//VFX
	UPROPERTY(EditAnywhere) UParticleSystem* MuzzleFlash;
	UPROPERTY(EditAnywhere) UParticleSystem* HitPoint;
//SFX
	UPROPERTY(EditAnywhere) USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere) USoundBase* HitSound;


//Gun Information
	UPROPERTY(EditAnywhere) float MaxRange = 10000.f;
	UPROPERTY(EditAnywhere) float Damage = 10.f;

	bool GunTrace(FHitResult& Hit, FVector& ShortDirection);
	AController* GetOwnerController() const;
};
