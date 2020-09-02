#include<iostream>

#include"Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argv, char** argc)
{

	Uint32 frameStart, frameTime;
	TheGame::Instance()->Initialized("Hello world", 800, 600, false);

	while (TheGame::Instance()->GetIsRuning())
	{
		frameStart = SDL_GetTicks();

		TheGame::Instance()->UpdateHandles();
		TheGame::Instance()->Draw();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	TheGame::Instance()->Exit();

	return 0;
}