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
		if (!inhibitRight)
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
	isShapeChanged = wnd.kbd.KeyIsPressed(VK_SPACE);
	x += vx;
	y += vy;

}

void Game::ComposeFrame()
{
	if(isShapeChanged)
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
}
