#pragma once
#ifndef __TEXTUREMANAGER_H_
#define __TEXTUREMANAGER_H_

// core windows
#include<iostream>
#include<string>

// includes sdl image
#include<SDL_image.h>
#include <map>





class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pTextureManager == 0)
		{
			s_pTextureManager = new TextureManager();
			return s_pTextureManager;
		}


		return s_pTextureManager;
	}


	bool Load(std::string filename, std::string id, SDL_Renderer* render);

	void Draw(std::string id, int positionX, int positionY, int width, int height, SDL_Renderer* render);
	void DrawTexture(std::string id, int positionX, int positionY, int width, int height, SDL_Renderer* render, SDL_RendererFlip renderFlip);
	void DrawFrame(std::string id, int x, int y, int currentRow, int currentFrame, SDL_Renderer* pRenderer, bool centered, SDL_RendererFlip flip);

private:
	TextureManager();
	~TextureManager();

	std::map<std::string, SDL_Texture*> m_pTexture;

	static TextureManager* s_pTextureManager;
};
#endif // !__TEXTUREMANAGER_H_
typedef TextureManager TheTextureManager;