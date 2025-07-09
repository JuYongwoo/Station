#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GhostAIController.generated.h"

UCLASS()
class STATION_API AGhostAIController : public AAIController
{
    GENERATED_BODY()

public:
    AGhostAIController();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "AI")
    FName TargetKey = "TargetActor";

    UPROPERTY()
    class UBlackboardComponent* BlackboardComp;

    UPROPERTY()
    class UBehaviorTree* BehaviorTreeAsset; // Optional, 현재는 사용 안 함
};
