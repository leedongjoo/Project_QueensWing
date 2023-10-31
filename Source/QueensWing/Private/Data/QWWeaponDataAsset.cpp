// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/QWWeaponDataAsset.h"

FPrimaryAssetId UQWWeaponDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(WeaponAsset.WeaponType, GetFName());
}
