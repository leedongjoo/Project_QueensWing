// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UserWidget/QWUserWidget.h"

void UQWUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet(); // 블루프린트 이벤트 호출
}