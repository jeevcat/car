// Fill out your copyright notice in the Description page of Project Settings.

#include "BlocksComponent.h"

#include "BlockSpecification.h"
#include "BlockState.h"

// Sets default values for this component's properties
UBlocksComponent::UBlocksComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    bWantsInitializeComponent = true;

    // ...
}

void UBlocksComponent::InitializeComponent()
{
    Super::InitializeComponent();

    SpawnChildComponents();
}

// Called when the game starts
void UBlocksComponent::BeginPlay()
{
    Super::BeginPlay();

    // Create states
    for (auto& [Coords, BlockInstance] : Blocks)
    {
        BlockInstance.State = UBlockState::Create(BlockInstance.Type, this, Coords);
    }
}

void UBlocksComponent::SpawnChildComponents()
{
    for (USceneComponent* Child : ChildComponents)
    {
        Child->DestroyComponent();
    }
    ChildComponents.Empty(Blocks.Num());

    for (auto& [Coords, BlockInstance] : Blocks)
    {
        if (!BlockInstance.Type || !BlockInstance.Type->ComponentClass)
        {
            continue;
        }

        USceneComponent* Child = NewObject<USceneComponent>(this, BlockInstance.Type->ComponentClass);
        Child->SetupAttachment(this);
        Child->SetRelativeLocation(FVector(Coords.X, Coords.Y, Coords.Z) * BlockSize);
        if (GetWorld())
        {
            Child->RegisterComponent();
        }
        ChildComponents.Add(Child);
    }
}

#if WITH_EDITOR
void UBlocksComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    if (const FName PropertyName(PropertyChangedEvent.MemberProperty->GetFName());
        PropertyName == GET_MEMBER_NAME_CHECKED(UBlocksComponent, Blocks))
    {
        SpawnChildComponents();
    }
}
#endif
