// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowedCharacter.h"


// Sets default values
AFollowedCharacter::AFollowedCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFollowedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

