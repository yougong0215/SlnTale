#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	position = new Vector2(0, 0);
	newPosition = new Vector2(0, 0);
	tag = Tag::None;
	_image = '#';
	*newPosition = *position;
}

Object::Object(Vector2 pos)
{
	*position = pos;
	newPosition = new Vector2(0, 0);
	tag = Tag::None;
	_image = '#';
	*newPosition = *position;

}

Object::Object(char ch, Vector2 pos, Tag tag)
{
	*position = pos;
	newPosition = new Vector2(0, 0);
	this->tag = tag;
	_image = ch;
	*newPosition = *position;
}

Object::~Object()
{
}

void Object::Init()
{
}

void Object::Update()
{
}

void Object::Render()
{
}

void Object::Release()
{
	SAFE_DELETE(position);
}
