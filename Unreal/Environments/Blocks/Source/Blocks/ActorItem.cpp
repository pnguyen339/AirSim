// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorItem.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
//#include
//#include "../../Plugins/AirSim/Source/AirLib/include/controllers/Settings.h"

// Sets default values
AActorItem::AActorItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	Mesh->SetStaticMesh(StaticMesh.Object);
	currentTime = 0;
}

// Called when the game starts or when spawned
void AActorItem::BeginPlay()
{
	Super::BeginPlay();
	curLoc = GetActorLocation();
	newVector = GetActorLocation();
	lowBound = curLoc.X - 300;
	highBound = curLoc.X + 300;
}


void AActorItem::move(float time) {
	if (curLoc.X > newVector.X)
	{
		curLoc.X -= time;
	}
	else
		curLoc.X += time;

	if (curLoc.Y > newVector.Y)
	{
		curLoc.Y -= time;
	}
	else
		curLoc.Y += time;

	if (curLoc.Z > newVector.Z)
	{
		curLoc.Z -= time;
	}
	else
		curLoc.Z += time;
}
// Called every frame
void AActorItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	currentTime = currentTime + 1 * DeltaTime;
	curLoc = GetActorLocation();
	FVector low = newVector - FVector(2, 2, 2);
	FVector hi = newVector + FVector(2, 2, 2);
	if (currentTime >=  DeltaTime) {
		if ( (curLoc.X < hi.X) && (curLoc.Y < hi.Y) && (curLoc.Z < hi.Z) &&
			(curLoc.X > low.X) && (curLoc.Y > low.Y) && (curLoc.Z > low.Z)) {
			//newVector = curLoc + FVector(FMath::RandRange(Settings::getFloat("lowerRange", -300),Settings::getFloat("highRange", 300)),
			//							 FMath::RandRange(Settings::getFloat("lowerRange", -300), Settings::getFloat("highRange", 300)),
			//							 FMath::RandRange(Settings::getFloat("lowerRange", -300), Settings::getFloat("highRange", 300)));
			newVector = curLoc + FVector(FMath::RandRange(-300, 300), FMath::RandRange(-300, 300), FMath::RandRange(-300, 300));

			move(1);
			SetActorLocation(curLoc, false);
		}
		else {
			move(1);
			SetActorLocation(curLoc, false);
		}
		currentTime = 0.f;
	}
	

}