// snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include <list>
#include <random>
#include "gameObject.h"
#include "food.h"
#include "snakeHead.h"
#include "global.h"
using namespace std;

bool _snakecolour = false; //used for making the tail pattern

//const int width = 20; //size of arena. includes walls
//const int height = 20;
//const int tileSize = 30;

int isPlaying = true;

int currentFrame; //used for speed calc

int framesPerMove = 15;
int moveDir = 0; //0 = up, 1 = left, 2 = down, 3 = right

int curLength = 1; //snake vars
int snakeLength = 3;
int snake = width/2 + width * (height/2);
list<int> body;

int food;


int getX(int pos) { //convert location id to x and y
	return pos % width;
}

int getY(int pos){
	return pos / width;
	}

void draw(int id, Color color) { //draw tile
	DrawRectangle(getX(id) * tileSize, getY(id) * tileSize, tileSize, tileSize, color);
}

void placeFood() { //places food in playing area, but not on snake. (currently causes overflow if you somehow fill the board with snake)
	food = rand() % (width * (height - 2) + height); //wont try top/bottom row
	if (food == snake) //on head
	{
		placeFood();
		return;
	}

	list<int>::iterator it;
	for (it = body.begin(); it != body.end(); ++it) //on tail
	{
		if (*it == food)
		{
			placeFood();
			return;
		}
	}

	if ((food <= width) || (food >= height * (width - 1) - 1 || (food + 1) % width <= 1)) { //on edge
		placeFood();
		return;
	}
}


int main()
{
	srand((unsigned)time(0)); //setup RNG

	placeFood();

	InitWindow(width*tileSize, height*tileSize, "SNAKE");

	SetTargetFPS(60);

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (isPlaying) {

			if (IsKeyPressed(KEY_W) && moveDir != 2) //movement keys
			{
				moveDir = 0;
			}
			if (IsKeyPressed(KEY_S) && moveDir != 0)
			{
				moveDir = 2;
			}
			if (IsKeyPressed(KEY_A) && moveDir != 3)
			{
				moveDir = 1;
			}
			if (IsKeyPressed(KEY_D) && moveDir != 1)
			{
				moveDir = 3;
			}
			/*if (IsKeyPressed(KEY_Q)) //debug, removes end of tail
			{
				if (!body.empty()) { body.pop_back(); }

			}*/
			currentFrame++;
			if (currentFrame >= framesPerMove) //runs every <framesPerMove> frames
			{
				currentFrame = 0;
				switch (moveDir) //move forward
				{
				case 0:
					body.push_front(snake); //head sq. becomes front of tail
					snake -= width;
					break;
				case 1:
					body.push_front(snake);
					snake -= 1;
					break;
				case 2:
					body.push_front(snake);
					snake += width;
					break;
				case 3:
					body.push_front(snake);
					snake += 1;
					break;
				default:
					break;
				}

				if (snake == food) //hit food
				{
					snakeLength++;
					placeFood();
				}

				curLength++;
				if (curLength > snakeLength) //update tail (remove end if no food)
				{
					curLength--;
					if (!body.empty()) { body.pop_back(); }
				}
				if ((snake <= width) || (snake >= height * (width - 1) - 1 || (snake+1) % width <= 1)) { //hit wall
					isPlaying = false;
					
				}
				
				list<int>::iterator it;
				for (it = body.begin(); it != body.end(); ++it) //hit tail
				{
					if (*it == snake)
					{
						isPlaying = false;
						
					}
				}
			}
		}

		BeginDrawing();
		ClearBackground(DARKGRAY); //wall
		
		for (int i = 1; i < width-1; i++)
		{
			for (int j = 1; j < height-1; j++)
			{
				DrawRectangle(i * tileSize, j * tileSize, tileSize, tileSize, ((i + j) % 2 == 1) ? LIGHTGRAY : Color{180,180,180,255}); //draw background grid
				
			}
		}
		list<int>::iterator it;
		_snakecolour = false;
		for ( it = body.begin(); it != body.end(); ++it)
		{
			_snakecolour = !_snakecolour;
			draw(*it, (_snakecolour) ?  Color{ 0,200, 40, 255 } : Color{0,220, 40, 255}); //draw tail
		}
		draw(snake, RED); //draw head

		draw(food, ORANGE); //draw food

		EndDrawing();
	}
}