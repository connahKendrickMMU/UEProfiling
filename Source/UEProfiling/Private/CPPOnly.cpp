// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineUtils.h"
#include "Engine/Engine.h"
#include "CPPOnly.h"

// Sets default values
ACPPOnly::ACPPOnly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create our mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe); // notice we use -> as it's a pointer, QueryAndProbe is a trigger based collision
	CubeMesh->OnComponentHit.AddDynamic(this, &ACPPOnly::OnHit); // Bind the OnHit function to the collision event 
	SetRootComponent(CubeMesh);
}

// Function to handle the collision event
void ACPPOnly::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Mark the start of the trace region
	MarkTraceRegionStart("CPP only");

	// Perform the loop for the trace region
	LoopTime();

	// Mark the end of the trace region
	MarkTraceRegionEnd("CPP only");
}


// Called when the game starts or when spawned
void ACPPOnly::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// our loop function
void ABP_Hybrid::LoopTime()
{
	for (int i = 0; i < LoopCount; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT(FString::AppendInt(i));
	}
}

// Function to mark the start of the trace region
void ACPPOnly::MarkTraceRegionStart()
{
	// Use FScopedDurationTimer to mark the start of the trace region
	FScopedDurationTimer TraceRegionTimer(GetWorld()->GetGameInstance(), TEXT("CPP Trace"));
}

// Function to mark the end of the trace region
void ACPPOnly::MarkTraceRegionEnd()
{
	// Use FScopedDurationTimer to mark the end of the trace region
	FScopedDurationTimer TraceRegionTimer(GetWorld()->GetGameInstance(), TEXT("CPP Trace"));
}