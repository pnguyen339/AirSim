// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMovementChar.h"

#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "FileHelper.h"
// Sets default values
ARandomMovementChar::ARandomMovementChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	counter = 0;
	path = FPaths::GameSourceDir() + "/Game/Data/myData.json";
	FFileHelper::LoadFileToString(JsonString, *path);

}

// Called when the game starts or when spawned
void ARandomMovementChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomMovementChar::Tick(float DeltaTime)
{

	float speed = .5;
	Super::Tick(DeltaTime);
	counter += 1 * DeltaTime;
	if (counter == 100) {
		choice = FMath::RandRange(0, 3);
		counter = 0;
	}
	else
		counter++;
	switch (choice)
	{
		case 0: AddMovementInput(GetActorForwardVector(), speed * 1); break;
		case 1: AddMovementInput(GetActorForwardVector(), speed *-1); break;
		case 2: AddMovementInput(GetActorRightVector(), speed *1); break;
		case 3: AddMovementInput(GetActorRightVector(), speed *-1); break;

		default:
			break;
	}
}

// Called to bind functionality to input
void ARandomMovementChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

