// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/QWCharacterBase.h"
#include "QWPlayableCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class QUEENSWING_API AQWPlayableCharacter : public AQWCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQWPlayableCharacter();
	
	virtual void PossessedBy(AController* NewController) override; // 빙의 진행 시 호출
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Collision")
	TObjectPtr<UCameraComponent> DefaultCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Collision")
	TObjectPtr<USpringArmComponent> SpringArm;

private:
	void InitAbilityActorInfo();
};
