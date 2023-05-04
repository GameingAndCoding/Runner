// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "SegmentOfTheRoad.generated.h"



UCLASS()
class RUNNER_API ASegmentOfTheRoad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASegmentOfTheRoad();



	UPROPERTY(EditAnywhere , Category = HasObstacle);
	bool HasObstacle;

	
	UPROPERTY(EditAnywhere , Category = Player);
	AActor* Player;
	UPROPERTY(EditAnywhere , Category = Player);
	TArray<AActor*> Found;

	UPROPERTY(EditAnywhere , Category = READONLY);
	bool DestroyNext;
	

	bool alreadyChecked;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
