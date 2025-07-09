#include "AGhost.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GhostAIController.h"

AAGhost::AAGhost()
{
    PrimaryActorTick.bCanEverTick = true;

    bUseControllerRotationYaw = false;

    GetCharacterMovement()->bUseControllerDesiredRotation = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);

    AIControllerClass = AGhostAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    // ¹Ýµå½Ã Ä¸½¶¿¡ ºÎÂø
    GetMesh()->SetupAttachment(GetCapsuleComponent());

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -83.f));

    GetCharacterMovement()->MaxWalkSpeed = 10.f;
}


void AAGhost::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Ghost MaxWalkSpeed: %f"), GetCharacterMovement()->MaxWalkSpeed);

}
