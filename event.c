//
// Created by Igor STALEVSKIY on 8/19/18.
//

#include "includes/wolf3d.h"

void	ft_move(t_SDL *sdlT, t_cam *cam, t_time *t)
{
	if (sdlT->currentKey[SDL_SCANCODE_UP] || sdlT->currentKey[SDL_SCANCODE_W])
	{
		if (sdlT->mapT.map[(int)(cam->pos.X + cam->dir.X * t->moveSpeed)][(int)cam->pos.Y] == false)
			cam->pos.X += cam->dir.X * t->moveSpeed;
		if (sdlT->mapT.map[(int)cam->pos.X][(int)(cam->pos.Y + cam->dir.Y * t->moveSpeed)] == false)
			cam->pos.Y += cam->dir.Y * t->moveSpeed;
	}
	if (sdlT->currentKey[SDL_SCANCODE_DOWN] || sdlT->currentKey[SDL_SCANCODE_S])
	{
		if(sdlT->mapT.map[(int)(cam->pos.X - cam->dir.X * t->moveSpeed)][(int)cam->pos.Y] == false)
			cam->pos.X -= cam->dir.X * t->moveSpeed;
		if(sdlT->mapT.map[(int)cam->pos.X][(int)(cam->pos.Y - cam->dir.Y * t->moveSpeed)] == false)
			cam->pos.Y -= cam->dir.Y * t->moveSpeed;
	}
}

void	ft_rotate(t_SDL *sdlT, t_cam *cam, t_time *t)
{
	double oldDirX;
	double oldPlaneX;

	if (sdlT->currentKey[SDL_SCANCODE_RIGHT])
	{
		oldDirX = cam->dir.X;
		cam->dir.X = cam->dir.X * cos(-t->rotSpeed) - cam->dir.Y * sin(-t->rotSpeed);
		cam->dir.Y = oldDirX * sin(-t->rotSpeed) + cam->dir.Y * cos(-t->rotSpeed);

		oldPlaneX = cam->plane.X;
		cam->plane.X = cam->plane.X * cos(-t->rotSpeed) - cam->plane.Y * sin(-t->rotSpeed);
		cam->plane.Y = oldPlaneX * sin(-t->rotSpeed) + cam->plane.Y * cos(-t->rotSpeed);
	}
	if (sdlT->currentKey[SDL_SCANCODE_LEFT])
	{
		oldDirX = cam->dir.X;
		cam->dir.X = cam->dir.X * cos(t->rotSpeed) - cam->dir.Y * sin(t->rotSpeed);
		cam->dir.Y = oldDirX * sin(t->rotSpeed) + cam->dir.Y * cos(t->rotSpeed);

		oldPlaneX = cam->plane.X;
		cam->plane.X = cam->plane.X * cos(t->rotSpeed) - cam->plane.Y * sin(t->rotSpeed);
		cam->plane.Y = oldPlaneX * sin(t->rotSpeed) + cam->plane.Y * cos(t->rotSpeed);
	}
}

void	event(t_SDL *sdlT, t_cam *cam, t_time *time)
{
	SDL_PollEvent(&sdlT->event);
	sdlT->currentKey = SDL_GetKeyboardState(NULL);
	if (sdlT->currentKey[SDL_SCANCODE_ESCAPE])
		sdlT->loop = false;
	if (sdlT->event.type == SDL_QUIT)
		sdlT->loop = false;
	ft_move(sdlT, cam, time);
	ft_rotate(sdlT, cam, time);
}
