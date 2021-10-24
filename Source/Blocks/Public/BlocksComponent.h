// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockDirection.h"
#include "BlockType.h"
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
    EBlockType Type;

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

    template <class T>
    T* GetState(const FIntVector& Location) const;

protected:
    virtual void InitializeComponent() override;
    virtual void BeginPlay() override;
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    void SpawnChildComponents();

    UPROPERTY(EditDefaultsOnly)
    UBlocksLibrary* Library;

    UPROPERTY(EditDefaultsOnly)
    float BlockSize = 50.f;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TMap<FIntVector, FBlockInstance> Blocks;

private:
    UPROPERTY()
    TArray<USceneComponent*> ChildComponents;
};

template <class T>
T* UBlocksComponent::GetState(const FIntVector& Location) const
{
    if (const FBlockInstance* Instance = Blocks.Find(Location))
    {
        if (T* State = Cast<T>(Instance->State))
        {
            return State;
        }
    }
    return nullptr;
}
