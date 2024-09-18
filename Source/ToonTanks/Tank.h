// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:

	void Move(float Value);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 350.f;
private:
	ATank();
	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* Arm;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* Camera;


};
