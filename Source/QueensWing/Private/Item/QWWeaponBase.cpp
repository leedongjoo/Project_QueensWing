// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/QWWeaponBase.h"

// Sets default values
AQWWeaponBase::AQWWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	Mesh->SetupAttachment(RootComponent);

	// 무기 에셋을 얻어온다, 무기에 따라 달라진다 - 블루프린트에서 해주는 것으로 뺀다
	// const ConstructorHelpers::FObjectFinder<URPGCharacterDataAsset> CharacterAsset(
	// 	TEXT("/Game/Blueprints/DataAssets/TestCharacterData.TestCharacterData"));
	//
	// if (CharacterAsset.Succeeded())
	// {
	// 	CharacterAssetData = CharacterAsset.Object;
	// }

}

// Called when the game starts or when spawned
void AQWWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}


