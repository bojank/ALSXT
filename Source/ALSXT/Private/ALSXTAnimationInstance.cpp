// Fill out your copyright notice in the Description page of Project Settings.


#include "ALSXTAnimationInstance.h"
#include "ALSXTCharacter.h"

void UALSXTAnimationInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ALSXTCharacter = Cast<AALSXTCharacter>(GetOwningActor());

#if WITH_EDITOR
	if (!GetWorld()->IsGameWorld() && ALSXTCharacter.IsNull())
	{
		// Use default objects for editor preview.

		ALSXTCharacter = GetMutableDefault<AALSXTCharacter>();
	}
#endif
}

void UALSXTAnimationInstance::NativeUpdateAnimation(const float DeltaTime)
{

	Super::NativeUpdateAnimation(DeltaTime);

	if (!IsValid(ALSXTCharacter))
	{
		return;
	}

	Freelooking = ALSXTCharacter->GetDesiredFreelooking();
	Sex = ALSXTCharacter->GetDesiredSex();
	LocomotionVariant = ALSXTCharacter->GetDesiredLocomotionVariant();
	Injury = ALSXTCharacter->GetDesiredInjury();
	CombatStance = ALSXTCharacter->GetDesiredCombatStance();
	WeaponFirearmStance = ALSXTCharacter->GetDesiredWeaponFirearmStance();
	WeaponReadyPosition = ALSXTCharacter->GetDesiredWeaponReadyPosition();
	Blocking = ALSXTCharacter->GetDesiredBlocking();
	StationaryMode = ALSXTCharacter->GetStationaryMode();
	HitReaction = ALSXTCharacter->GetHitReaction();
	HitSurface = ALSXTCharacter->GetHitSurface();
	BumpReaction = ALSXTCharacter->GetBumpReaction();
	BumpSurface = ALSXTCharacter->GetBumpSurface();
	HoldingBreath = ALSXTCharacter->GetHoldingBreath();
	Emote = ALSXTCharacter->GetEmote();
	Gesture = ALSXTCharacter->GetGesture();
	GestureHand = ALSXTCharacter->GetGestureHand();
	ReloadingType = ALSXTCharacter->GetReloadingType();

}

bool UALSXTAnimationInstance::IsSpineRotationAllowed()
{
	return ALSXTCharacter->GetRotationMode() == AlsRotationModeTags::Aiming;
	//return ALSXTCharacter->GetRotationMode() == AlsRotationModeTags::Aiming && ALSXTCharacter->GetLocomotionState().bRotationLocked == false;
}

bool UALSXTAnimationInstance::IsRotateInPlaceAllowed()
{
	return (ALSXTCharacter->GetRotationMode() == AlsRotationModeTags::Aiming || ALSXTCharacter->GetViewMode() == AlsViewModeTags::FirstPerson) && ALSXTCharacter->GetLocomotionState().bRotationLocked == false;
}

bool UALSXTAnimationInstance::IsTurnInPlaceAllowed()
{
	return (ALSXTCharacter->GetRotationMode() == AlsRotationModeTags::LookingDirection && ALSXTCharacter->GetViewMode() != AlsViewModeTags::FirstPerson) && ALSXTCharacter->GetLocomotionState().bRotationLocked == false;
}