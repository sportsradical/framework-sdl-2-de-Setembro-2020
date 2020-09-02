#pragma once
#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include<glm/vec2.hpp>


class GameObject
{
public:
	GameObject();
	~GameObject();


	virtual void Update() = 0;
	virtual void Draw() = 0;


protected:

	// setters modifications
	void SetPosition(glm::vec2 position);
	void SetPosition(float x, float y);

	void SetRotation(glm::vec2 rotation);
	void SetRotation(float x, float y);

	void SetScale(glm::vec2 scale);
	void SetScale(float x, float y);


	void SetWidth(int width);
	void SetHeight(int height);

	void SetVelocity(glm::vec2 velocity);

	// getters acessores
	glm::vec2 GetPosition();
	float GetPositionX();
	float GetPositionY();


	glm::vec2 GetRotation();
	float GetRotationX();
	float GetRotationY();


	glm::vec2 GetScale();
	float GetScaleX();
	float GetScaleY();

	int GetWidth();
	int GetHeight();


	glm::vec2 GetVelocity();

private:
	// transformations

	glm::vec2 m_position;
	glm::vec2 m_rotation;
	glm::vec2 m_scale;


	glm::vec2 m_velocity;

	int m_width;
	int m_height;

};
#endif // !__GAMEOBJECT_H_
