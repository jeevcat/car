// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlocksComponent.h"
#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"

#include "BlockWheeledVehiclePawn.generated.h"

/**
 *
 */
UCLASS()
class CAR_API ABlockWheeledVehiclePawn final : public AWheeledVehiclePawn
{
    GENERATED_BODY()

public:
    ABlockWheeledVehiclePawn();
    virtual void PostInitializeComponents() override;
    virtual void PostRegisterAllComponents() override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
    TObjectPtr<UBlocksComponent> Blocks;

private:
    void InitWheels();

#if WITH_EDITOR
        virtual void
        PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
