// Fill out your copyright notice in the Description page of Project Settings.


#include "SegmentOfTheRoad.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerClass.h"
// Sets default values
ASegmentOfTheRoad::ASegmentOfTheRoad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASegmentOfTheRoad::BeginPlay()
{
	Super::BeginPlay();
	
	TSubclassOf<APlayerClass> ClassToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerClass:: StaticClass(), Found);
	Player = Found[0];	
}

// Called every frame
void ASegmentOfTheRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if(Player->GetActorLocation().X > this->GetActorLocation().X && HasObstacle && !alreadyChecked)
	{
			int index = FMath::RandRange(0,100);

		if(index >75)
		{
			DestroyNext =true;
		}
		alreadyChecked = true;
	}
}

