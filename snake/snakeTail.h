#pragma once
#include "gameObject.h"
class snakeTail :
    public gameObject
{
public:
    snakeTail *next;


    void Move();
};

