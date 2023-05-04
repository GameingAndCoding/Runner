// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerClass2.h"
#include "JsonObjectConverter.h"
#include "JsonObjectConverter.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"


// Sets default values
APlayerClass2::APlayerClass2()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerClass2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerClass2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isJumping && ZPosition< 400)
	{
		ZPosition+= 9.8;
			
	}else if(isJumping && ZPosition >= 400){

		isJumping = false;
			
	}else if (!isJumping && ZPosition >0)
	{

		ZPosition-=  9.8;
	}
	

	CurrentLocation = FVector(GetActorLocation().X + Speed,GetActorLocation().Y,ZPosition);
	
	SetActorLocation(CurrentLocation);

	Speed += 0.005;


	if(Lives <= 0)
	{
		Die();
	}

}


void APlayerClass2:: MoveCharacter( int change)
{

	if(InputDirection + change == 2 ||InputDirection + change == -2 )
	{
		change = 0;
	}
	InputDirection  = InputDirection +change;
	
	CurrentLocation = FVector( GetActorLocation().X,333 *InputDirection ,ZPosition);
	SetActorLocation(CurrentLocation);
	
}
void APlayerClass2:: Jump()
{

	if(ZPosition <5 )
	{
		isJumping = true;	
	}
	
}





// Called to bind functionality to input
void APlayerClass2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void APlayerClass2:: Die()
{

	Fscore.Score = FString::FromInt(CurrentLocation.X);


	

	FString HighScore =  FString::FromInt(CurrentLocation.X);
	FJsonObjectConverter::UStructToJsonObjectString(Fscore,HighScore);
	FFileHelper::SaveStringToFile(*HighScore,  *(FPaths::ProjectDir() + TEXT("/Json/Test.json")));
	UE_LOG(LogTemp, Warning, TEXT("Died"));
	UGameplayStatics::OpenLevel(this,"GameOver", false);
}

