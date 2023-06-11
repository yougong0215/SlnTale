#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>


//////////////////////////////
#include "Console.h"
#include "Timer.h"

#define WIDTHMAX 117

#define HEIGHTMAX 65


#define SAFE_DELETE(p)            {if(p) {delete (p);   (p) = 0; } }

#define SAFE_DELETE_ARRAY(p)     {if(p) {delete[] (p);  (p) = 0; } }

#define SAFE_RELEASE(p)            {if(p) { p->Release(); (p) = 0; } }

static Timer Time;
#pragma comment(lib, "user32")

using namespace std;

enum class Tag
{
	None = 0,
	Player,
	Arrow,
	Wall
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
};
