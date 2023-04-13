#include "DemoGameMode.h"
//#include "LyraLogChannels.h"
//#include "C:\Users\HoeJa\OneDrive\Desktop\DemoGame\DemoGame\Source\DemoGame\Development\LyraDeveloperSettings.h"
#include "C:\Users\HoeJa\OneDrive\Desktop\DemoGame\DemoGame\Source\DemoGame\GameModes\LyraExperienceDefinition.h"
#include "C:\Users\HoeJa\OneDrive\Desktop\DemoGame\DemoGame\Source\DemoGame\GameModes\LyraWorldSettings.h"
#include "C:\Users\HoeJa\OneDrive\Desktop\DemoGame\DemoGame\Source\DemoGame\System\LyraAssetManager.h"
#include "C:\Users\HoeJa\OneDrive\Desktop\DemoGame\DemoGame\Source\DemoGame\GameModes\LyraExperienceManagerComponent.h"


#include "Kismet/GameplayStatics.h"




ADemoGameMode::ADemoGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GameStateClass = ALyraGameState::StaticClass();
	//GameSessionClass = ALyraGameSession::StaticClass();
	//PlayerControllerClass = ALyraPlayerController::StaticClass();
	//ReplaySpectatorPlayerControllerClass = ALyraReplayPlayerController::StaticClass();
	//PlayerStateClass = ALyraPlayerState::StaticClass();
	//DefaultPawnClass = ALyraCharacter::StaticClass();
	//HUDClass = ALyraHUD::StaticClass();
}

void ADemoGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	//@TODO: Eventually only do this for PIE/auto
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::HandleMatchAssignmentIfNotExpectingOne);
}



void ADemoGameMode::HandleMatchAssignmentIfNotExpectingOne()
{
	FPrimaryAssetId ExperienceId;
	FString ExperienceIdSource;

	// Precedence order (highest wins)
	//  - Matchmaking assignment (if present)
	//  - URL Options override
	//  - Developer Settings (PIE only)
	//  - Command Line override
	//  - World Settings
	//  - Default experience

	UWorld* World = GetWorld();

	if (!ExperienceId.IsValid() && UGameplayStatics::HasOption(OptionsString, TEXT("Experience")))
	{
		const FString ExperienceFromOptions = UGameplayStatics::ParseOption(OptionsString, TEXT("Experience"));
		ExperienceId = FPrimaryAssetId(FPrimaryAssetType(ULyraExperienceDefinition::StaticClass()->GetFName()), FName(*ExperienceFromOptions));
		ExperienceIdSource = TEXT("OptionsString");
	}

	if (!ExperienceId.IsValid() && World->IsPlayInEditor())
	{
		//ExperienceId = GetDefault<ULyraDeveloperSettings>()->ExperienceOverride;
		//ExperienceIdSource = TEXT("DeveloperSettings");


		// FIX LATER!!!!!
	}

	// see if the command line wants to set the experience
	if (!ExperienceId.IsValid())
	{
		FString ExperienceFromCommandLine;
		if (FParse::Value(FCommandLine::Get(), TEXT("Experience="), ExperienceFromCommandLine))
		{
			ExperienceId = FPrimaryAssetId::ParseTypeAndName(ExperienceFromCommandLine);
			ExperienceIdSource = TEXT("CommandLine");
		}
	}

	
	// see if the world settings has a default experience
	if (!ExperienceId.IsValid())
	{
		if (ALyraWorldSettings* TypedWorldSettings = Cast<ALyraWorldSettings>(GetWorldSettings()))
		{
			ExperienceId = TypedWorldSettings->GetDefaultGameplayExperience();
			ExperienceIdSource = TEXT("WorldSettings");
		}
	}

	
	ULyraAssetManager& AssetManager = ULyraAssetManager::Get();
	FAssetData Dummy;
	if (ExperienceId.IsValid() && !AssetManager.GetPrimaryAssetData(ExperienceId, /*out*/ Dummy))
	{
		//UE_LOG(LogLyraExperience, Error, TEXT("EXPERIENCE: Wanted to use %s but couldn't find it, falling back to the default)"), *ExperienceId.ToString());
		//ExperienceId = FPrimaryAssetId();
	}
	

	// Final fallback to the default experience
	if (!ExperienceId.IsValid())
	{
		//@TODO: Pull this from a config setting or something
		ExperienceId = FPrimaryAssetId(FPrimaryAssetType("LyraExperienceDefinition"), FName("B_LyraDefaultExperience"));
		ExperienceIdSource = TEXT("Default");
	}

	OnMatchAssignmentGiven(ExperienceId, ExperienceIdSource);
	
}


void ADemoGameMode::OnMatchAssignmentGiven(FPrimaryAssetId ExperienceId, const FString& ExperienceIdSource)
{

#if WITH_SERVER_CODE
	if (ExperienceId.IsValid())
	{
		//UE_LOG(LogLyraExperience, Log, TEXT("Identified experience %s (Source: %s)"), *ExperienceId.ToString(), *ExperienceIdSource);

		ULyraExperienceManagerComponent* ExperienceComponent = GameState->FindComponentByClass<ULyraExperienceManagerComponent>();
		check(ExperienceComponent);
		ExperienceComponent->ServerSetCurrentExperience(ExperienceId);
	}
	else
	{
		//UE_LOG(LogLyraExperience, Error, TEXT("Failed to identify experience, loading screen will stay up forever"));
	}
#endif
}