// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetManager/QWAssetManager.h"

/* Character Types */
const FPrimaryAssetType UQWAssetManager::MainCharacterType =	TEXT("MainCharacter");
//const FPrimaryAssetType UQWAssetManager::SubCharacterType =		TEXT("SubCharacter");
//const FPrimaryAssetType UQWAssetManager::NPCType =				TEXT("NPC");
//const FPrimaryAssetType UQWAssetManager::MonsterType =			TEXT("Monster");

/* Weapon Types */
const FPrimaryAssetType UQWAssetManager::BoltActionGun =		TEXT("BoltActionGun");
//const FPrimaryAssetType UQWAssetManager::MachineGun =			TEXT("MachineGun");
//const FPrimaryAssetType UQWAssetManager::Pistol =				TEXT("Pistol");

void UQWAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}

UQWAssetManager& UQWAssetManager::Get()
{
	UQWAssetManager* This = Cast<UQWAssetManager>(GEngine->AssetManager);

	if (This)
	{
		return *This;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invaild AssetManager in DefaultEngine.ini, Must set this to URPGAssetManager"));
		return *NewObject<UQWAssetManager>();
	}
}
