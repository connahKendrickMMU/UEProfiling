// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPOnly.h"
#include <Containers/UnrealString.h>
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h" 
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPOnly::ACPPOnly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create our mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	//CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe); // notice we use -> as it's a pointer, QueryAndProbe is a trigger based collision
	
	SetRootComponent(CubeMesh);

	// Set up overlap events
	CubeMesh->SetGenerateOverlapEvents(true);
	CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &ACPPOnly::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ACPPOnly::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello i am alive"));
}

// Called every frame
void ACPPOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// our loop function
void ACPPOnly::LoopTime()
{
	UWorld* World = GetWorld();
	int32 temp;
	start = UGameplayStatics::GetRealTimeSeconds(World);
	UGameplayStatics::GetAccurateRealTime(temp, start);
	UE_LOG(LogTemp, Warning, TEXT("Start time is: %d"), start);
	for (int i = 0; i < LoopCount; i++)
	{
		if (GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("CPP loop is: %d"), i);
		}
	}
	UGameplayStatics::GetAccurateRealTime(temp, start);
	UE_LOG(LogTemp, Warning, TEXT("Start time is: %d"), start);
}

// Called when the CubeMesh overlaps another actor
void ACPPOnly::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OverlapBegin triggered"));
	// Call LoopTime method when overlap begins
	LoopTime();
}