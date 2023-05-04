// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/TextRenderActor.h"
#include "GameFramework/Actor.h"
#include "HighScoreTracker.generated.h"

class FJsonObject;


UCLASS()
class RUNNER_API AHighScoreTracker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHighScoreTracker();
	
	UPROPERTY(EditAnywhere , Category = TextObject);
	ATextRenderActor* TextActor;
	UPROPERTY(EditAnywhere , Category = TextObject)
	FText SavedText;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
