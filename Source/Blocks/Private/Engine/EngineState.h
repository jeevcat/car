// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockState.h"
#include "CoreMinimal.h"
#include "EngineSpecification.h"

#include "EngineState.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class UEngineState final : public UBlockState
{
    GENERATED_BODY()

public:
    virtual UEngineSpecification* GetSpecification() const override;

    UFUNCTION(BlueprintCallable)
    float GetTotalPower() const;
};
