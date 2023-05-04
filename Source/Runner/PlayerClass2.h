// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "PlayerClass2.generated.h"




USTRUCT(BlueprintType)
struct FScore
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= JsonData)
	FString Score;
	
};


UCLASS()



class RUNNER_API APlayerClass2 : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	APlayerClass2();
	
	UPROPERTY(EditAnywhere, Category = MoveForward);
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, Category = MoveForward);
	float InputDirection;
	
	UPROPERTY(EditAnywhere, Category = MoveForward);
	float Speed;

	float ZPosition;
	bool isJumping;


	UPROPERTY(VisibleAnywhere, Category = VIEWONLY)
	int Lives = 3;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveCharacter(int change);
	
	UFUNCTION(BlueprintCallable, Category="Movement")
	void Jump();



	void Die();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	FScore Fscore;

};
