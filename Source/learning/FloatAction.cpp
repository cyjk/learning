// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatAction.h"
#include "learning.h"

// Sets default values
AFloatAction::AFloatAction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingSpeed = { 1.f, 1.f, 1.f };

}

// Called when the game starts or when spawned
void AFloatAction::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Error, TEXT("Log Message"));
	UE_LOG(LogTemp, Warning, TEXT("Log Message"));
	UE_LOG(LogTemp, Display, TEXT("Log Message"));

	UE_LOG(MyLogCategory, Log, TEXT("My Category Log"));

	FString CharacterName = TEXT("TestName");
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s"), *CharacterName);
	bool isAttackable = true;
	UE_LOG(LogTemp, Log, TEXT("Is Attackable = %s"), isAttackable ? TEXT("true") : TEXT("false"));
	int hp = 100;
	UE_LOG(LogTemp, Log, TEXT("HP = %d"), hp);
	float AttackSpeed = 1.f;
	UE_LOG(LogTemp, Log, TEXT("AttackSpeed = %f"), AttackSpeed);

	FVector CharacterPosition = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Position = %s"), *CharacterPosition.ToString());
	
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s, HP = %d, Attack Speed = %f"), *CharacterName, hp, AttackSpeed);
}

// Called every frame
void AFloatAction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaX = (FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X));
	float DeltaY = (FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y));
	float DeltaZ = (FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z));
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.f;
	RunningTime += DeltaTime * FloatingSpeed;
	SetActorLocation(NewLocation); 
}

