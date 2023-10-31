// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/QWCharacterDataAsset.h"

FPrimaryAssetId UQWCharacterDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(CharacterAsset.CharacterType, GetFName());
}
