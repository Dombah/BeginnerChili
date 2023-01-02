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
}

void Game::ComposeFrame()
{
	// x and y modifiers
	// NOTE: upper < 795 and lower < 595
	//		 upper > 4   and lower > 4
	int x = 400; // x value of center of crosshair
	int y = 300; // y value of center of crosshair

	int r = 255, g = 255, b = 255;

	int movement_Offset = 100;
	/*Homework*/
	
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= movement_Offset;
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			x -= movement_Offset;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			x += movement_Offset;
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += movement_Offset;
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			x -= movement_Offset;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			x += movement_Offset;
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= movement_Offset;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += movement_Offset;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		g = 0;
		b = 0;
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
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
	else
	{
		// Upper part of crosshair
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
		gfx.PutPixel(x, y - 2, r, g, b);
		gfx.PutPixel(x, y + 2, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);

		// Lower part of crosshair
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x - 2, y, r, g, b);
		gfx.PutPixel(x + 2, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
	}


	/*
	if(wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			// Upper part of crosshair
			gfx.PutPixel(x, y - 5, 255, 255, 255);
			gfx.PutPixel(x, y - 4, 255, 255, 255);
			gfx.PutPixel(x, y - 3, 255, 255, 255);
			gfx.PutPixel(x, y - 2, 255, 255, 255);
			gfx.PutPixel(x, y + 2, 255, 255, 255);
			gfx.PutPixel(x, y + 3, 255, 255, 255);
			gfx.PutPixel(x, y + 4, 255, 255, 255);
			gfx.PutPixel(x, y + 5, 255, 255, 255);

			// Lower part of crosshair
			gfx.PutPixel(x - 5, y, 255, 255, 255);
			gfx.PutPixel(x - 4, y, 255, 255, 255);
			gfx.PutPixel(x - 3, y, 255, 255, 255);
			gfx.PutPixel(x - 2, y, 255, 255, 255);
			gfx.PutPixel(x + 2, y, 255, 255, 255);
			gfx.PutPixel(x + 3, y, 255, 255, 255);
			gfx.PutPixel(x + 4, y, 255, 255, 255);
			gfx.PutPixel(x + 5, y, 255, 255, 255);
		}	
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		// Upper part of crosshair
		gfx.PutPixel(x, y - 5, 255, 0, 255);
		gfx.PutPixel(x, y - 4, 255, 0, 255);
		gfx.PutPixel(x, y - 3, 255, 0, 255);
		gfx.PutPixel(x, y - 2, 255, 0, 255);
		gfx.PutPixel(x, y + 2, 255, 0, 255);
		gfx.PutPixel(x, y + 3, 255, 0, 255);
		gfx.PutPixel(x, y + 4, 255, 0, 255);
		gfx.PutPixel(x, y + 5, 255, 0, 255);

		// Lower part of crosshair
		gfx.PutPixel(x - 5, y, 255, 0, 255);
		gfx.PutPixel(x - 4, y, 255, 0, 255);
		gfx.PutPixel(x - 3, y, 255, 0, 255);
		gfx.PutPixel(x - 2, y, 255, 0, 255);
		gfx.PutPixel(x + 2, y, 255, 0, 255);
		gfx.PutPixel(x + 3, y, 255, 0, 255);
		gfx.PutPixel(x + 4, y, 255, 0, 255);
		gfx.PutPixel(x + 5, y, 255, 0, 255);
	}
	else
	{
		// Upper part of crosshair
		gfx.PutPixel(x, y - 5, 255, 0, 0);
		gfx.PutPixel(x, y - 4, 255, 0, 0);
		gfx.PutPixel(x, y - 3, 255, 0, 0);
		gfx.PutPixel(x, y - 2, 255, 0, 0);
		gfx.PutPixel(x, y + 2, 255, 0, 0);
		gfx.PutPixel(x, y + 3, 255, 0, 0);
		gfx.PutPixel(x, y + 4, 255, 0, 0);
		gfx.PutPixel(x, y + 5, 255, 0, 0);
									   
		// Lower part of crosshair	   
		gfx.PutPixel(x - 5, y, 255, 0, 0);
		gfx.PutPixel(x - 4, y, 255, 0, 0);
		gfx.PutPixel(x - 3, y, 255, 0, 0);
		gfx.PutPixel(x - 2, y, 255, 0, 0);
		gfx.PutPixel(x + 2, y, 255, 0, 0);
		gfx.PutPixel(x + 3, y, 255, 0, 0);
		gfx.PutPixel(x + 4, y, 255, 0, 0);
		gfx.PutPixel(x + 5, y, 255, 0, 0);
	}
	*/
}
