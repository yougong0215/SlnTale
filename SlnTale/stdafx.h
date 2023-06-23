#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <map>
#include <fstream>
#include <list>
#include <memory>
#include <Windows.h>
#include <mmsystem.h>

//#include <mmsystem.h>
//////////////////////////////
#pragma comment(lib, "winmm.lib")

#pragma comment(lib, "user32")


#define WIDTHMAX 127

#define HEIGHTMAX 65


#define SAFE_DELETE(p)            {if(p) {delete (p);   (p) = 0; } }

#define SAFE_DELETE_ARRAY(p)     {if(p) {delete[] (p);  (p) = 0; } }

#define SAFE_RELEASE(p)            {if(p) { p->Release(); (p) = 0; } }

#define DECLARE_SINGLE(type)	\
private:						\
	type() {}					\
	~type() {}					\
public:							\
	static type* GetInstance()	\
	{							\
		static type instance;	\
		return &instance;		\
	}							\

#define GET_SINGLE(type)	type::GetInstance()

#include "Console.h"
#include "Timer.h"


using namespace std;


enum class ArrowMod
{
	normal = 0,
	shipja,
	WaSans,
	SAS,
	Miro,
};


enum class Tag
{
	None = 0,
	Player,
	Arrow,
	Wall
};

enum class walls
{
	None = 0,
	LeftUP = 1,
	Up = 2,
	RightUP = 3,
	Left = 4,
	LeftDown,
	RightDown,
};

typedef struct Vector2
{
public:
	int x = 0;
	int y = 0;
public:
	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	bool operator==(Vector2 v)
	{
		if (x == v.x &&  y == v.y)
		{
			return true;
		}
		return false;

	}
	bool operator!=(Vector2 v)
	{
		if (x != v.x || y != v.y)
		{
			return true;
		}
		return false;

	}

	void operator+=(Vector2 v1)
	{
		x += v1.x;
		y += v1.y;
	}

	void operator*=(Vector2 v1)
	{
		x *= v1.x;
		y *= v1.y;
	}

	void operator*=(int v1)
	{
		x *= v1;
		y *= v1;
	}

	Vector2 operator/(int v1)
	{

		return Vector2(x / v1, y / v1);
	}

	float magnitude() {
		return sqrt(x * x + y * y);
	}

	Vector2 normalize() {
		float mag = magnitude();
		if (mag != 0.0f) {
			x /= mag;
			y /= mag;
		}

		return *this;
	}
};


