#include "MBAssetManeger.h"

#include "AbilitySystemGlobals.h"

void UMBAssetManeger::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
	
}
