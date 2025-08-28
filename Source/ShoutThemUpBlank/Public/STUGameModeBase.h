// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "STUCoreTypes.h"

#include "STUGameModeBase.generated.h"

class AAIController;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASTUGameModeBase();

    FOnMatchStateChangedSignature OnMatchStateChanged;

    virtual void StartPlay() override;

    virtual UClass *GetDefaultPawnClassForController_Implementation(AController *InController) override;

    void Killed(const AController *KillerController, AController *VictimController);

    int32 GetMaximumRoundsNumber() const
    {
        return GameData.RoundsNum;
    }

    int32 GetCurrentRoundNumber() const
    {
        return CurrentRound;
    }

    int32 GetRoundCountdown() const
    {
        return RoundCountDown;
    }

    void RespawnRequest(AController *Controller);

    virtual bool SetPause(APlayerController *PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;

  protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

private:
    ESTUMatchState MatchState = ESTUMatchState::WaitingToStart;
    int32 CurrentRound = 1;
    int32 RoundCountDown = 0;
    FTimerHandle GameRoundTimerHandle;

    void SpawnBots();
    void StartRound();
    void GameTimerUpdate();

    void ResetPlayers();
    void ResetOnePlayer(AController *Controller);

    void CreateTeamsInfo();
    FLinearColor DetermineColorByTeamID(int32 TeamID) const;
    void SetPlayerColor(AController *Controller);

    void LogPlayerInfo();

    void StartRespawn(AController* Controller);

    void GameOver();

    void SetMatchState(ESTUMatchState State);
    void StopAllFire();
};
