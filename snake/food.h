#pragma once
#include "gameObject.h"
#include <list>
using namespace std;

class food :
	public gameObject
{
public:
	food(Color colour);

	void place();
};

