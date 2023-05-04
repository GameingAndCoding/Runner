// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerClass.h"
#include "RoadSegment.generated.h"


UCLASS()
class RUNNER_API ARoadSegment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadSegment();


	//For future use in creating an array of segments
	
	UPROPERTY(VisibleAnywhere, Category = ViewOnly);
	int index;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ListOfPossibleSegments)
	TArray<TSubclassOf<AActor>> Segments;

	UPROPERTY(VisibleAnywhere, Category = VIEWONLY)
	TArray<AActor*> SavedSegments;


	
	void SpawnSegment();
	void Clear();
	
	UPROPERTY(VisibleAnywhere, Category = VIEWONLY)
	AActor* Player;
	
	FVector Location;
	AActor* Current;

	UPROPERTY(VisibleAnywhere, Category = VIEWONLY)
	int MovedDistance;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
