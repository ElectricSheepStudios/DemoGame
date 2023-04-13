
#pragma once

#include "CoreMinimal.h"
#include "C:/Users/HoeJa/OneDrive/Desktop/DemoGame/DemoGame/Plugins/ModularGameplayActors/Source/ModularGameplayActors/Public/ModularGameState.h"
#include "E:/EpicGames/Epic Games/UE_5.0/Engine/Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
//#include "Messages/LyraVerbMessage.h"

#include "LyraGameState.generated.h"

class ULyraExperienceManagerComponent;
//class ULyraAbilitySystemComponent;
class UAbilitySystemComponent;


UCLASS(Config = Game)
class DEMOGAME_API ALyraGameState : public AModularGameStateBase
{
	GENERATED_BODY()

public:

	ALyraGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	float GetServerFPS() const { return ServerFPS; }

	//~AActor interface
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of AActor interface

	//~AGameStateBase interface
	virtual void AddPlayerState(APlayerState* PlayerState) override;
	virtual void RemovePlayerState(APlayerState* PlayerState) override;
	//~End of AGameStateBase interface

	//~IAbilitySystemInterface
	//virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End of IAbilitySystemInterface

	//UFUNCTION(BlueprintCallable, Category = "Lyra|GameState")
//		ULyraAbilitySystemComponent* GetLyraAbilitySystemComponent() const { return AbilitySystemComponent; }

	// Send a message that all clients will (probably) get
	// (use only for client notifications like eliminations, server join messages, etc... that can handle being lost)
	//UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "Lyra|GameState")
	//	void MulticastMessageToClients(const FLyraVerbMessage Message);

	// Send a message that all clients will be guaranteed to get
	// (use only for client notifications that cannot handle being lost)
	//UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Lyra|GameState")
	//	void MulticastReliableMessageToClients(const FLyraVerbMessage Message);

private:
	UPROPERTY()
		ULyraExperienceManagerComponent* ExperienceManagerComponent;

	// The ability system component subobject for game-wide things (primarily gameplay cues)
	//UPROPERTY(VisibleAnywhere, Category = "Lyra|GameState")
		//ULyraAbilitySystemComponent* AbilitySystemComponent;


protected:

	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(Replicated)
		float ServerFPS;
};

