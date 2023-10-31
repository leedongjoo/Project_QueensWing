// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/QWGameplayDataLibrary.h"
#include "QWWeaponDataAsset.generated.h"

/**
 * 
 */


UCLASS()
class QUEENSWING_API UQWWeaponDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Asset Info")
	FGenericWeaponAssetInfo WeaponAsset;
};
