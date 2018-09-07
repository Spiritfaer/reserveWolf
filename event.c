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

	if (sdlT->currentKey[SDL_SCANCODE_RIGHT] || sdlT->currentKey[SDL_SCANCODE_D])
	{
		oldDirX = cam->dir.X;
		cam->dir.X = cam->dir.X * cos(-t->rotSpeed) - cam->dir.Y * sin(-t->rotSpeed);
		cam->dir.Y = oldDirX * sin(-t->rotSpeed) + cam->dir.Y * cos(-t->rotSpeed);

		oldPlaneX = cam->plane.X;
		cam->plane.X = cam->plane.X * cos(-t->rotSpeed) - cam->plane.Y * sin(-t->rotSpeed);
		cam->plane.Y = oldPlaneX * sin(-t->rotSpeed) + cam->plane.Y * cos(-t->rotSpeed);
	}
	if (sdlT->currentKey[SDL_SCANCODE_LEFT] || sdlT->currentKey[SDL_SCANCODE_A])
	{
		oldDirX = cam->dir.X;
		cam->dir.X = cam->dir.X * cos(t->rotSpeed) - cam->dir.Y * sin(t->rotSpeed);
		cam->dir.Y = oldDirX * sin(t->rotSpeed) + cam->dir.Y * cos(t->rotSpeed);

		oldPlaneX = cam->plane.X;
		cam->plane.X = cam->plane.X * cos(t->rotSpeed) - cam->plane.Y * sin(t->rotSpeed);
		cam->plane.Y = oldPlaneX * sin(t->rotSpeed) + cam->plane.Y * cos(t->rotSpeed);
	}
}

void	audioSetings(t_SDL *sdlT)
{
	if (sdlT->event.type == SDL_KEYDOWN)
	{
		if (sdlT->currentKey[SDL_SCANCODE_P])
		{
			if (Mix_PausedMusic() == 1)
				Mix_ResumeMusic();
			else
				Mix_PauseMusic();
		}
		if (sdlT->currentKey[SDL_SCANCODE_KP_MULTIPLY])
		{
			if (sdlT->numTrack == 1)
				sdlT->numTrack = 0;
			else
				sdlT->numTrack = 1;
			Mix_PlayMusic(sdlT->music[sdlT->numTrack], -1);
		}
	}
	if (sdlT->currentKey[SDL_SCANCODE_KP_PLUS])
	{
		sdlT->volume += 1;
		if (sdlT->volume > 100)
			sdlT->volume = 100;
		Mix_VolumeMusic(sdlT->volume);
	}
	if (sdlT->currentKey[SDL_SCANCODE_KP_MINUS])
	{
		sdlT->volume -= 1;
		if (sdlT->volume <= 0)
			sdlT->volume = 0;
		Mix_VolumeMusic(sdlT->volume);
	}
}

void 	gameSetings(t_SDL *sdlT)
{
	if (sdlT->event.type == SDL_KEYDOWN)
	{
		if (sdlT->currentKey[SDL_SCANCODE_TAB])
		{
			if (sdlT->flag == GAME)
			{
				sdlT->menuFlag = 0;
				sdlT->flag = MENU;
			}
			else
				sdlT->flag = GAME;
			SDL_Delay(150);
		}
	}
}

void	gameMenuEvent(t_SDL *sdlT)
{
	if (sdlT->event.type == SDL_KEYDOWN)
	{
		if (sdlT->currentKey[SDL_SCANCODE_UP])
		{
			sdlT->menuFlag--;
			SDL_Delay(100);
		}
		if (sdlT->currentKey[SDL_SCANCODE_DOWN])
		{
			sdlT->menuFlag++;
			SDL_Delay(100);
		}
		sdlT->menuFlag = (sdlT->menuFlag < 0) ? (short)0 : sdlT->menuFlag;
		sdlT->menuFlag = (sdlT->menuFlag > 2) ? (short)2 : sdlT->menuFlag;
	}
	if (sdlT->currentKey[SDL_SCANCODE_RETURN] || sdlT->currentKey[SDL_SCANCODE_KP_ENTER])
	{
		if (sdlT->menuFlag == 0)
			sdlT->flag = GAME;
		else if (sdlT->menuFlag == 1)
			system("say 'meow'");
		else if (sdlT->menuFlag == 2)
			sdlT->loop = false;
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
	gameSetings(sdlT);
	if (sdlT->flag == GAME)
	{
		audioSetings(sdlT);
		ft_move(sdlT, cam, time);
		ft_rotate(sdlT, cam, time);
	}
	else if (sdlT->flag == MENU)
	{
		gameMenuEvent(sdlT);
	}
}
