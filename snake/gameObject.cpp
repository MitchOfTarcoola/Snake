#include "gameObject.h"


gameObject::gameObject() {
	Location = 0;
	Colour = PINK;
}

gameObject::gameObject(int id, Color colour) {
	Location = id;
	Colour = colour;
}




void gameObject::Draw() { //draw this object
	DrawRectangle(getX() * tileSize, getY() * tileSize, tileSize, tileSize, Colour);
}
int gameObject::getX() { //convert location id to x and y
	return Location % width;
}

int gameObject::getY() {
	return Location / width;
}