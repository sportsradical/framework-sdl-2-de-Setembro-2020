#pragma once
#ifndef __SHIPE_H_
#define __SHIPE_H_

#include"GameObject.h"




class Shipe : public GameObject
{
public:
	Shipe();
	~Shipe();

	// Inherited via GameObject
	virtual void Update() override;

	virtual void Draw() override;




};

#endif // !__SHIPE_H_
