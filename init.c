#include "includes/wolf3d.h"

int8_t	ft_initSdl(t_SDL *sdlT)
{
	int8_t result;

	result = 1;
	sdlT->mapT.PixelSizeW = (sdlT->argvT.flag & MAPW) ?
							sdlT->argvT.screenW : (int16_t)DEF_SCREEN_WIDTH;
	sdlT->mapT.PixelSizeH = (sdlT->argvT.flag & MAPH) ?
							sdlT->argvT.screenH : (int16_t)DEF_SCREEN_HEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 && result--)
		ft_putendl_fd(SDL_GetError(), 2);
	else
	{
		sdlT->window = SDL_CreateWindow("Doom style", 960, 400,
			sdlT->mapT.PixelSizeW, sdlT->mapT.PixelSizeH, SDL_WINDOW_SHOWN);
		if (!sdlT->window && result--)
			ft_putendl_fd(SDL_GetError(), 2);
		else
		{
			sdlT->renderer = SDL_CreateRenderer(sdlT->window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			sdlT->textures = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 8);
			sdlT->loop = 1;
			sdlT->flag = MENU;
			sdlT->menuFlag = 0;
		}
	}
	return (result);
}

int8_t	ft_initMix(void)
{
	int8_t result;
	int initted;

	result = 1;
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 && result--)
		printf("SDL_mixer Error: %s\n", Mix_GetError());
	initted = Mix_Init(MIX_INIT_MP3);
	if ((initted & MIX_INIT_MP3) != MIX_INIT_MP3 && result--)
		printf("SDL_mixer Error: %s\n", Mix_GetError());
	return (result);
}

int8_t	ft_initTtf(t_SDL *sdlT)
{
	int8_t result;

	result = 1;
	if (TTF_Init() == -1 && result--)
		printf("TTF_Init: %s\n", TTF_GetError());
	else
	{
		sdlT->gFont = TTF_OpenFont("font/wolfenstein.ttf", 28);
		if(sdlT->gFont == NULL && result--)
			printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	return (result);
}

int8_t	ft_initImg(void)
{
	int8_t result;
	int imgFlags;

	result = 1;
	imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags) && result--)
		ft_errors("IMG Init error!");
	return (result);
}

int8_t 	ft_INIT(t_SDL *sdlT)
{
	int8_t result;

	result = 0;
	if (ft_initSdl(sdlT) > 0 && ++result)
		if (ft_initTtf(sdlT) > 0 && ++result)
			if (ft_initMix() > 0 && ++result)
				if (ft_initImg() > 0 && ++result)
					;
	if (result != 4)
		result = 0;
	return (result);
}
