#pragma once
#include "snakeTail.h"
#include "food.h"
#include <list>
using namespace std;
class snakeHead :
    public snakeTail
{
public:

    
    snakeHead(int id, Color colour, list<Color> tailCol, food* Foood);
    ~snakeHead();

    food* Food;
    list<Color> tailColours;
    list<Color>::iterator nextTailCol;
    bool isPlaying = true;

    void Move(int dir);
    void Draw();
    void Grow();


};