#include "GhostAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
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

    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ACharacter* GhostCharacter = Cast<ACharacter>(ControlledPawn);
        if (GhostCharacter)
        {
            GhostCharacter->GetCharacterMovement()->MaxWalkSpeed = 50.f;
        }
    }

    // 기존 추적 로직
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        MoveToActor(PlayerPawn, 5.f);
    }
}
