// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Move(FVector Direction)
{
	FVector DeltaLocation(0.f);
	DeltaLocation.X = Direction.Y * MoveSpeed * GetWorld()->DeltaTimeSeconds;

	AddActorLocalOffset(DeltaLocation);

}

void ATank::Rotate(FVector Direction)
{
	FQuat DeltaRotation = FQuat::MakeFromEuler(FVector(0.f, 0.f, Direction.X * RotationSpeed * GetWorld()->DeltaTimeSeconds));

	AddActorLocalRotation(DeltaRotation);
}

void ATank::Shoot()
{
	UE_LOG(LogTemp, Display, TEXT("Shooting"));
}

