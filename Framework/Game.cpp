#include"Game.h"

// includes
#include"TextureManager.h"



Game* Game::s_pGame = 0;



Game::Game(): m_isRunning(true)
{
}

Game::~Game()
{
}

bool Game::Initialized(std::string title, int width, int height, bool isFullscreen)
{
	int flags = 0;

	if (isFullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	else
	{
		flags = SDL_WINDOW_RESIZABLE;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "Initialized SDL Sucess" << "\n";

		m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, flags);

		if (m_pWindow != 0)
		{
			std::cout << "Create window Sucess" << "\n";

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_pRenderer != 0)
			{
				CreateGameObjects();

				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				std::cout << "Create render Sucess" << "\n";
			}

			return true;
		}
		return true;
	}

	return false;
}



void Game::Update()
{
	UpdateGameobjects();
}

void Game::UpdateHandles()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_isRunning = false;
				break;
			case SDLK_w:
				std::cout << "Press key w: " << "\n";
				break;
			case SDLK_s:
				break;
			case SDLK_a:
				break;
			case SDLK_d:
				break;
			}
			break;
		}
	}

	Update();
}

void Game::CreateGameObjects()
{
	m_pShipe = new Shipe();
	m_pPlayer = new Player();
}

void Game::UpdateGameobjects()
{
	m_pShipe->Update();
	m_pPlayer->Update();
}

void Game::Draw()
{
	SDL_RenderClear(m_pRenderer);

	m_pShipe->Draw();
	m_pPlayer->Draw();

	SDL_RenderPresent(m_pRenderer);
}

void Game::Exit()
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

bool Game::GetIsRuning()
{
	return m_isRunning;
}

SDL_Renderer* Game::GetRenderer()
{
	return m_pRenderer;
}


