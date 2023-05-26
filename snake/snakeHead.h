#pragma once
#include "snakeTail.h"
#include <list>
using namespace std;
class snakeHead :
    public snakeTail
{
public:

    list<int> tailColours;
    void Move();
    void Draw();


};