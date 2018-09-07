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

void	makeText(t_SDL *sdlT)
{
	char *str[] = {"START GAME", "SETTINGS", "QUIT"};
	char *font = "font/wolfenstein.ttf";
	SDL_Surface *tmp = NULL;
	int16_t i = 0;
	SDL_Color black = {0, 0, 0, 0};
	SDL_Color red = {200, 0, 0, 0};
	TTF_Font *gFont = TTF_OpenFont(font, 88);
	TTF_Font *gFontBig = TTF_OpenFont(font, 150);
	while (i < 3)
	{
		tmp = TTF_RenderText_Blended(gFont, str[i], black);
		TTF_SizeText(gFont, str[i], &sdlT->words[i].renderQuad.w, &sdlT->words[i].renderQuad.h);
		sdlT->words[i].renderQuad.y = 200 + i * 100;
		sdlT->words[i].renderQuad.x = (int)((sdlT->mapT.PixelSizeW / 4) * 2.5);
		sdlT->words[i].match = SDL_CreateTextureFromSurface(sdlT->renderer, tmp);
		SDL_FreeSurface(tmp);
		tmp = TTF_RenderText_Blended(gFont, str[i], red);
		sdlT->words[i].mismatch = SDL_CreateTextureFromSurface(sdlT->renderer, tmp);
		SDL_FreeSurface(tmp);
		i++;
	}
	tmp = TTF_RenderText_Blended(gFont, "_%", red);
	TTF_SizeText(gFontBig, "_%", &sdlT->words[3].renderQuad.w, &sdlT->words[3].renderQuad.h);
	sdlT->words[3].match = SDL_CreateTextureFromSurface(sdlT->renderer, tmp);
	sdlT->words[3].renderQuad.y = (int)(sdlT->mapT.PixelSizeH / 2.5) - sdlT->words[3].renderQuad.h / 2;
	sdlT->words[3].renderQuad.x = (int)(sdlT->mapT.PixelSizeW / 3.2) - sdlT->words[3].renderQuad.w / 2;
	SDL_FreeSurface(tmp);
	TTF_CloseFont(gFont);
	TTF_CloseFont(gFontBig);
}

void	drawMenu(t_SDL *sdlT)
{
	SDL_RenderCopy(sdlT->renderer, sdlT->words[3].match, NULL, &sdlT->words[3].renderQuad);
	if (sdlT->menuFlag == 0)
	{
		SDL_RenderCopy(sdlT->renderer, sdlT->words[0].match, NULL, &sdlT->words[0].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[1].mismatch, NULL, &sdlT->words[1].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[2].mismatch, NULL, &sdlT->words[2].renderQuad);
	}
	else if (sdlT->menuFlag == 1)
	{
		SDL_RenderCopy(sdlT->renderer, sdlT->words[0].mismatch, NULL, &sdlT->words[0].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[1].match, NULL, &sdlT->words[1].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[2].mismatch, NULL, &sdlT->words[2].renderQuad);
	}
	else if (sdlT->menuFlag == 2)
	{
		SDL_RenderCopy(sdlT->renderer, sdlT->words[0].mismatch, NULL, &sdlT->words[0].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[1].mismatch, NULL, &sdlT->words[1].renderQuad);
		SDL_RenderCopy(sdlT->renderer, sdlT->words[2].match, NULL, &sdlT->words[2].renderQuad);
	}
}

void 	ft_process(t_SDL *sdlT)
{
	t_cam camT;
	t_ray ray;
	t_time time;
	t_floor floor;

	makeTexture(sdlT->textures, &sdlT->texT, &sdlT->menuBG);
	makeText(sdlT);
	setCam(&camT);
	setMusic(sdlT);
	while (sdlT->loop)
	{
		sdlT->buffer = SDL_CreateRGBSurface(0,sdlT->mapT.PixelSizeW, sdlT->mapT.PixelSizeH, 32, 0, 0, 0, 0);
		sdlT->texT.pixel2 = sdlT->buffer->pixels;
		sdlT->x = 0;
		if (sdlT->flag & MENU)
		{
			SDL_SetRenderDrawColor(sdlT->renderer, 0xFF, 0xFF, 0xFF, 0);
			SDL_RenderClear(sdlT->renderer);
			SDL_RenderCopy(sdlT->renderer, sdlT->preRender, 0, 0);
			drawMenu(sdlT);
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
