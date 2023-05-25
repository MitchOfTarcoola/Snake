#pragma once
#include "raylib.h"
#include "global.h"
class gameObject
{
public:
	int Location;
	Color Colour;

	void Draw();
	int getX();
	int getY();
private:
	const int TileSize;
};

