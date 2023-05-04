// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "PlayerClass.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox -> SetBoxExtent(FVector(32.f,32.f,32.f));
	CollisionBox -> SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;


	CollisionBox-> OnComponentBeginOverlap.AddDynamic(this , &AObstacle::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AObstacle::OnOverlapBegin(UPrimitiveComponent*  OverLappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp , int32 OtherBody ,bool bFromSweep,const FHitResult& SweepResult)
{

	GEngine -> AddOnScreenDebugMessage(-1 , 1.f , FColor:: Green, "Overlap Begin Called");


	Player = Cast<APlayerClass>(OtherActor);



	if (Player){ Player->Lives --;}

	
}

