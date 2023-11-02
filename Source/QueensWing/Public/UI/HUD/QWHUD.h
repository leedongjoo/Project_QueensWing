// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/QWWidgetController.h"
#include "QWHUD.generated.h"

class UQWUserWidget;
class UOverlayWidgetController;

/**
 * 
 */
UCLASS()
class QUEENSWING_API AQWHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UQWUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	// Widget과 WidgetController를 초기화한다
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:
	// BP에서 세팅
	UPROPERTY(EditAnywhere)
	TSubclassOf<UQWUserWidget> OverlayWidgetClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	// End: BP에서 세팅

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
