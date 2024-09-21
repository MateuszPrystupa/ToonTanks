// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"


ATank::ATank()
{
    Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
    Arm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(Arm);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::Move(float Value)
{   
	FVector DeltaLocation(0.f);
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;
    //Yaw = Value * DeltaTime * TurnRate
    DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalRotation(DeltaRotation, true);
}

void ATank::Fire()
{
	FRotator SpawnRotation = FRotator::ZeroRotator;
    SpawnBulletLocation = FVector(500,0,130);
    for(int i = 0; i < 10; i++)
    {
        GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnBulletLocation, SpawnRotation );
        UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnBulletLocation.ToString());
        i++;
    }
   // GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnBulletLocation, SpawnRotation );
   // UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnBulletLocation.ToString());
}
