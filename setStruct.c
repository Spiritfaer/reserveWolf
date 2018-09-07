//
// Created by Igor STALEVSKIY on 9/6/18.
//

#include "includes/wolf3d.h"

void	setCam(t_cam *cam)
{
	cam->pos.x = 7.5;
	cam->pos.y = 1.5;
	cam->dir.x = -1;
	cam->dir.y = 0;
	cam->plane.x = 0;
	cam->plane.y = 0.66;
}

void	setTime(t_time *t)
{
	t->old_time = t->time;
	t->time = SDL_GetTicks();
	t->frame_time = (t->time - t->old_time) / 1000.0;
	t->move_speed = t->frame_time * 3.0;
	t->rot_speed = t->frame_time * 2.0;
}

void	setPixFor(SDL_PixelFormat *pFormat)
{
	pFormat->BitsPerPixel = 32;
	pFormat->BytesPerPixel = 4;
	pFormat->palette = NULL;
	pFormat->Rmask = 0;
	pFormat->Gmask = 0;
	pFormat->Bmask = 0;
	pFormat->Amask = 0;
}

void	setMusic(t_sdl *sdlT)
{
	sdlT->num_track = 0;
	sdlT->music[0] = Mix_LoadMUS("sound/Future_City_Funk.mp3");
	sdlT->music[1] = Mix_LoadMUS("sound/Itty_Bitty_8_Bit.mp3");
	sdlT->volume = 20;

	if (!sdlT->music[0])
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	else
		Mix_PlayMusic(sdlT->music[sdlT->num_track], -1);
	Mix_VolumeMusic(sdlT->volume);
}
