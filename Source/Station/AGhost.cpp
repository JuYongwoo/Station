#include "AGhost.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GhostAIController.h" // 너가 따로 만든 AIController 있다면 이걸로

AAGhost::AAGhost()
{
    PrimaryActorTick.bCanEverTick = true;

    // AIController 설정
    AIControllerClass = AGhostAIController::StaticClass(); // ← 없으면 AAIController 로 임시 설정 가능
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    // 유령용 SkeletalMeshComponent 추가
    GhostMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GhostMesh"));
    GhostMesh->SetupAttachment(RootComponent);
    GhostMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GhostMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f)); // 캡슐 위치 보정

    // (선택) 걷는 속도 약간 느리게 유령 느낌
    GetCharacterMovement()->MaxWalkSpeed = 200.f;

    // 메쉬 리소스 지정 (에디터에서 직접 지정하는 걸 더 권장)
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/YourPath/SK_Ghost.SK_Ghost"));
    if (MeshAsset.Succeeded())
    {
        GhostMesh->SetSkeletalMesh(MeshAsset.Object);
    }
}

void AAGhost::BeginPlay()
{
    Super::BeginPlay();
}
