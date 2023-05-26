#include "snakeTail.h"


void snakeTail::Move() {
	Location = next->Location;

}

snakeTail::snakeTail() {
	Location = 0;
	Colour = PINK;
	next = nullptr;
}

snakeTail::snakeTail(int id, Color colour, snakeTail* Next) {
	Location = id;
	Colour = colour;
	next = Next;
}