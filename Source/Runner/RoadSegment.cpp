// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadSegment.h"
#include "SegmentOfTheRoad.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARoadSegment::ARoadSegment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadSegment::BeginPlay()
{
	Super::BeginPlay();

	//const ARoadSegment* SelectedSegment = Segments[index];
	TArray<AActor*> foundPlayer;

	TSubclassOf<APlayerClass> classToFind;

	classToFind = APlayerClass::StaticClass();
	
	UGameplayStatics:: GetAllActorsOfClass( GetWorld(), classToFind  ,foundPlayer);

	Player  = foundPlayer[0];


	MovedDistance = 25000;
		
}


// Called every frame
void ARoadSegment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if( SavedSegments.Num() <50)
	{
		SpawnSegment();
	}

	
		if(Player->GetActorLocation().X > MovedDistance)
		{
			Clear();
			MovedDistance += 25000;
		}



	CheckIfDestroyNext();
}



void ARoadSegment::SpawnSegment()
{
	index =	FMath::RandRange(0, Segments.Num()-1);
	
	 Current = GetWorld()-> SpawnActor<AActor>(Segments[index] , this->GetActorLocation() + Location,this->GetActorRotation());

	SavedSegments.Add(Current);

	Location= FVector(Location.X+1000,0,0);
}


void ARoadSegment::Clear()
{
	for (int i = 0; i < 25; i++) {
			
		SavedSegments[0]->Destroy();
		SavedSegments.RemoveAt(0);
	}
}



void ARoadSegment:: CheckIfDestroyNext()
{
	for (int i = 0; i < SavedSegments.Num(); i++) {

		ASegmentOfTheRoad* temp = Cast<ASegmentOfTheRoad> (SavedSegments[i]);

		if(temp->DestroyNext)
		{
			ASegmentOfTheRoad* temporary = Cast<ASegmentOfTheRoad> (SavedSegments[i+1]);
			
			temporary -> Destroy();

			UE_LOG(LogTemp, Warning, TEXT("Hello"));
		}
		
	}
}

