// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorItem.generated.h"

UCLASS()
class BLOCKS_API AActorItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void move(float time);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	FVector curLoc;
	FVector newVector;
	float currentTime;
	float lowBound;
	float highBound;
};
