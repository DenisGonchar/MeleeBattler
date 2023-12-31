#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MBCharacterAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class UMBCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category= "Damage")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMBCharacterAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category= "Damage")
	FGameplayAttributeData MaxHealth; 
	ATTRIBUTE_ACCESSORS(UMBCharacterAttributeSet, MaxHealth);
	

};
