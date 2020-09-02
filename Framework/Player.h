#pragma once
#ifndef __PLAYER_H_
#define __PLAYER_H_

#include"GameObject.h"


class Player : public GameObject
{
public:
	Player();
	~Player();




	// Inherited via GameObject
	virtual void Update() override;

	virtual void Draw() override;

private:
	void CheckRand();

};
#endif // !__PLAYER_H_
