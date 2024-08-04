// PG26 2024


#include "ClassDefaults/SpaceInvaderGameModeBase.h"
#include "ClassDefaults/SpaceInvaderGameStateBase.h"
#include "ClassDefaults/SpaceInvaderPlayerState.h"
#include "Controllers/SpaceInvaderController.h"
#include "Pawns/SpaceInvaderPawn.h"

ASpaceInvaderGameModeBase::ASpaceInvaderGameModeBase()
{
	GameStateClass = ASpaceInvaderGameStateBase::StaticClass();
	PlayerControllerClass = ASpaceInvaderController::StaticClass();
	PlayerStateClass = ASpaceInvaderPlayerState::StaticClass();
	DefaultPawnClass = ASpaceInvaderPawn::StaticClass();
}
