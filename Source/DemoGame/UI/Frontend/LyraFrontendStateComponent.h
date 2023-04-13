// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/GameStateComponent.h"
#include "E:/EpicGames/Epic Games/UE_5.0/Engine/Plugins/Experimental/ControlFlows/Source/ControlFlows/Public/ControlFlow.h"
#include "Engine/EngineTypes.h"
#include "HAL/Platform.h"
#include "C:/Users/HoeJa/OneDrive/Desktop/DemoGame/DemoGame/Plugins/CommonLoadingScreen/Source/CommonLoadingScreen/Public/LoadingProcessInterface.h"
#include "Templates/SharedPointer.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"

#include "LyraFrontendStateComponent.generated.h"



UCLASS(Abstract)
class ULyraFrontendStateComponent : public UGameStateComponent, public ILoadingProcessInterface
{
	GENERATED_BODY()

public:

	ULyraFrontendStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~UActorComponent interface
//	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of UActorComponent interface


private:
	//void OnExperienceLoaded(const ULyraExperienceDefinition* Experience);



	//void FlowStep_WaitForUserInitialization(FControlFlowNodeRef SubFlow);
	//void FlowStep_TryShowPressStartScreen(FControlFlowNodeRef SubFlow);
	//void FlowStep_TryJoinRequestedSession(FControlFlowNodeRef SubFlow);
	//void FlowStep_TryShowMainScreen(FControlFlowNodeRef SubFlow);

};

