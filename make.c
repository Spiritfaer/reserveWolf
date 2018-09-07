//
// Created by Igor STALEVSKIY on 9/7/18.
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
	*menuBG = loadTexture("pics/ft_wall.png", &pFormat);
	texT->pixel = NULL;
	texT->pixel2 = NULL;
	texT->tex_w = 64;
	texT->tex_h = 64;
}

void	makeText(t_sdl *sdlT)
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
		TTF_SizeText(gFont, str[i], &sdlT->wrds[i].r_q.w, &sdlT->wrds[i].r_q.h);
		sdlT->wrds[i].r_q.y = 200 + i * 100;
		sdlT->wrds[i].r_q.x = (int)((sdlT->m_t.pxl_s_W / 4) * 2.5);
		sdlT->wrds[i].bl = SDL_CreateTextureFromSurface(sdlT->ren, tmp);
		SDL_FreeSurface(tmp);
		tmp = TTF_RenderText_Blended(gFont, str[i], red);
		sdlT->wrds[i].red = SDL_CreateTextureFromSurface(sdlT->ren, tmp);
		SDL_FreeSurface(tmp);
		i++;
	}
	tmp = TTF_RenderText_Blended(gFont, "_%", red);
	TTF_SizeText(gFontBig, "_%", &sdlT->wrds[3].r_q.w, &sdlT->wrds[3].r_q.h);
	sdlT->wrds[3].bl = SDL_CreateTextureFromSurface(sdlT->ren, tmp);
	sdlT->wrds[3].r_q.y = (int)(sdlT->m_t.pxl_s_h / 2.5) - sdlT->wrds[3].r_q.h / 2;
	sdlT->wrds[3].r_q.x = (int)(sdlT->m_t.pxl_s_W / 3.2) - sdlT->wrds[3].r_q.w / 2;
	SDL_FreeSurface(tmp);
	TTF_CloseFont(gFont);
	TTF_CloseFont(gFontBig);
}

int8_t		makeMap(t_sdl *sdlT)
{
	int16_t		fd;

	if (!(sdlT->argv_t.flag & MAPN))
		return (ft_errors("error m_t flag"));
	else
	{
		fd = (int16_t)open(sdlT->argv_t.map_name, O_RDONLY);
		if (fd < 1)
			return (ft_errors("error fd"));
		else
			sdlT->m_t.head = ft_pars_file(fd);
	}
	ft_revers_list(&sdlT->m_t.head);
	if (!mapping(&sdlT->m_t))
		return (0);
	close(fd);
#ifdef DEBUG
	print_map(&sdlT->m_t);
#endif
	return (1);
}
