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
    TObjectPtr<UBlockSpecification> Type;

    UPROPERTY(Transient)
    TObjectPtr<UBlockState> State;
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

    UFUNCTION(BlueprintPure)
    TArray<UBlockSpecification*> GetSpecifications(TSubclassOf<UBlockSpecification> Class);

    UFUNCTION(BlueprintPure)
    const TMap<FIntVector, FBlockInstance>& GetBlockInstances() const;

protected:
    virtual void InitializeComponent() override;
    virtual void BeginPlay() override;

    void SpawnChildComponents();

    UPROPERTY(EditDefaultsOnly)
    float BlockSize = 50.f;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TMap<FIntVector, FBlockInstance> Blocks;

private:
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    UPROPERTY(Transient)
    TArray<TObjectPtr<USceneComponent>> ChildComponents;
};
