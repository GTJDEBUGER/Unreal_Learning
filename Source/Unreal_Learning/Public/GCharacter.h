// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GInteractionComponent.h"
#include "GCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UGInteractionComponent;

UCLASS()
class UNREAL_LEARNING_API AGCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;

public:
	// Sets default values for this character's properties
	AGCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	UGInteractionComponent* InteractionComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Player move forward (relate to camera)
	void MoveForward(float Value);
	//Player move right (relate to camera)
	void MoveRight(float Value);

	//Generate a fireball from left hand of player
	void FireballAttack();

	//Rewrite virtual function of jump
	virtual void Jump() override;

	//How player response to interact input
	void PrimaryInteract();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
