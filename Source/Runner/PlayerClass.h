// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlayerClass2.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "PlayerClass.generated.h"


USTRUCT(BlueprintType)
struct FScore2
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= JsonData)
	FString Score;
	
};


UCLASS(Blueprintable)
class RUNNER_API APlayerClass : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerClass();
	
	UPROPERTY(EditAnywhere, Category = MoveForward);
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, Category = MoveForward);
	float InputDirection;
	
	UPROPERTY(EditAnywhere, Category = MoveForward);
	float Speed;

	float ZPosition;
	bool isJumping;

	bool GameOver;
	

	UPROPERTY(VisibleAnywhere, Category = VIEWONLY)
	int Lives = 3;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveCharacter(int change);
	
	UFUNCTION(BlueprintCallable, Category="Movement")
	void Jump();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveCharacter2Player(int change);
	
	UFUNCTION(BlueprintCallable, Category="Movement")
	void Jump2Player();
	
	UFUNCTION(BlueprintCallable, Category="Player2")
		void SpawnPlayer2();

	
	void Die();

	UPROPERTY(EditAnywhere, Category = OtherPlayer);
	TSubclassOf<AActor> SpawnThis;

	UPROPERTY(EditAnywhere, Category = OtherPlayer);
	AActor* Player2Instance;
	
	UPROPERTY(EditAnywhere, Category = OtherPlayer);
	APlayerClass2* Player2Class;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	FScore2 Fscore;

};
