// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsChaos/ImmediatePhysicsActorHandle_Chaos.h"


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
   /* if(SpawnPoint != nullptr)
    {
        FVector SpawnLocation = SpawnPoint->GetComponentLocation();
        FRotator SpawnRotation = SpawnPoint->GetComponentRotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;

        AActor* BulletSpawned = GetWorld()->SpawnActor<AActor>(BulletToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

        if(BulletSpawned)
        {
            UPrimitiveComponent* BulletMesh = BulletSpawned->FindComponentByClass<UPrimitiveComponent>();
            FVector ImpulseDirection = SpawnRotation.Vector();
            BulletMesh -> AddImpulse(ImpulseDirection * BulletImpulse);
            //GetWorld() ->GetTimerManager().SetTimer(TimerHandle, this, &ATank::Fire, 60.f); 
        }
        
        
	    
        UE_LOG(LogTemp, Warning, TEXT("Spawn location %s"), *SpawnLocation.ToString()); 
        
    }*/
}
