// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "QWAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class QUEENSWING_API UQWAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UQWAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pawn")
	float Speed;
};
