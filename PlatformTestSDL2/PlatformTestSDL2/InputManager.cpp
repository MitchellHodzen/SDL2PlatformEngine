#include "InputManager.h"



InputManager::InputManager()
{
	currentKeyboardState = SDL_GetKeyboardState(NULL);
}


InputManager::~InputManager()
{
}

bool InputManager::HandleInput(float deltaTime, Player* player)
{
	bool quit = false;
	while (SDL_PollEvent(&e) != 0 && e.key.repeat == 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				player->ActionKeyPressed(PlayerActions::JUMP);
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				//player->StopMoving(Player::Direction::UP);
				player->ActionKeyReleased(PlayerActions::JUMP);
				break;
			//case SDLK_DOWN:
			//	player->StopMoving(Player::Direction::DOWN);
			//	break;
			case SDLK_LEFT:
				//player->StopMoving(Player::Direction::LEFT);
				player->ActionKeyReleased(PlayerActions::MOVE_LEFT);
				break;
			case SDLK_RIGHT:
				//player->StopMoving(Player::Direction::RIGHT);
				player->ActionKeyReleased(PlayerActions::MOVE_RIGHT);
				break;
			}
		}
	}
	if (currentKeyboardState[SDL_SCANCODE_UP])
	{
		//player->Move(Player::Direction::UP, deltaTime);
		player->ActionKeyHeld(PlayerActions::JUMP);
	}
	if (currentKeyboardState[SDL_SCANCODE_DOWN])
	{
		//player->Move(Player::Direction::DOWN, deltaTime);
	}
	if (currentKeyboardState[SDL_SCANCODE_LEFT])
	{
		//player->Move(Player::Direction::LEFT, deltaTime);
		player->ActionKeyHeld(PlayerActions::MOVE_LEFT);
	}
	if (currentKeyboardState[SDL_SCANCODE_RIGHT])
	{
		//player->Move(Player::Direction::RIGHT, deltaTime);
		player->ActionKeyHeld(PlayerActions::MOVE_RIGHT);
	}
	return quit;
}