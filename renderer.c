//
// Created by Igor STALEVSKIY on 8/17/18.
//
#include "includes/wolf3d.h"

SDL_Surface*	loadTexture(char *name, SDL_PixelFormat *pFormat)
{
	SDL_Surface* optimizedSurface;
	SDL_Surface* loadedSurface;

	optimizedSurface = NULL;
	loadedSurface = IMG_Load(name);
	if(!loadedSurface)
		printf("Unable to load image %s! SDL_image Error: %s\n", name, IMG_GetError());
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, pFormat, 0);
		if(!optimizedSurface)
			printf( "Unable to optimize image %s! SDL Error: %s\n", name, SDL_GetError());
		SDL_FreeSurface(loadedSurface);
	}
	return (optimizedSurface);
}

void	makeTexture(SDL_Surface **tex, t_tex *texT, SDL_Surface **menuBG)
{
	int16_t x;
	SDL_PixelFormat pFormat;

	x = 7;
	char *path[8] = {"pics/greystone.png",
					 "pics/wood.png",
					 "pics/eagle.png",
					 "pics/purplestone.png",
					 "pics/redbrick.png",
					 "pics/mossy.png",
					 "pics/bluestone.png",
					 "pics/colorstone.png"};
	setPixFor(&pFormat);
	while (x >= 0)
	{
		tex[x] = loadTexture(path[x], &pFormat);
		x--;
	}
	*menuBG = loadTexture("pics/wall.png", &pFormat);
	texT->pixel = NULL;
	texT->pixel2 = NULL;
	texT->texWidth = 64;
	texT->texHeight = 64;
}



void 	ft_process(t_SDL *sdlT)
{
	t_cam camT;
	t_ray ray;
	t_time time;
	t_floor floor;
	SDL_Color gColor = {0, 0, 0, 0};

	makeTexture(sdlT->textures, &sdlT->texT, &sdlT->menuBG);
	setCam(&camT);
	setMusic(sdlT);
	while (sdlT->loop)
	{
		sdlT->buffer = SDL_CreateRGBSurface(0,sdlT->mapT.PixelSizeW, sdlT->mapT.PixelSizeH, 32, 0, 0, 0, 0);
		sdlT->texT.pixel2 = sdlT->buffer->pixels;
		sdlT->x = 0;
		if (sdlT->flag & MENU)
		{
			sdlT->preRender = SDL_CreateTextureFromSurface(sdlT->renderer, sdlT->menuBG);
			SDL_RenderCopy(sdlT->renderer, sdlT->preRender, 0, 0);

		}
		else if (sdlT->flag & GAME)
		{
			while (sdlT->x < sdlT->mapT.PixelSizeW)
			{
				InitRay(sdlT, &camT, &ray, sdlT->x);
				Ray(&camT, &ray);
				Cast(&ray, &sdlT->mapT);
				Wall(&camT, &ray, sdlT->mapT.PixelSizeH);
				drawTextureWall(sdlT, &camT, &ray, sdlT->x);
				floorCast(&ray, &sdlT->texT, &camT, &floor);
				floorAdd(&floor, &ray, sdlT, &camT);
				sdlT->x++;
			}
			sdlT->preRender = SDL_CreateTextureFromSurface(sdlT->renderer, sdlT->buffer);
			SDL_RenderCopy(sdlT->renderer, sdlT->preRender, 0, 0);
		}

		SDL_DestroyTexture(sdlT->preRender);
		SDL_FreeSurface(sdlT->buffer);
		setTime(&time);
		event(sdlT, &camT, &time);
		SDL_RenderPresent(sdlT->renderer);
		SDL_RenderClear(sdlT->renderer);
	}
}
