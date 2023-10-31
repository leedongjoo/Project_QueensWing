// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QWAnimInstance.h"

UQWAnimInstance::UQWAnimInstance()
{
	Speed = 0.0f;
}

void UQWAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	const APawn* Pawn = TryGetPawnOwner();
	
	if(::IsValid(Pawn))
	{
		FVector HorizontalMovement = Pawn->GetVelocity();
		HorizontalMovement.Z = 0.0f;
		
		Speed = HorizontalMovement.Length();
	}
}
