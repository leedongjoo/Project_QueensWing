// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/QWPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AQWPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(QWContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(QWContext, 0); // 입력 우선순위 설정.

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
}

void AQWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AQWPlayerController::Move);
}

void AQWPlayerController::Move(const FInputActionValue& Value) 
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>(); // xy축 벡터를 가져온다.
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		if (InputAxisVector.Y != 0.f)
		{
			ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		}
		
		if (InputAxisVector.X != 0.f)
		{
			ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
		}
	}
}
