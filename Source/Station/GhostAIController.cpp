#include "GhostAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

AGhostAIController::AGhostAIController()
{
    PrimaryActorTick.bCanEverTick = true;

    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AGhostAIController::BeginPlay()
{
    Super::BeginPlay();

    if (UseBlackboard(nullptr, BlackboardComp))
    {
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (PlayerPawn)
        {
            BlackboardComp->SetValueAsObject(TargetKey, PlayerPawn);
        }
    }
}

void AGhostAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (!BlackboardComp) return;

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        BlackboardComp->SetValueAsObject(TargetKey, PlayerPawn);
        MoveToActor(PlayerPawn, 5.0f); // 5cm까지 접근
    }
}
