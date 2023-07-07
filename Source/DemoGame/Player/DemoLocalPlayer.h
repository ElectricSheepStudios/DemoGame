

#pragma once

#include "CoreMinimal.h"
#include "CommonLocalPlayer.h"
//#include "AudioMixerBlueprintLibrary.h"
//#include "Teams/LyraTeamAgentInterface.h"
#include "DemoLocalPlayer.generated.h"

//class ULyraSettingsLocal;
//class ULyraSettingsShared;
//class UInputMappingContext;

/**
 * ULyraLocalPlayer
 */
UCLASS()
class DEMOGAME_API UDemoLocalPlayer : public UCommonLocalPlayer //, public ILyraTeamAgentInterface
{
	GENERATED_BODY()

public:

	UDemoLocalPlayer();

};
