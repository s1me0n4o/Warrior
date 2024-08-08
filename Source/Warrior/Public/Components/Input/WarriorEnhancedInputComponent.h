// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Inputs/DataAsset_InputConfig.h"
#include "WarriorEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent, UserObject* CtxObject, CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
inline void UWarriorEnhancedInputComponent::BindNativeAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* CtxObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data is null, cannot proceed with binding!"));
	if(auto FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, CtxObject, Func);
	}
}
