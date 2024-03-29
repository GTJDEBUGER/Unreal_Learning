// Fill out your copyright notice in the Description page of Project Settings.


#include "GRealBox.h"
#include "Components/StaticMeshComponent.h"

void AGRealBox::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetWorldLocation(TargetPos);
}

// Sets default values
AGRealBox::AGRealBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);

	TargetPos = FVector(-140,0,0);
}

// Called when the game starts or when spawned
void AGRealBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGRealBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

