#include "snakeHead.h"



snakeHead::snakeHead(int id, Color colour, list<Color> tailCol, food* Foood) {
	Food = Foood;
	Location = id;
	Colour = colour;
	next = this;
	tailColours = tailCol;
	nextTailCol = tailColours.begin();
}
snakeHead::~snakeHead() {
	snakeTail* j = next;
	for (snakeTail* i = next->next; i != this; i = i->next) //delete each tail piece
	{
		delete j;
		j = i;
	}
}
void snakeHead::Move(int dir) {
	for (snakeTail* i = next; i != this; i = i->next) //run each tail piece's move func
	{
		i->Move();
	}
	//add head move code here
	switch (dir) //move forward
	{
	case 0:
		Location -= width;
		break;
	case 1:
		Location -= 1;
		break;
	case 2:
		Location += width;
		break;
	case 3:
		Location += 1;
		break;
	default:
		break;
	}

	if (Location == Food->Location) //hit food
	{
		Grow();
		Food->place();
	}
}

void snakeHead::Draw() {
	for (snakeTail* i = next; i != this; i = i->next) //run each tail piece's draw func
	{
		i->Draw();
	}
	gameObject::Draw();

}
void snakeHead::Grow() {
	snakeTail* newtail = new snakeTail(next->Location, *nextTailCol, next); //create tail piece on top of the old end. Snake will only visually grow when it moves, as the new piece is on top of the last piece
	next = newtail;
	nextTailCol++;
	if (nextTailCol == tailColours.end())
	{
		nextTailCol = tailColours.begin();
	}
}
