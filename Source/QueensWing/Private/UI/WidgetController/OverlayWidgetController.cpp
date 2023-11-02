// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/QWAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UQWAttributeSet* QWAttributeSet = CastChecked<UQWAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(QWAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(QWAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(QWAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(QWAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UQWAttributeSet* QWAttributeSet = CastChecked<UQWAttributeSet>(AttributeSet);
	
	// 체력 변경 시 해당 바인딩 함수 호출.
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		QWAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	// 최대 체력 변경 시 해당 바인딩 함수 호출.
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	QWAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	// 마나 변경 시 해당 바인딩 함수 호출
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	QWAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	
	// 최대 마나 변경 시 해당 바인딩 함수 호출
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	QWAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const // 체력 변경 시 호출
{
	OnHealthChanged.Broadcast(Data.NewValue); // 블루프린트에서 등록된 모든 함수를 호출
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const // 최대 체력 변경 시 호출
{
	OnMaxHealthChanged.Broadcast(Data.NewValue); // 블루프린트에서 등록된 모든 함수를 호출
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const // 마나 변경 시 호출
{
	OnManaChanged.Broadcast(Data.NewValue); // 블루프린트에서 등록된 모든 함수를 호출
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const // 최대 마나 변경 시 호출
{
	OnMaxManaChanged.Broadcast(Data.NewValue); // 블루프린트에서 등록된 모든 함수를 호출
}



