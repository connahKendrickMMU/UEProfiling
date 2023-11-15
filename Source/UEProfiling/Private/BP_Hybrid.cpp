// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Hybrid.h"
#include "Components/StaticMeshComponent.h" // notice we need add the header file
#include "Components/TextRenderComponent.h"
#include <string>
// Sets default values
ABP_Hybrid::ABP_Hybrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create our mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe); // notice we use -> as it's a pointer, QueryAndProbe is a trigger based collision

	SetRootComponent(CubeMesh);
}

// Called when the game starts or when spawned
void ABP_Hybrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Hybrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

} 

// our loop function
void ABP_Hybrid::LoopTime()
{
	
	for (int i = 0; i < LoopCount; i++)
	{
		if (GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("Loop count: %d"), i);
		}
	}
}

