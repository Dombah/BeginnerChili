#pragma once 
#include "Graphics.h"

class Poo
{
public:
	void Update();
	int vx;
	int vy;
	int x;
	int y;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool pooIsEated = false;
};