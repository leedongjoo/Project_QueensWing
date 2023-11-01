// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "QWCharacterBase.generated.h"

class UQWCharacterDataAsset;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract) // 추상 베이스 클래스로 사용자가 이 클래스 엑터를 월드에 추가하지 못한다.
class QUEENSWING_API AQWCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQWCharacterBase();
	
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// BP에서 세팅
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CharacterData")
	TObjectPtr<UQWCharacterDataAsset> CharacterDataAsset;

	// 자식 클래스에서 세팅
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
