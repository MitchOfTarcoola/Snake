#pragma once
#include "raylib.h"
#include "global.h"
class gameObject
{
public:
	int Location; //all objects have a location and colour
	Color Colour;

	
	virtual ~gameObject();

	void Draw();
	int getX();
	int getY();
private:
	
};

