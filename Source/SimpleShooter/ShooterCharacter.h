// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage (float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure) bool IsDead() const; 
	UFUNCTION(BlueprintPure) float GetHealthPercent() const;
	void Shoot();

private:
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveRight(float AxisValue);
	void LookRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	

	UPROPERTY(EditAnywhere, Category = "Gun") float RotationRate = 10;
	UPROPERTY(EditDefaultsOnly, Category = "Gun") TSubclassOf<AGun> GunClass;

	UPROPERTY() AGun* Gun;

	UPROPERTY(EditDefaultsOnly, Category = "Health") float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, Category = "Health") float Health;
};
