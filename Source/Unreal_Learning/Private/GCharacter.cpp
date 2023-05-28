// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp"); //Create spring arm component
	SpringArmComp->bUsePawnControlRotation = true; //Let spring arm can be control by pawn
	SpringArmComp->SetupAttachment(RootComponent); //Set new spring arm component follow player

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp"); //Create Camera component
	CameraComp->SetupAttachment(SpringArmComp); //Set new camera follow player

	GetCharacterMovement()->bOrientRotationToMovement = true; //Make sure player move to current face direction

	bUseControllerRotationYaw = false; //Cancel player rotate in Yaw
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch= 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}

void AGCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	//X: forward (red) Y: right (green) Z: up (blue)

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}

void AGCharacter::FireballAttack()
{
	FVector LefthandLocation = GetMesh()->GetSocketLocation("middle_01_l");

	FTransform SpawnTM=FTransform(GetControlRotation(),LefthandLocation);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass,SpawnTM, SpawnParams);
}

// Called every frame
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("FireballAttack",IE_Pressed,this, &AGCharacter::FireballAttack);
}

