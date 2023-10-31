// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QWPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class QUEENSWING_API AQWPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	// BP에서 세팅
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> QWContext;

	// BP에서 세팅
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;

	// 콜백 함수
	void Move(const FInputActionValue& InputActionValue);
};
