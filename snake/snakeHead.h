#pragma once
#include "gameObject.h"
#include "snakeTail.h"
#include <list>
using namespace std;
class snakeHead :
    public gameObject
{
public:
    snakeTail* Tail;

    list<int> tailColours;

    void Move();
};

