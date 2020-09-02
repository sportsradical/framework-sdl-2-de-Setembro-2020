#include"TextureManager.h"





TextureManager* TextureManager::s_pTextureManager = 0;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::Load(std::string filename, std::string id, SDL_Renderer* render)
{

	SDL_Surface* surface = IMG_Load(filename.c_str());

	if (surface == 0)
	{
		std::cout << "failed load texture" << "\n";
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);

	if (texture != 0)
	{
		m_pTexture[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::Draw(std::string id, int positionX, int positionY, int width, int height, SDL_Renderer* render)
{

	SDL_Rect sourceRect;
	SDL_Rect destinationRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = destinationRect.w = width;
	sourceRect.h = destinationRect.h = height;
	destinationRect.x = positionX;
	destinationRect.y = positionY;

	SDL_RenderCopy(render, m_pTexture[id], &sourceRect, &destinationRect);
}

void TextureManager::DrawTexture(std::string id, int positionX, int positionY, int width, int height, SDL_Renderer* render, SDL_RendererFlip renderFlip)
{

	SDL_Rect sourceRect, destinationRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = destinationRect.w = width;
	sourceRect.h = destinationRect.h = height;
	destinationRect.x = positionX;
	destinationRect.y = positionY;


	SDL_RenderCopyEx(render, m_pTexture[id], &sourceRect, &destinationRect, 0, 0, renderFlip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int currentRow, int currentFrame, SDL_Renderer* pRenderer, bool centered, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	int textureWidth, textureHeight;

	SDL_QueryTexture(m_pTexture[id], NULL, NULL, &textureWidth, &textureHeight);

	srcRect.x = textureWidth * currentFrame;
	srcRect.y = textureHeight * (currentRow - 1);
	srcRect.w = destRect.w = textureWidth;
	srcRect.h = destRect.h = textureHeight;

	if (centered) {
		int xOffset = textureWidth * 0.5;
		int yOffset = textureHeight * 0.5;
		destRect.x = x - xOffset;
		destRect.y = y - yOffset;
	}
	else {
		destRect.x = x;
		destRect.y = y;
	}

	SDL_RenderCopyEx(pRenderer, m_pTexture[id], &srcRect, &destRect, 0, 0, flip);
}








