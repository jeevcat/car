#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BlockSpecification.generated.h"

class UBlockState;

UCLASS()
class BLOCKS_API UBlockSpecification final : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FText HumanName;

	// Can be null if no state needed
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBlockState> StateClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USceneComponent> ComponentClass;
};
