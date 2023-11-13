// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPOnly.generated.h"

UCLASS()
class UEPROFILING_API ACPPOnly : public AActor
{
	GENERATED_BODY()
	// U us used for components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true")) // these tell the editor how to work see the scipts for the character
		class UStaticMeshComponent* CubeMesh;

public:	
	// Sets default values for this actor's properties
	ACPPOnly();
	// create a public variable for us to us
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ExposedVariables)// only change the default value
	int LoopCount = 500;
	float start = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = ExposedFunctions)
	void LoopTime();
};
