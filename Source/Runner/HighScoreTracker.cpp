// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreTracker.h"
#include "JsonObjectConverter.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Serialization/JsonSerializer.h"


// Sets default values
AHighScoreTracker::AHighScoreTracker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHighScoreTracker::BeginPlay()
{
	Super::BeginPlay();

	
	if (TextActor)
	{
		UTextRenderComponent* TextRenderComponent = TextActor->GetTextRender();
		if (TextRenderComponent)
		{
			FString JsonString;
	
			
			TextRenderComponent->SetText(SavedText);
		}
		else
		{
			//its over
		}
	}
}

// Called every frame
void AHighScoreTracker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

