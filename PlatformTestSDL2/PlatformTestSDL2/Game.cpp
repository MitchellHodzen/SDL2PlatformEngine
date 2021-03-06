#include "Game.h"
#include "Animation.h"


Game::Game()
{
	screenWidth = 800;
	screenHeight = 601;
	levelWidth = 1000;
	levelHeight = 1001;

	renderer = new Renderer(screenWidth, screenHeight, false);
	mediaManager = new MediaManager();
	inputManager = new InputManager();
}


Game::~Game()
{
	delete renderer;
	delete mediaManager;
	delete inputManager;
}

void Game::Start()
{
	if (Initialize())
	{
		bool quit = false;
		Player player(350, 150, 18, 26, -9.0f, -12.0f);
		player.GetAnimationController()->SetTexture(mediaManager->GetTexture(0));
		player.GetAnimationController()->SetAnimationMap(mediaManager->GetPlayerAnimations());
		player.Initialize();
		
		BlockTest block(350, 345, 100, 100, -50.0f, -50.0f, false);
		block.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block2(450, 275, 100, 100, -50.0f, -50.0f, false);
		block2.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block2.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block3(250, 345, 100, 100, -50.0f, -50.0f, false);
		block3.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block3.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block4(150, 345, 100, 100, -50.0f, -50.0f, false);
		block4.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block4.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block5(50, 345, 100, 100, -50.0f, -50.0f, false);
		block5.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block5.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block6(50, 245, 100, 100, -50.0f, -50.0f, false);
		block6.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block6.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block7(50, 145, 100, 100, -50.0f, -50.0f, false);
		block7.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block7.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block8(500, 455, 100, 100, -50.0f, -50.0f, false);
		block8.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block8.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block9(600, 455, 100, 100, -50.0f, -50.0f, false);
		block9.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block9.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block10(700, 455, 100, 100, -50.0f, -50.0f, false);
		block10.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block10.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block11(800, 455, 100, 100, -50.0f, -50.0f, false);
		block11.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block11.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block12(900, 455, 100, 100, -50.0f, -50.0f, false);
		block12.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block12.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block13(900, 355, 100, 100, -50.0f, -50.0f, false);
		block13.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block13.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		BlockTest block14(900, 255, 100, 100, -50.0f, -50.0f, false);
		block14.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block14.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);

		BlockTest block15(900, 155, 100, 100, -50.0f, -50.0f, false);
		block15.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block15.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);

		std::vector<Entity*> entityList;
		entityList.push_back(&block);
		entityList.push_back(&block2);
		entityList.push_back(&block3);
		entityList.push_back(&block4);
		entityList.push_back(&block5);
		entityList.push_back(&block6);
		entityList.push_back(&block7);
		entityList.push_back(&block8);
		entityList.push_back(&block9);
		entityList.push_back(&block10);
		entityList.push_back(&block11);
		entityList.push_back(&block12);
		entityList.push_back(&block13);
		entityList.push_back(&block14);
		entityList.push_back(&block15);
		entityList.push_back(&player);


		Camera camera(0, 0, screenWidth, screenHeight, levelWidth, levelHeight);
		camera.SetTarget(&player);


		Uint32 lastFrameTime = 0;
		Uint32 currentFrameTime = 0;
		float deltaTime = 0.0f;
		renderer->Draw(&entityList, &camera);
		currentFrameTime = SDL_GetTicks();
		while (quit == false)
		{
			lastFrameTime = currentFrameTime;
			currentFrameTime = SDL_GetTicks();
			deltaTime = (float)(currentFrameTime - lastFrameTime) / 1000;
			player.GetTiming(lastFrameTime, currentFrameTime, deltaTime);
			quit = inputManager->HandleInput(deltaTime, &player);
			player.Update(entityList);
			camera.Reset();
			renderer->Draw(&entityList, &camera);
			//SDL_Delay(30);
		}
	}
}

bool Game::Initialize()
{
	if (renderer->Initialize() == true)
	{
		mediaManager->CreateTexture("Media/Sprites/megamanx.png", renderer->GetRenderer());
		//mediaManager->CreateTexture("Media/Sprites/megamanxidlerun.png", renderer->GetRenderer());
		//mediaManager->CreateTexture("Media/Sprites/runningplayertransparencytest.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/blocktypes.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/player1.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/block1.png", renderer->GetRenderer());
		mediaManager->GeneratePlayerAnimations();
		return true;
	}
	else
	{
		return false;
	}
}
