// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tanks.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATanks : public ABasePawn
{
	GENERATED_BODY()
	
public:

	void Move(float Value);
	void Turn(float Value);
	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 350.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TurnRate = 150.f;


private:
	ATanks();
	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* Arm;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* Camera;








};
