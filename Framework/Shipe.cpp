#include"Shipe.h"
#include"TextureManager.h"
#include"Game.h"



Shipe::Shipe()
{
	TheTextureManager::Instance()->Load("../Framework/Assets/Sprites/plane.png", "shipe", 
		                                TheGame::Instance()->GetRenderer());



	glm::vec2 position = glm::vec2(100.0f, 100.0f);
	glm::vec2 velocitity = glm::vec2(5.0f, 5.0f);

	SetPosition(position);
	SetVelocity(velocitity);


}

Shipe::~Shipe()
{
}

void Shipe::Update()
{
	glm::vec2 newposition = GetPosition() + GetVelocity();
	SetPosition(newposition);
}

void Shipe::Draw()
{
	TheTextureManager::Instance()->DrawTexture("shipe", GetPosition().x, GetPosition().y, 100, 100, TheGame::Instance()->GetRenderer(), SDL_FLIP_NONE);
}
