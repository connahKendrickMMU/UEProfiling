// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPOnly.h"
#include <Containers/UnrealString.h>

// Sets default values
ACPPOnly::ACPPOnly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create our mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	//CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe); // notice we use -> as it's a pointer, QueryAndProbe is a trigger based collision
	
	SetRootComponent(CubeMesh);
}

/*void ACPPOnly::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	LoopTime();
}*/

// Called when the game starts or when spawned
void ACPPOnly::BeginPlay()
{
	Super::BeginPlay();
	//CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &ACPPOnly::OnHit);
}

// Called every frame
void ACPPOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// our loop function
void ACPPOnly::LoopTime()
{
	for (int i = 0; i < LoopCount; i++)
	{
		if (GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("CPP loop is: %d"), i);
		}
	}
}