#include "gameObject.h"




gameObject::~gameObject() {}


void gameObject::Draw() { //draw this object
	DrawRectangle(getX() * tileSize, getY() * tileSize, tileSize, tileSize, Colour);
}
int gameObject::getX() { //convert location id to x and y
	return Location % width;
}

int gameObject::getY() {
	return Location / width;
}