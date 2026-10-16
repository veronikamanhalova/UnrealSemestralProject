#include "PlayerBall.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"

// Sets default values
APlayerBall::APlayerBall()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerBall::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void APlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Started, this, &APlayerBall::Move);
		EIC->BindAction(TurnAction, ETriggerEvent::Started, this, &APlayerBall::Turn);
		EIC->BindAction(AbilityAction, ETriggerEvent::Started, this, &APlayerBall::ActivateAbility);
	}
}

void APlayerBall::Move(const FInputActionValue& Value)
{
	const float Direction = Value.Get<float>();
	AddActorWorldOffset(GetActorForwardVector() * StepDistance * Direction, true);
}

void APlayerBall::Turn(const FInputActionValue& Value)
{
	const float Direction = Value.Get<float>();

	if (Controller)
	{
		FRotator Rot = Controller->GetControlRotation();
		Rot.Yaw += 90.f * Direction;
		Controller->SetControlRotation(Rot);
	}
}

void APlayerBall::ActivateAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Ability pressed"));
}


