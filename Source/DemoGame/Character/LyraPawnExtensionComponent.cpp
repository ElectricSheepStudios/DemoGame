#include "LyraPawnExtensionComponent.h"
//#include "LyraLogChannels.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "DemoPawnData.h"
//#include "AbilitySystem/LyraAbilitySystemComponent.h"

// Sets default values
ULyraPawnExtensionComponent::ULyraPawnExtensionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);

	//PawnData = nullptr;
	//AbilitySystemComponent = nullptr;
	bPawnReadyToInitialize = false;
}


void ULyraPawnExtensionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ULyraPawnExtensionComponent, PawnData);
}


void ULyraPawnExtensionComponent::SetPawnData(const UDemoPawnData* InPawnData)
{
	check(InPawnData);

	bPawnReadyToInitialize = false;

	APawn* Pawn = GetPawnChecked<APawn>();

	if (Pawn->GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	if (PawnData)
	{
		//UE_LOG(LogLyra, Error, TEXT("Trying to set PawnData [%s] on pawn [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(Pawn), *GetNameSafe(PawnData));
		return;
	}

	PawnData = InPawnData;

	Pawn->ForceNetUpdate();

	//CheckPawnReadyToInitialize();
}




/*bool ULyraPawnExtensionComponent::CheckPawnReadyToInitialize()
{
	if (bPawnReadyToInitialize)
	{
		return true;
	}

	// Pawn data is required.
	if (!PawnData)
	{
		return false;
	}

	APawn* Pawn = GetPawnChecked<APawn>();

	const bool bHasAuthority = Pawn->HasAuthority();
	const bool bIsLocallyControlled = Pawn->IsLocallyControlled();

	if (bHasAuthority || bIsLocallyControlled)
	{
		// Check for being possessed by a controller.
		if (!GetController<AController>())
		{
			return false;
		}
	}

	// Allow pawn components to have requirements.
	TArray<UActorComponent*> InteractableComponents = Pawn->GetComponentsByInterface(ULyraReadyInterface::StaticClass());
	for (UActorComponent* InteractableComponent : InteractableComponents)
	{
		const ILyraReadyInterface* Ready = CastChecked<ILyraReadyInterface>(InteractableComponent);
		if (!Ready->IsPawnComponentReadyToInitialize())
		{
			return false;
		}
	}

	// Pawn is ready to initialize.
	bPawnReadyToInitialize = true;
	//OnPawnReadyToInitialize.Broadcast();
	//BP_OnPawnReadyToInitialize.Broadcast();

	return true;
}*/

void ULyraPawnExtensionComponent::OnRep_PawnData()
{

}
