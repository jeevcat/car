// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockSpecification.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"

#include "BlocksComponent.generated.h"

class UBlocksLibrary;
class UBlockState;

USTRUCT(BlueprintType)
struct FBlockInstance
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    UBlockSpecification* Type;

    UPROPERTY(Transient)
    UBlockState* State;
};

UCLASS(ClassGroup = (Blocks), meta = (BlueprintSpawnableComponent))
class BLOCKS_API UBlocksComponent final : public USceneComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UBlocksComponent();

    UFUNCTION(BlueprintPure)
    UBlockState* GetState(const FIntVector& Location) const;

protected:
    virtual void InitializeComponent() override;
    virtual void BeginPlay() override;
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    void SpawnChildComponents();

    UPROPERTY(EditDefaultsOnly)
    float BlockSize = 50.f;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TMap<FIntVector, FBlockInstance> Blocks;

private:
    UPROPERTY()
    TArray<USceneComponent*> ChildComponents;
};
