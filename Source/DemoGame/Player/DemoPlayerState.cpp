#include "DemoPlayerState.h"
#include "Net/UnrealNetwork.h"



//@TODO: Would like to isolate this a bit better to get the pawn data in here without this having to know about other stuff
#include "GameModes/DemoGameMode.h"
#include "GameModes/LyraExperienceManagerComponent.h"


ADemoPlayerState::ADemoPlayerState(const FObjectInitializer& ObjectInitializer)
{
}

UAbilitySystemComponent* ADemoPlayerState::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ADemoPlayerState::SetPawnData(const UDemoPawnData* InPawnData)
{
	check(InPawnData);

	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}


	if (PawnData)
	{
		//UE_LOG(LogLyra, Error, TEXT("Trying to set PawnData [%s] on player state [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(this), *GetNameSafe(PawnData));
		return;
	}

	//MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, PawnData, this);
	PawnData = InPawnData;

	//for (const ULyraAbilitySet* AbilitySet : PawnData->AbilitySets)
//	{
	//	if (AbilitySet)
	//	{
	//		AbilitySet->GiveToAbilitySystem(AbilitySystemComponent, nullptr);
//		}
//	}

	//UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, NAME_LyraAbilityReady);

	ForceNetUpdate();
}

void ADemoPlayerState::OnExperienceLoaded(const ULyraExperienceDefinition* /*CurrentExperience*/)
{
	if (ADemoGameMode* DemoGameMode = GetWorld()->GetAuthGameMode<ADemoGameMode>())
	{
		if (const UDemoPawnData* NewPawnData = DemoGameMode->GetPawnDataForController(GetOwningController()))
		{
			SetPawnData(NewPawnData);
		}
		else
		{
			//UE_LOG(LogLyra, Error, TEXT("ALyraPlayerState::OnExperienceLoaded(): Unable to find PawnData to initialize player state [%s]!"), *GetNameSafe(this));
		}
	}
}

//void ADemoPlayerState::OnRep_PawnData()
//{
//}


/*void ADemoPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;

	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, PawnData, SharedParams);
	//DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, MyPlayerConnectionType, SharedParams)
	//DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, MyTeamID, SharedParams);
	//DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, MySquadID, SharedParams);

	//DOREPLIFETIME(ThisClass, StatTags);
}*/
