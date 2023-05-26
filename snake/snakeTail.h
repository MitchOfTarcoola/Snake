#pragma once
#include "gameObject.h"
class snakeTail :
    public gameObject
{
public:

    snakeTail();
    snakeTail(int id, Color colour, snakeTail* Next);
    ~snakeTail() = default;

    snakeTail *next;


    void Move();
};

