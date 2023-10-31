// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "QWAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class QUEENSWING_API UQWAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	UQWAssetManager() {}
	virtual void StartInitialLoading() override;

	// TODO: 프로젝트 세팅 - 에셋 메니저에 스캔할 프라이메리 에셋 유형에 해당 유형 추가할 것
	
	/* Character Types */
	static const FPrimaryAssetType MainCharacterType;
	//static const FPrimaryAssetType SubCharacterType;
	//static const FPrimaryAssetType NPCType;
	//static const FPrimaryAssetType MonsterType;

	/* Weapon Types */
	static const FPrimaryAssetType BoltActionGun;
	
	// Return the asset manager singleton class
	static UQWAssetManager& Get();
};
