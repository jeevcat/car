// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockState.h"
#include "CoreMinimal.h"
#include "EngineShaft.h"

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

private:
    TSharedRef<FEngineShaft> GetShaft();

    // Doesn't really matter who owns the shaft in an engine, just someone needs to
    TSharedPtr<FEngineShaft> OwnedShaft;
};
