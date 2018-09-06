//
// Created by Igor STALEVSKIY on 9/6/18.
//

#include "includes/wolf3d.h"

void	setCam(t_cam *cam)
{
	cam->pos.X = 7.5;
	cam->pos.Y = 1.5;
	cam->dir.X = -1;
	cam->dir.Y = 0;
	cam->plane.X = 0;
	cam->plane.Y = 0.66;
}

void	setTime(t_time *t)
{
	t->oldTime = t->time;
	t->time = SDL_GetTicks();
	t->frameTime = (t->time - t->oldTime) / 1000.0;
	t->moveSpeed = t->frameTime * 3.0;
	t->rotSpeed = t->frameTime * 2.0;
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

void	setMusic(t_SDL *sdlT)
{
	sdlT->numTrack = 0;
	sdlT->music[0] = Mix_LoadMUS("sound/Future_City_Funk.mp3");
	sdlT->music[1] = Mix_LoadMUS("sound/Itty_Bitty_8_Bit.mp3");
	sdlT->volume = 20;

	if (!sdlT->music[0])
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	else
		Mix_PlayMusic(sdlT->music[sdlT->numTrack], -1);
	Mix_VolumeMusic(sdlT->volume);
}
