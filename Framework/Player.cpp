#include "Player.h"
#include"Game.h"
#include"TextureManager.h"


Player::Player()
{
	TheTextureManager::Instance()->Load("../Framework/Assets/Sprites/rollerskate.png", "player",
		TheGame::Instance()->GetRenderer());



	glm::vec2 position = glm::vec2(100.0f, 100.0f);
	glm::vec2 velocitity = glm::vec2(0.0f, 5.0f);

	SetPosition(position);
	SetVelocity(velocitity);

	SetWidth(903);
	SetHeight(500);

}

Player::~Player()
{
}

void Player::Update()
{
	CheckRand();
	glm::vec2 newposition = GetPosition() + GetVelocity();


	SetPosition(newposition);
}

void Player::Draw()
{
	TheTextureManager::Instance()->DrawTexture("player", GetPosition().x, GetPosition().y, GetWidth() / 5, GetHeight() / 3, TheGame::Instance()->GetRenderer(), SDL_FLIP_HORIZONTAL);
}

void Player::CheckRand()
{
	/*int randomVelocityX = (rand() % 5) - 2;
	int randomVelocityY = (rand() % 6) + 5;
	SetVelocity(glm::vec2(randomVelocityX, randomVelocityY));


	int walfWidth = GetWidth() * 0.5;
	int positionx = std::rand() % (5 - GetWidth()) + walfWidth + 1;
	int positiony = -GetHeight();

	SetPosition(glm::vec2(positionx, 0));*/
}
