// Fill out your copyright notice in the Description page of Project Settings.


#include "GRealBox.h"

// Sets default values
AGRealBox::AGRealBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp= CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetCollisionProfileName("RealObject");
	StaticMeshComp->SetSimulatePhysics(true);
	RootComponent = StaticMeshComp;

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

