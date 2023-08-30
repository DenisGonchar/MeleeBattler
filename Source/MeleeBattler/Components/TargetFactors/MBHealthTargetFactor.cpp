
#include "MBHealthTargetFactor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/MBCharacterAttributeSet.h"

TArray<AActor*> UMBHealthTargetFactor::GetHighPriorityActors_Implementation(
	const TArray<AActor*>& TestActors, bool bEnableDebug, float TargetRadius) const
{
	AActor* actorWithLowestHealth = nullptr;
	float minHealth = 0.0f;
	
	for(const auto testActor : TestActors)
	{
		if (testActor != nullptr)
		{
			bool bFoundAttribute = false;
			const float health = UAbilitySystemBlueprintLibrary::GetFloatAttribute(testActor, UMBCharacterAttributeSet::GetHealthAttribute(), bFoundAttribute);
			
			if (bFoundAttribute && (actorWithLowestHealth == nullptr || minHealth > health) && health > 0.0f)
			//if (bFoundAttribute && actorWithLowestHealth == nullptr  minHealth < health)
			{
				actorWithLowestHealth = testActor;
				minHealth = health;
				
			}		
		}
	}

	return {actorWithLowestHealth};
}
