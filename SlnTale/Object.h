#pragma once




class Object
{
public:
	Object();
	Object(Vector2 pos);
	Object(char ch, Vector2 pos, Tag tag);
	virtual ~Object();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	
public:
	char Image()
	{
		return _image;
	}

public:
	Vector2* position;
	Tag tag;

protected:
	Vector2* newPosition;
	char _image;
};

