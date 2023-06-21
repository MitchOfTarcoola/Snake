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
#include <string>
using namespace std;

bool hasStarted = false;

int currentFrame; //used for speed calc

int framesPerMove = 5;
int moveDir = 0; //0 = up, 1 = left, 2 = down, 3 = right


int main()
{

	srand((unsigned)time(0)); //setup RNG

	snakeHead Snake = snakeHead(width / 2 + width * (height / 2), RED, list<Color>{Color{ 0,200, 40, 255 }, Color{ 0,220, 40, 255 }}, new food(ORANGE));

	Snake.Grow();
	Snake.Grow();

	InitWindow(width*tileSize, height*tileSize, "SNAKE");

	SetTargetFPS(60);

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (!hasStarted)
		{
			if (IsKeyPressed(KEY_W)) //movement keys
			{
				moveDir = 0;
				hasStarted = true;
			}
			if (IsKeyPressed(KEY_S))
			{
				moveDir = 2;
				hasStarted = true;
			}
			if (IsKeyPressed(KEY_A))
			{
				moveDir = 1;
				hasStarted = true;
			}
			if (IsKeyPressed(KEY_D))
			{
				moveDir = 3;
				hasStarted = true;
			}
		}
		if (Snake.isPlaying && hasStarted) {

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

			currentFrame++;
			if (currentFrame >= framesPerMove) //runs every <framesPerMove> frames
			{
				Snake.Move(moveDir);

				currentFrame = 0;

			}
		}

		BeginDrawing();
		ClearBackground(DARKGRAY); //wall
		DrawText("Score:", 0, 0, tileSize, YELLOW);
		DrawText(to_string(Snake.Score).c_str(), tileSize * 3.5, 0, tileSize, YELLOW);
		for (int i = 1; i < width-1; i++)
		{
			for (int j = 1; j < height-1; j++)
			{
				DrawRectangle(i * tileSize, j * tileSize, tileSize, tileSize, ((i + j) % 2 == 1) ? LIGHTGRAY : Color{180,180,180,255}); //draw background grid
				
			}
		}
		Snake.Draw();


		if (!Snake.isPlaying)
		{
			DrawText("GAME OVER", width/2*tileSize-tileSize*12, height / 2 * tileSize - tileSize*2, tileSize*4, RED);
		}

		EndDrawing();
	}
}