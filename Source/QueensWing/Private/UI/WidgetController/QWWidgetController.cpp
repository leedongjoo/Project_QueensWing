// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/QWWidgetController.h"

void UQWWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UQWWidgetController::BroadcastInitialValues()
{
}

void UQWWidgetController::BindCallbacksToDependencies()
{
}
