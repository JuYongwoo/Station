#include "AGhost.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GhostAIController.h" // �ʰ� ���� ���� AIController �ִٸ� �̰ɷ�

AAGhost::AAGhost()
{
    PrimaryActorTick.bCanEverTick = true;

    // AIController ����
    AIControllerClass = AGhostAIController::StaticClass(); // �� ������ AAIController �� �ӽ� ���� ����
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    // ���ɿ� SkeletalMeshComponent �߰�
    GhostMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GhostMesh"));
    GhostMesh->SetupAttachment(RootComponent);
    GhostMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GhostMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f)); // ĸ�� ��ġ ����

    // (����) �ȴ� �ӵ� �ణ ������ ���� ����
    GetCharacterMovement()->MaxWalkSpeed = 200.f;

    // �޽� ���ҽ� ���� (�����Ϳ��� ���� �����ϴ� �� �� ����)
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
