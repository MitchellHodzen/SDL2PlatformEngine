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
				player->GetInput(PlayerActions::JUMP, InputType::PRESSED);
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				//player->StopMoving(Player::Direction::UP);
				player->ActionKeyReleased(PlayerActions::JUMP);
				player->GetInput(PlayerActions::JUMP, InputType::RELEASED);
				break;
			//case SDLK_DOWN:
			//	player->StopMoving(Player::Direction::DOWN);
			//	break;
			case SDLK_LEFT:
				//player->StopMoving(Player::Direction::LEFT);
				player->ActionKeyReleased(PlayerActions::MOVE_LEFT);
				player->GetInput(PlayerActions::MOVE_LEFT, InputType::RELEASED);
				break;
			case SDLK_RIGHT:
				//player->StopMoving(Player::Direction::RIGHT);
				player->ActionKeyReleased(PlayerActions::MOVE_RIGHT);
				player->GetInput(PlayerActions::MOVE_RIGHT, InputType::RELEASED);
				break;
			}
		}
	}
	if (currentKeyboardState[SDL_SCANCODE_UP])
	{
		//player->Move(Player::Direction::UP, deltaTime);
		player->ActionKeyHeld(PlayerActions::JUMP);
		player->GetInput(PlayerActions::JUMP, InputType::HELD);
	}
	if (currentKeyboardState[SDL_SCANCODE_DOWN])
	{
		//player->Move(Player::Direction::DOWN, deltaTime);
	}
	if (currentKeyboardState[SDL_SCANCODE_LEFT])
	{
		//player->Move(Player::Direction::LEFT, deltaTime);
		player->ActionKeyHeld(PlayerActions::MOVE_LEFT);
		player->GetInput(PlayerActions::MOVE_LEFT, InputType::HELD);
	}
	if (currentKeyboardState[SDL_SCANCODE_RIGHT])
	{
		//player->Move(Player::Direction::RIGHT, deltaTime);
		player->ActionKeyHeld(PlayerActions::MOVE_RIGHT);
		player->GetInput(PlayerActions::MOVE_RIGHT, InputType::HELD);
	}
	return quit;
}