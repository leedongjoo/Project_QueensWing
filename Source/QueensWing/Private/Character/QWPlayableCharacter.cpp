// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QWPlayableCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/QWPlayerController.h"
#include "Player/QWPlayerState.h"
#include "UI/HUD/QWHUD.h"

AQWPlayableCharacter::AQWPlayableCharacter()
{
	GetMesh()->CastShadow = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0);
	GetCapsuleComponent()->SetCapsuleRadius(42.0);
	
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -97.0f),
		FRotator(0.0f, -90.0f, 0.0f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->TargetArmLength = 700.0f;
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bDoCollisionTest = false;

	DefaultCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("DefaultCamera"));
	DefaultCamera->SetupAttachment(SpringArm);
}

void AQWPlayableCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

void AQWPlayableCharacter::InitAbilityActorInfo()
{
	AQWPlayerState* QWPlayerState = CastChecked<AQWPlayerState>(GetPlayerState());
	QWPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(QWPlayerState, this); // 어빌리티 초기화
	
	AbilitySystemComponent = QWPlayerState->GetAbilitySystemComponent();
	AttributeSet = QWPlayerState->GetAttributeSet();

	if (AQWPlayerController* QWPlayerController = Cast<AQWPlayerController>(GetController()))
	{
		if(AQWHUD* QWHUD = Cast<AQWHUD>(QWPlayerController->GetHUD()))
		{
			QWHUD->InitOverlay(QWPlayerController, QWPlayerState, AbilitySystemComponent, AttributeSet); // UI를 띄운다
		}
	}
}
