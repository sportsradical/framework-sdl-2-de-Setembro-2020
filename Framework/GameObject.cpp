#include"GameObject.h"

GameObject::GameObject() :
						m_position(0.0f, 0.0f), 
						m_rotation(0.0f, 0.0f),
						m_scale(1.0f, 1.0f),
						m_velocity(0.0f, 0.0f)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw()
{
}

void GameObject::SetPosition(glm::vec2 position)
{
	m_position = position;
}

void GameObject::SetRotation(glm::vec2 rotation)
{
	m_rotation = rotation;
}

void GameObject::SetRotation(float x, float y)
{
	m_rotation.x = x;
	m_rotation.y = y;
}

void GameObject::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void GameObject::SetScale(glm::vec2 scale)
{
	m_scale = scale;
}

void GameObject::SetScale(float x, float y)
{
	m_scale.x = x;
	m_scale.y = y;
}

void GameObject::SetWidth(int width)
{
	m_width = width;
}

void GameObject::SetHeight(int height)
{
	m_height = height;
}

void GameObject::SetVelocity(glm::vec2 velocity)
{
	m_velocity = velocity;
}

glm::vec2 GameObject::GetPosition()
{
	return m_position;
}

float GameObject::GetPositionX()
{
	return m_position.x;
}

float GameObject::GetPositionY()
{
	return m_position.y;
}

glm::vec2 GameObject::GetRotation()
{
	return m_rotation;
}

float GameObject::GetRotationX()
{
	return m_rotation.x;
}

float GameObject::GetRotationY()
{
	return m_rotation.y;
}

glm::vec2 GameObject::GetScale()
{
	return m_scale;
}

float GameObject::GetScaleX()
{
	return m_scale.x;
}

float GameObject::GetScaleY()
{
	return m_scale.y;
}

int GameObject::GetWidth()
{
	return m_width;
}

int GameObject::GetHeight()
{
	return m_height;
}

glm::vec2 GameObject::GetVelocity()
{
	return m_velocity;
}
