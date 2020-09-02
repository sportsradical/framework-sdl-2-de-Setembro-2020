#pragma once
#ifndef __GAME_H_
#define __GAME_H_

// includes CORE 
#include<iostream>


// includes SDL
#include<SDL.h>


// includes
#include"Shipe.h"
#include"Player.h"

class Game
{
public:

	static Game* Instance()
	{
		if (s_pGame == 0)
		{
			s_pGame = new Game();

			return s_pGame;
		}
		return s_pGame;
	}


	bool Initialized(std::string title, int width, int height, bool isFullscreen);
	void UpdateHandles();
	void Draw();
	void Exit();




	bool GetIsRuning();
	SDL_Renderer* GetRenderer();

	

private:
	Game();
	~Game();
	void UpdateGameobjects();
	void Update();
	void CreateGameObjects();


	static Game* s_pGame;

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_isRunning;

	Shipe* m_pShipe;
	Player* m_pPlayer;
};
typedef Game TheGame;
#endif // !__GAME_H_
