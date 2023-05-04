// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerClass.h"
#include "PlayerClass2.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class RUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere , BlueprintReadWrite)
	class UBoxComponent* CollisionBox;

		UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent*  OverLappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp , int32 OtherBody ,bool bFromSweep,const FHitResult& SweepResult);

		UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Player)
		APlayerClass* Player;

		UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Player)
		APlayerClass2* Player2;
};
