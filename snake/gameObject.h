#pragma once
#include "raylib.h"
#include "global.h"
class gameObject
{
public:
	int Location; //all objects have a location and colour
	Color Colour;

	gameObject();
	gameObject(int id, Color colour); //constructors and destructor
	~gameObject() = default;

	void Draw();
	int getX();
	int getY();
private:
	
};

