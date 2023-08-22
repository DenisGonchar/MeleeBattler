#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MBAssetManeger.generated.h"

UCLASS()
class MELEEBATTLER_API UMBAssetManeger : public UAssetManager
{
	GENERATED_BODY()

public:
	virtual void StartInitialLoading() override;
	
};
