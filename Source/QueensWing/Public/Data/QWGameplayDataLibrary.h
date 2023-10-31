// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QWGameplayDataLibrary.generated.h"


// 에셋 데이터 구조체들
// <사용 방법>
// 1. C++ 데이터 에셋을 만들고 멤버로 이 구조체들을 지정.
// 2. 사용할 엑터 또는 폰에 C++ 데이터 에셋을 멤버로 지정.
// 3. C++ 데이터 에셋을 부모로 한 블루프린트 데이터 에셋을 만들고 에셋 지정.
// 4. 블루프린트 데이터 에셋을 엑터 또는 폰에 경로를 불러들여 사용.

// 이거 수정하면 블루프린트 데이터 에셋 맴버들이 다 빠지니까 주의

USTRUCT(BlueprintType)
struct FGenericCharacterAssetInfo // 게임에 등장하는 다양한 캐릭터/npc/몹 등의 에셋 정보
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data") // 캐릭터의 타입 지정
	FPrimaryAssetType CharacterType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CharacterInfo")
	TObjectPtr<USkeletalMesh> SkeletalMesh; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CharacterInfo")
	TSubclassOf<UAnimInstance> AnimInstance;
};

USTRUCT(BlueprintType)
struct FGenericWeaponAssetInfo // 게임에 등장하는 다양한 무기의 에셋 정보
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data") // 무기의 타입 지정
	FPrimaryAssetType WeaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponInfo")
	TObjectPtr<USkeletalMesh> SkeletalMesh; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponInfo")
	TSubclassOf<UAnimInstance> AnimInstance;
};

UCLASS()
class QUEENSWING_API UQWGameplayDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	// TODO : Implement Save Function
	
};
