#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MBEquipComponent.generated.h"


class AMBMeleeItem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MELEEBATTLER_API UMBEquipComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMBEquipComponent();

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	
	UFUNCTION(BlueprintCallable)
	void EquipItemClassToHand(TSubclassOf<AMBMeleeItem> NewItem);

	UFUNCTION(BlueprintCallable)
	void EquipItemToHand(AMBMeleeItem* NewItem);

	UFUNCTION(BlueprintPure)
	AMBMeleeItem* GetActiveItem() const { return ActiveItem; };

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName HandItemAttachSocketName;
	
private:
	UPROPERTY()
	AMBMeleeItem* ActiveItem;
};
