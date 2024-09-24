// Fill out your copyright notice in the Description page of Project Settings.


#include "Tanks.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

ATanks::ATanks()
{
    Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
    Arm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(Arm);

    
}

void ATanks::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATanks::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATanks::Turn);
    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATanks::Fire);
}

void ATanks::Move(float Value)
{   
	FVector DeltaLocation(0.f);
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATanks::Turn(float Value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;
    //Yaw = Value * DeltaTime * TurnRate
    DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalRotation(DeltaRotation, true);
}

void ATanks::Fire()
{
    
	FRotator SpawnRotation = FRotator::ZeroRotator;
    FVector SpawnBulletLocation = FVector(500,0,130);
    for(int i = 0; i < 10; i++)
    {
        GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnBulletLocation, SpawnRotation );
        UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnBulletLocation.ToString());
        i++;
    }
   // GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnBulletLocation, SpawnRotation );
   // UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnBulletLocation.ToString());

    // if(SpawnPoint != nullptr)
    // {
    //     FVector SpawnLocation = SpawnPoint->GetComponentLocation();
    //     FRotator SpawnRotation = SpawnPoint->GetComponentRotation();
    //     //SpawnBulletLocation = FVector(500,0,130);

    //     FActorSpawnParameters SpawnParams;
    //     SpawnParams.Owner = this;

    //     GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
    //     UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnBulletLocation.ToString());
    // }
}