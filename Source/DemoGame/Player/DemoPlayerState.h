
#pragma once

#include "CoreMinimal.h"
#include "ModularPlayerState.h"
#include "AbilitySystemInterface.h"
//#include "System/GameplayTagStack.h"
//#include "Messages/LyraVerbMessage.h"
//#include "Teams/LyraTeamAgentInterface.h"

#include "DemoPlayerState.generated.h"


//class ALyraPlayerController;
//class ULyraAbilitySystemComponent;
//class UAbilitySystemComponent;
class UDemoPawnData;
class ULyraExperienceDefinition;




/**
 * ALyraPlayerState
 *
 *	Base player state class used by this project.
 */
UCLASS(Config = Game)
class DEMOGAME_API ADemoPlayerState : public AModularPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADemoPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	template <class T>
	const T* GetPawnData() const { return Cast<T>(PawnData); }

	void SetPawnData(const UDemoPawnData* InPawnData);




protected:
	//UFUNCTION()
		//void OnRep_PawnData();

protected:

	//UPROPERTY(ReplicatedUsing = OnRep_PawnData)
		const UDemoPawnData* PawnData;

};