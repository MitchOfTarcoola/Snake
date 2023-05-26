#include "food.h"


food::food(Color colour) { //creates and places a food item
	Colour = colour;
	Location = 0;
	place();
}

void food::place() {
	Location = rand() % (width * (height - 2) + height); //wont try top/bottom row
	//if (Location == snake) //on head
	//{
	//	placeFood();
	//	return;
	//}

	//list<int>::iterator it;
	//for (it = body.begin(); it != body.end(); ++it) //on tail
	//{
	//	if (*it == Location)
	//	{
	//		placeFood();
	//		return;
	//	}
	//}

	if ((Location <= width) || (Location >= height * (width - 1) - 1 || (Location + 1) % width <= 1)) { //on edge
		place();
		return;
	}
}