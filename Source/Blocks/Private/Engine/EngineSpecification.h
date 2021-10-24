#pragma once

#include "BlockSpecification.h"
#include "CoreMinimal.h"

#include "EngineSpecification.generated.h"

UCLASS()
class UEngineSpecification : public UBlockSpecification
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere)
    float Power = 10.f;
};
