// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/QWCharacterDataAsset.h"
#include "AssetManager/QWAssetManager.h"
#include "QWMainCharacterDataAsset.generated.h"

/**
 * 
 */

UENUM()
enum class EMainCharacterName // 다양한 메인 캐릭터의 이름을 정의
{
	Tirah			UMETA(DisplayName = "Tirah"),	    
	Mel		        UMETA(DisplayName = "Mel"),				   
	Test1			UMETA(DisplayName = "Test1"),
	Test2			UMETA(DisplayName = "Test2")
};

// UENUM()
// enum class EWeaponName // 다양한 무기 이름을 정의
// {
// 	BoltActionGun	UMETA(DisplayName = "BoltActionGun"),
// 	MachineGun		UMETA(DisplayName = "MachineGun"),
// 	Pistol			UMETA(DisplayName = "Pistol"),
// 	Default			UMETA(DisplayName = "Default")
// };

UCLASS()
class QUEENSWING_API UQWMainCharacterDataAsset : public UQWCharacterDataAsset
{
	GENERATED_BODY()

public:
	UQWMainCharacterDataAsset()
	{
		CharacterAsset.CharacterType = UQWAssetManager::MainCharacterType;
	}
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterInfo")
	EMainCharacterName CharacterName;
};
