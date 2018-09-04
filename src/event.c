//
// Created by Igor STALEVSKIY on 8/12/18.
//

#include "../includes/including.h"


//void demo(t_base base, const uint8_t *currentKey, t_start *t)
//{
//	t->oldTime = t->time;
//	t->time = SDL_GetTicks();
//	double frameTime = (t->time - t->oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
////		print(1.0 / frameTime); //FPS counter
//
//
//
//	//speed modifiers
//	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
//
//	//move forward if no wall in front of you
//	if (currentKey[SDL_SCANCODE_UP] || currentKey[SDL_SCANCODE_W])
//	{
//		if (base.mapT.map[((int)(t->posX + t->dirX * moveSpeed)) + ((int)t->posY * base.mapT.mapW)] == 0)
//			t->posX += t->dirX * moveSpeed;
//		if (base.mapT.map[((int)(t->posX)) + (((int)(t->posY + t->dirY * moveSpeed)) * base.mapT.mapW)] == 0)
//			t->posY += t->dirY * moveSpeed;
//	}
//	//move backwards if no wall behind you
//	if (currentKey[SDL_SCANCODE_DOWN] || currentKey[SDL_SCANCODE_S])
//	{
//		if(base.mapT.map[(int)(t->posX - t->dirX * moveSpeed) + ((int)t->posY * base.mapT.mapW)] == 0)
//			t->posX -= t->dirX * moveSpeed;
//		if(base.mapT.map[(int)(t->posX) + ((int)(t->posY - t->dirY * moveSpeed)) * base.mapT.mapW] == 0)
//			t->posY -= t->dirY * moveSpeed;
//	}
//	//rotate to the right
//	if (currentKey[SDL_SCANCODE_RIGHT])
//	{
//		//both camera direction and camera plane must be rotated
//		double oldDirX = t->dirX;
//		t->dirX = t->dirX * cos(-rotSpeed) - t->dirY * sin(-rotSpeed);
//		t->dirY = oldDirX * sin(-rotSpeed) + t->dirY * cos(-rotSpeed);
//		double oldPlaneX = t->planeX;
//		t->planeX = t->planeX * cos(-rotSpeed) - t->planeY * sin(-rotSpeed);
//		t->planeY = oldPlaneX * sin(-rotSpeed) + t->planeY * cos(-rotSpeed);
//	}
//	//rotate to the left
//	if (currentKey[SDL_SCANCODE_LEFT])
//	{
//		//both camera direction and camera plane must be rotated
//		double oldDirX = t->dirX;
//		t->dirX = t->dirX * cos(rotSpeed) - t->dirY * sin(rotSpeed);
//		t->dirY = oldDirX * sin(rotSpeed) + t->dirY * cos(rotSpeed);
//		double oldPlaneX = t->planeX;
//		t->planeX = t->planeX * cos(rotSpeed) - t->planeY * sin(rotSpeed);
//		t->planeY = oldPlaneX * sin(rotSpeed) + t->planeY * cos(rotSpeed);
//	}
//}
