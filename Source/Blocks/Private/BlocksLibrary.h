#pragma once
#include "CoreMinimal.h"
#include "BlockType.h"
#include "Engine/DataAsset.h"

#include "BlocksLibrary.generated.h"

class UBlockSpecification;

UCLASS()
class UBlocksLibrary final : public UDataAsset
{
    GENERATED_BODY()

public:
    virtual void Serialize(FArchive& Ar) override;

    UPROPERTY(EditAnywhere)
    TMap<EBlockType, UBlockSpecification*> Blocks;
};
