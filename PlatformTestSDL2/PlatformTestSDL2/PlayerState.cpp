#include "PlayerState.h"

PlayerState* PlayerState::Transition(Player& player, PlayerState* newState)
{
	this->Exit();
    newState->Enter(player);
    return newState;
}
