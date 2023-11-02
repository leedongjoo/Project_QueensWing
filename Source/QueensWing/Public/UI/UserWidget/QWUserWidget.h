// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QWUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUEENSWING_API UQWUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) // 오버레이에서 컴포지션한BP 위젯 클래스들의 컨트롤러 세팅해준다
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:
	UFUNCTION(BlueprintImplementableEvent) // 자식 BP가 컨트롤러의 델리게이트 구독
	void WidgetControllerSet();
};
