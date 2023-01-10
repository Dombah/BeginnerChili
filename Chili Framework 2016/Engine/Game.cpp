/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			vy = vy - mv_Increment;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			vy = vy + mv_Increment;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft)
		{
			vx = vx - mv_Increment;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight)
		{
			vx = vx + mv_Increment;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		g = 0;
		b = 0;
	}
	else
	{
		g = 255;
		b = 255;
	}
	x += vx;
	y += vy;
	isColliding = CollisionChecker(x, draw_x, y, draw_y) ||
				  CollisionChecker(x, draw_x1, y, draw_y1);

}

void Game::ComposeFrame()
{
	if (isColliding)
	{
		g = 0;
		b = 0;
	}
	else
	{
		g = 255;
		b = 255;
	}
	DrawBox(x, y, r, g, b);
	DrawBox(draw_x, draw_y, 0, 255, 0);
	DrawBox(draw_x1, draw_y1, 0, 0, 255);
}

void Game::DrawBox(int x, int y, int r, int g ,int b)
{
	// Upper part of crosshair
	gfx.PutPixel(x - 7, y - 5 + 1, r, g, b);
	gfx.PutPixel(x - 7, y - 6 + 1, r, g, b);
	gfx.PutPixel(x - 7, y - 7 + 1, r, g, b);
	gfx.PutPixel(x - 7, y - 8 + 1, r, g, b);
	gfx.PutPixel(x - 6, y - 8 + 1, r, g, b);
	gfx.PutPixel(x - 5, y - 8 + 1, r, g, b);
	gfx.PutPixel(x - 4, y - 8 + 1, r, g, b);
	gfx.PutPixel(x + 7, y - 5 + 1, r, g, b);
	gfx.PutPixel(x + 7, y - 6 + 1, r, g, b);
	gfx.PutPixel(x + 7, y - 7 + 1, r, g, b);
	gfx.PutPixel(x + 7, y - 8 + 1, r, g, b);
	gfx.PutPixel(x + 6, y - 8 + 1, r, g, b);
	gfx.PutPixel(x + 5, y - 8 + 1, r, g, b);
	gfx.PutPixel(x + 4, y - 8 + 1, r, g, b);

	// Lower part of crosshair
	gfx.PutPixel(x - 7, y + 5 - 1, r, g, b);
	gfx.PutPixel(x - 7, y + 6 - 1, r, g, b);
	gfx.PutPixel(x - 7, y + 7 - 1, r, g, b);
	gfx.PutPixel(x - 7, y + 8 - 1, r, g, b);
	gfx.PutPixel(x - 6, y + 8 - 1, r, g, b);
	gfx.PutPixel(x - 5, y + 8 - 1, r, g, b);
	gfx.PutPixel(x - 4, y + 8 - 1, r, g, b);
	gfx.PutPixel(x + 7, y + 5 - 1, r, g, b);
	gfx.PutPixel(x + 7, y + 6 - 1, r, g, b);
	gfx.PutPixel(x + 7, y + 7 - 1, r, g, b);
	gfx.PutPixel(x + 7, y + 8 - 1, r, g, b);
	gfx.PutPixel(x + 6, y + 8 - 1, r, g, b);
	gfx.PutPixel(x + 5, y + 8 - 1, r, g, b);
	gfx.PutPixel(x + 4, y + 8 - 1, r, g, b);
}

bool Game::CollisionChecker(int x_Box0, int x_Box1, int y_Box0, int y_Box1)
{
	bool isX_Colliding = x_Box0 >= x_Box1 - 14 && x_Box0 <= x_Box1 + 14;
	bool isY_Colliding = y_Box0 >= y_Box1 - 14 && y_Box0 <= y_Box1 + 14;

	return isX_Colliding && isY_Colliding;
}


