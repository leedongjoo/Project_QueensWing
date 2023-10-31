// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QWCharacterBase.h"

#include "Data/QWCharacterDataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AQWCharacterBase::AQWCharacterBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AQWCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// BP에서 데이터 에셋 세팅 시 호출
void AQWCharacterBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CharacterDataAsset)
	{
		GetMesh()->SetSkeletalMesh(CharacterDataAsset->CharacterAsset.SkeletalMesh);
		GetMesh()->SetAnimInstanceClass(CharacterDataAsset->CharacterAsset.AnimInstance);
	}
}





