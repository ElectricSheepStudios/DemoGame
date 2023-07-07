#include "DemoPlayerState.h"
#include "Net/UnrealNetwork.h"



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
