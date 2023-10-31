// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/QWGameplayDataLibrary.h"
#include "QWCharacterDataAsset.generated.h"

/**
 * 
 */

UCLASS()
class QUEENSWING_API UQWCharacterDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Asset Info")
	FGenericCharacterAssetInfo CharacterAsset;
};
