/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	void DrawBox(int x, int y, int r, int g, int b);
	bool CollisionChecker(int x_Box0, int x_Box1, int y_Box0, int y_Box1);
	/*Homework*/
	void InhibitMovementPastScreenSize();
	int ClampSizeX(int x_mobile);
	int ClampSizeY(int y_mobile);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	// x and y modifiers
	// NOTE: upper < 795 and lower < 595
	//		 upper > 4   and lower > 4
	int x = 286; // x value of center of crosshair
	int y = 400; // y value of center of crosshair
	int vx = 0;
	int vy = 0;
	int draw_x = 500;
	int draw_y = 200;
	int draw_x1 = 333;
	int draw_y1 = 69;
	int mv_Increment = 1;
	int r = 255, g = 255, b = 255;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	bool isColliding = false;
	/********************************/
};