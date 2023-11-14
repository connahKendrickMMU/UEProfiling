// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Hybrid.generated.h"

UCLASS()
class UEPROFILING_API ABP_Hybrid : public AActor // unreal uses A for Actors S for structs
{
	GENERATED_BODY()
	
	// U us used for components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true")) // these tell the editor how to work see the scipts for the character
	class UStaticMeshComponent* CubeMesh;

	

public:	
	// Sets default values for this actor's properties
	ABP_Hybrid();
	// create a public variable for us to us
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ExposedVariables)// only change the deaful value
	int LoopCount = 500;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = ExposedFunctions)
	void LoopTime();
};
