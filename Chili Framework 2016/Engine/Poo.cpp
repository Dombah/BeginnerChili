#include "Poo.h"


void Poo::Update()
{
	x += vx;
	y += vy;
	const int right = x + width;
	const int left = x;
	if (left < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right > Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}
	const int top = y;
	const int bottom = y + height;
	if (top < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom > Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}