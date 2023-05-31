// Fill out your copyright notice in the Description page of Project Settings.


#include "GInteractionComponent.h"
#include "GGamePlayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGInteractionComponent::UGInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();

	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);

	FVector End = EyeLocation + (EyeRotation.Vector()* 1000);//1m far from look direction 

	FHitResult Hit;
	bool bBlockingHit = GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation,End,ObjectQueryParams);
	
	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UGGamePlayInterface>()) 
		{
			APawn* MyPawn = Cast<APawn>(MyOwner); //if change failed this variable will become null pointer
			IGGamePlayInterface::Execute_Interact(HitActor, MyPawn);
		}
	}
	
	//Draw a debug line for interact detect 
	if(bBlockingHit) DrawDebugLine(GetWorld(),EyeLocation,End,FColor::Green,false,2,0,2);
	else DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 2, 0, 2);
}

