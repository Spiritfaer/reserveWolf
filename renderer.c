//
// Created by Igor STALEVSKIY on 8/17/18.
//
#include "includes/wolf3d.h"

void	clearFloor(t_SDL *sdlT)
{
	int32_t y;

	SDL_SetRenderDrawColor(sdlT->renderer, 0x30, 0xB0, 0xFF, 0xFF);
	SDL_RenderClear(sdlT->renderer);
	y = (sdlT->mapT.PixelSizeH / 2);
	SDL_SetRenderDrawColor(sdlT->renderer, 0x40, 0x60, 0x40, 0xFF);
	while (y < sdlT->mapT.PixelSizeH)
	{
		SDL_RenderDrawLine(sdlT->renderer, 0, y, sdlT->mapT.PixelSizeW - 1, y);
		y++;
	}
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

void	makeTexture(SDL_Surface **tex, t_tex *texT)
{
	int imgFlags;
	int16_t x;
	SDL_PixelFormat pFormat;

	x = 7;
	imgFlags = IMG_INIT_PNG;
	char *path[8] = {"pics/greystone.png",
			"pics/wood.png",
			"pics/eagle.png",
			"pics/purplestone.png",
			"pics/redbrick.png",
			"pics/mossy.png",
			"pics/bluestone.png",
			"pics/colorstone.png"};
	if (!(IMG_Init(imgFlags) & imgFlags))
		ft_errors("IMG Init error!");
	setPixFor(&pFormat);
	while (x >= 0)
	{
		tex[x] = loadTexture(path[x], &pFormat);
		x--;
	}
	texT->pixel = NULL;
	texT->pixel2 = NULL;
	texT->texWidth = 64;
	texT->texHeight = 64;
}

void 	ft_process(t_SDL *sdlT)
{
	t_cam cam;
	t_ray ray;
	t_time time;
	uint16_t x;

	makeTexture(sdlT->textures, &sdlT->texT);
	setCam(&cam);

	while (sdlT->loop)
	{
		SDL_Surface *buffer = SDL_CreateRGBSurface(0,sdlT->mapT.PixelSizeW, sdlT->mapT.PixelSizeH, 32, 0, 0, 0, 0);
		clearFloor(sdlT);
		sdlT->texT.pixel2 = buffer->pixels;
		x = 0;
		while (x < sdlT->mapT.PixelSizeW)
		{
			InitRay(sdlT, &cam, &ray, x);
			Ray(&cam, &ray);
			Cast(&ray, &sdlT->mapT);
			Wall(&cam, &ray, sdlT->mapT.PixelSizeH);
			drawTextureWall(sdlT, &cam, &ray, x);
			x++;
		}

		SDL_Texture *tex = SDL_CreateTextureFromSurface(sdlT->renderer, buffer);
		SDL_RenderCopy(sdlT->renderer, tex, 0, 0);
		SDL_DestroyTexture(tex);
		SDL_FreeSurface(buffer);
		setTime(&time);
		event(sdlT, &cam, &time);
		SDL_RenderPresent(sdlT->renderer);
		SDL_RenderClear(sdlT->renderer);
	}
}
