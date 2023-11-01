// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/QWPlayerState.h"

#include "AbilitySystem/QWAbilitySystemComponent.h"
#include "AbilitySystem/QWAttributeSet.h"

AQWPlayerState::AQWPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UQWAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UQWAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AQWPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
