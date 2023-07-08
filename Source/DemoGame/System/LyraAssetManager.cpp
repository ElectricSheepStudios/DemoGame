// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraAssetManager.h"
//#include "LyraLogChannels.h"
//#include "LyraGameplayTags.h"
//#include "LyraGameData.h"
//#include "AbilitySystemGlobals.h"
#include "Character\DemoPawnData.h"
#include "Stats/StatsMisc.h"
#include "Engine/Engine.h"
//#include "AbilitySystem/LyraGameplayCueManager.h"
#include "Misc/ScopedSlowTask.h"

const FName FLyraBundles::Equipped("Equipped");

//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////

//#define STARTUP_JOB_WEIGHTED(JobFunc, JobWeight) StartupJobs.Add(FLyraAssetManagerStartupJob(#JobFunc, [this](const FLyraAssetManagerStartupJob& StartupJob, TSharedPtr<FStreamableHandle>& LoadHandle){JobFunc;}, JobWeight))
//#define STARTUP_JOB(JobFunc) STARTUP_JOB_WEIGHTED(JobFunc, 1.f)

//////////////////////////////////////////////////////////////////////

ULyraAssetManager::ULyraAssetManager()
{
	//DefaultPawnData = nullptr;
}

ULyraAssetManager& ULyraAssetManager::Get()
{
	check(GEngine);

	if (ULyraAssetManager* Singleton = Cast<ULyraAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	//UE_LOG(LogLyra, Fatal, TEXT("Invalid AssetManagerClassName in DefaultEngine.ini.  It must be set to LyraAssetManager!"));

	// Fatal error above prevents this from being called.
	return *NewObject<ULyraAssetManager>();
}

//const UDemoPawnData* ULyraAssetManager::GetDefaultPawnData() const
//{
	//return GetAsset(DefaultPawnData);
//}
