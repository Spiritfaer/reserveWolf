//
// Created by Igor STALEVSKIY on 8/17/18.
//
#include "includes/wolf3d.h"

void	drawMenu(t_sdl *sdlT)
{
	SDL_SetRenderDrawColor(sdlT->ren, 0xFF, 0xFF, 0xFF, 0);
	SDL_RenderClear(sdlT->ren);
	SDL_RenderCopy(sdlT->ren, sdlT->pre_ren, 0, 0);
	SDL_RenderCopy(sdlT->ren, sdlT->wrds[3].bl, NULL, &sdlT->wrds[3].r_q);
	if (sdlT->menu_f == 0)
	{
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[0].bl, NULL, &sdlT->wrds[0].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[1].red, NULL, &sdlT->wrds[1].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[2].red, NULL, &sdlT->wrds[2].r_q);
	}
	else if (sdlT->menu_f == 1)
	{
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[0].red, NULL, &sdlT->wrds[0].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[1].bl, NULL, &sdlT->wrds[1].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[2].red, NULL, &sdlT->wrds[2].r_q);
	}
	else if (sdlT->menu_f == 2)
	{
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[0].red, NULL, &sdlT->wrds[0].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[1].red, NULL, &sdlT->wrds[1].r_q);
		SDL_RenderCopy(sdlT->ren, sdlT->wrds[2].bl, NULL, &sdlT->wrds[2].r_q);
	}
}

void	drawGame(t_sdl *sdlT, t_cam *camT, t_ray *ray, t_floor *floor)
{
	while (sdlT->x < sdlT->m_t.pxl_s_W)
	{
		InitRay(sdlT, camT, ray, sdlT->x);
		Ray(camT, ray);
		Cast(ray, &sdlT->m_t);
		ft_wall(camT, ray, sdlT->m_t.pxl_s_h);
		ft_draw_tex_w(sdlT, camT, ray, sdlT->x);
		floorCast(ray, &sdlT->tex_t, camT, floor);
		floorAdd(floor, ray, sdlT, camT);
		sdlT->x++;
	}
	sdlT->pre_ren = SDL_CreateTextureFromSurface(sdlT->ren, sdlT->buffer);
	SDL_RenderCopy(sdlT->ren, sdlT->pre_ren, 0, 0);
}

void	preLoop(t_sdl *sdlT, t_cam *camT)
{
	makeTexture(sdlT->textures, &sdlT->tex_t, &sdlT->menu_bg);
	makeText(sdlT);
	setCam(camT);
	setMusic(sdlT);
}

void 	ft_process(t_sdl *sdlT)
{
	t_cam camT;
	t_ray ray;
	t_time time;
	t_floor floor;

	preLoop(sdlT, &camT);
	while (sdlT->loop)
	{
		sdlT->buffer = SDL_CreateRGBSurface(0,
			sdlT->m_t.pxl_s_W, sdlT->m_t.pxl_s_h, 32, 0, 0, 0, 0);
		sdlT->tex_t.pixel2 = sdlT->buffer->pixels;
		sdlT->x = 0;
		if (sdlT->flag & MENU)
		{
			drawMenu(sdlT);
		}
		else if (sdlT->flag & GAME)
		{
			drawGame(sdlT, &camT, &ray, &floor);
		}
		SDL_DestroyTexture(sdlT->pre_ren);
		SDL_FreeSurface(sdlT->buffer);
		setTime(&time);
		event(sdlT, &camT, &time);
		SDL_RenderPresent(sdlT->ren);
		SDL_RenderClear(sdlT->ren);
	}
}
