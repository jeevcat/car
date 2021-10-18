// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockState.h"
#include "CoreMinimal.h"

#include "EngineState.generated.h"

/**
 *
 */
UCLASS()
class UEngineState final : public UBlockState
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    float GetPower() const;
};
