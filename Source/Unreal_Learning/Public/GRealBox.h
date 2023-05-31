// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGamePlayInterface.h"
#include "GRealBox.generated.h"

class UStaticMeshComponent;

UCLASS()
class UNREAL_LEARNING_API AGRealBox : public AActor, public IGGamePlayInterface
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
	FVector TargetPos;

	void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	AGRealBox();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
