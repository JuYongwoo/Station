#include "InteractionUIManager.h"
#include "Components/TextBlock.h"

void UInteractionUIManager::ShowInteractionUI(const FText& InteractionText)
{
    if (InteractionTextBlock)
    {
        InteractionTextBlock->SetText(InteractionText);
        SetVisibility(ESlateVisibility::Visible);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InteractionTextBlock is null"));
    }
}

void UInteractionUIManager::HideInteractionUI()
{
    SetVisibility(ESlateVisibility::Hidden);
}
