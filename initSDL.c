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
		}
	}
	return (result);
}

int8_t	ft_initMix(t_SDL *sdlT)
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

int8_t	ft_initImg(t_SDL *sdlT)
{
	int8_t result;
	int imgFlags;

	result = 0;
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
		if (ft_initMix(sdlT) > 0 && ++result)
			if (ft_initTtf(sdlT) > 0 && ++result)
				if (ft_initImg(sdlT) > 0 && ++result)
				;
	if (result != 4)
		result = 0;
	return (result);
}

/*
int8_t 	ft_initSDL(t_SDL *sdlT)
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
		}
		if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("SDL_mixer could not initialize step two! SDL_mixer Error: %s\n", Mix_GetError());
			result = false;
		}
		int audioFlag = MIX_INIT_MP3;
		int initted = Mix_Init(audioFlag);
		if ((initted & audioFlag) != audioFlag)
		{
			printf("SDL_mixer could not initialize FOR MP3! SDL_mixer Error: %s\n", Mix_GetError());
			result = false;
		}
		sdlT->flag = MENU;
		if (TTF_Init() == -1)
		{
			printf("TTF_Init: %s\n", TTF_GetError());
			result = false;
		}
		else
		{
			sdlT->gFont = TTF_OpenFont( "font/wolfenstein.ttf", 28 );
			if(sdlT->gFont == NULL)
				printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		}
	}
	return (result);
}
*/

void	ft_end(t_SDL *sdlT)
{
	if (sdlT->renderer != NULL)
	{
		SDL_DestroyRenderer(sdlT->renderer);
		sdlT->renderer = NULL;
	}
	if (sdlT->window != NULL)
	{
		SDL_DestroyWindow(sdlT->window);
		sdlT->window = NULL;
	}
	for (int i = 0; i < 2; i++)
	{
		if (sdlT->music[i])
		{
			Mix_FreeMusic(sdlT->music[i]);
			sdlT->music[i] = NULL;
		}
	}

	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
//	system("leaks wolf3d");
}
