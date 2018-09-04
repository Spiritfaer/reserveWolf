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

int8_t 	ft_initSDL(t_SDL *sdlT)
{
	int8_t result;

	result = 1;
	sdlT->mapT.PixelSizeW = (sdlT->argvT.flag & MAPW) ?
							sdlT->argvT.screenW : (int16_t)DEF_SCREEN_WIDTH;
	sdlT->mapT.PixelSizeH = (sdlT->argvT.flag & MAPH) ?
							sdlT->argvT.screenH : (int16_t)DEF_SCREEN_HEIGHT;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 && result--)
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
	IMG_Quit();
	SDL_Quit();
//	system("leaks wolf3d");
}
