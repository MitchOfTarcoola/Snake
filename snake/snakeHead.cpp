#include "snakeHead.h"


void snakeHead::Move() {
	for (snakeTail* i = next; i != this; i = i->next)
	{
		i->Move();
	}
	//add head move code here
}

void snakeHead::Draw() {
	for (snakeTail* i = next; i != this; i = i->next)
	{
		i->Draw();
	}
	gameObject::Draw();

};
