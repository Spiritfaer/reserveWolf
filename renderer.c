/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:51:23 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 11:51:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	ft_draw_menu(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->ren, 0xFF, 0xFF, 0xFF, 0);
	SDL_RenderClear(sdl->ren);
	SDL_RenderCopy(sdl->ren, sdl->wrds[3].bl, NULL, &sdl->wrds[3].r_q);
	if (sdl->menu_f == 0)
	{
		SDL_RenderCopy(sdl->ren, sdl->wrds[0].bl, NULL, &sdl->wrds[0].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[1].red, NULL, &sdl->wrds[1].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[2].red, NULL, &sdl->wrds[2].r_q);
	}
	else if (sdl->menu_f == 1)
	{
		SDL_RenderCopy(sdl->ren, sdl->wrds[0].red, NULL, &sdl->wrds[0].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[1].bl, NULL, &sdl->wrds[1].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[2].red, NULL, &sdl->wrds[2].r_q);
	}
	else if (sdl->menu_f == 2)
	{
		SDL_RenderCopy(sdl->ren, sdl->wrds[0].red, NULL, &sdl->wrds[0].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[1].red, NULL, &sdl->wrds[1].r_q);
		SDL_RenderCopy(sdl->ren, sdl->wrds[2].bl, NULL, &sdl->wrds[2].r_q);
	}
}

void	ft_draw_game(t_sdl *sdl, t_cam *cam, t_ray *ray, t_floor *floor)
{
	while (sdl->x < sdl->m_t.pxl_s_w)
	{
		ft_init_ray(sdl, cam, ray, sdl->x);
		ft_ray(cam, ray);
		ft_cast(ray, &sdl->m_t);
		ft_wall(cam, ray, sdl->m_t.pxl_s_h);
		ft_draw_tex_w(sdl, cam, ray, sdl->x);
		ft_floor_cast(ray, &sdl->tex_t, cam, floor);
		ft_floor_add(floor, ray, sdl, cam);
		sdl->x++;
	}
	ft_spline(sdl, cam, &sdl->s_calc);
	sdl->pre_ren = SDL_CreateTextureFromSurface(sdl->ren, sdl->buffer);
	SDL_RenderCopy(sdl->ren, sdl->pre_ren, 0, 0);
	ft_draw_weapon(sdl);
}

void	ft_make_weapon(t_sdl *sdl, t_weapon *weapon)
{
	static char *path = "dopPNG/weapon.png";
	int16_t			x;
	SDL_PixelFormat	format;
	Uint32			form;

	x = 0;
	ft_set_pix_for(&format);
	weapon->weap_sur = ft_load_texture(path, &format);
	uint32_t *pixel = (uint32_t*)(weapon->weap_sur->pixels);
	SDL_Color col = get_color(pixel[0]);
	SDL_SetColorKey(weapon->weap_sur, SDL_TRUE, SDL_MapRGB(weapon->weap_sur->format, col.r, col.g, col.b));
	weapon->weap_tex = SDL_CreateTextureFromSurface(sdl->ren, weapon->weap_sur);
	SDL_QueryTexture(weapon->weap_tex, &form, 0, &weapon->anim[5].w, &weapon->anim[5].h);
	weapon->anim[5].x = 0;
	weapon->anim[5].y = 0;
	weapon->box_screen.w = weapon->anim[5].w + 250;
	weapon->box_screen.h = weapon->anim[5].h + 250;
	weapon->box_screen.x = sdl->m_t.pxl_s_h / 2 + weapon->anim[5].w / 2;
	weapon->box_screen.y = sdl->m_t.pxl_s_h - weapon->box_screen.h;
	while (x < 5)
	{
		weapon->anim[x].w = weapon->anim[5].w / 5;
		weapon->anim[x].h = weapon->anim[5].h / 5;
		weapon->anim[x].x = 0 + weapon->anim[5].w / 5 * x + x;
		weapon->anim[x].y = 5;
		x++;
	}
	sdl->weapon.num = -1;
}

void	ft_draw_weapon(t_sdl *sdl)
{
	if (sdl->weapon.num == -1)
		SDL_RenderCopy(sdl->ren, sdl->weapon.weap_tex, &sdl->weapon.anim[1], &sdl->weapon.box_screen);
	else
	{
		SDL_RenderCopy(sdl->ren, sdl->weapon.weap_tex, &sdl->weapon.anim[sdl->weapon.num], &sdl->weapon.box_screen);
		sdl->weapon.num++;
		if (sdl->weapon.num >= 5)
			sdl->weapon.num = -1;
	}
}

void	ft_pre_loop(t_sdl *sdl, t_cam *cam)
{
	ft_make_texture(sdl->txtr, &sdl->tex_t);
	ft_make_text(sdl);
	ft_make_weapon(sdl, &sdl->weapon);
	ft_set_cam(cam);
	ft_set_music(sdl);
}

void	ft_draw_help(t_sdl *sdl)
{
	int	i;

	i = 4;
	SDL_SetRenderDrawColor(sdl->ren, 0xFF, 0xFF, 0xFF, 0);
	SDL_RenderClear(sdl->ren);
	while (i < 9)
	{
		SDL_RenderCopy(sdl->ren, sdl->wrds[i].red, NULL, &sdl->wrds[i].r_q);
		i++;
	}
	SDL_RenderCopy(sdl->ren, sdl->wrds[i].bl, NULL, &sdl->wrds[i].r_q);
}

void	ft_process(t_sdl *sdl)
{
	t_cam	cam;
	t_ray	ray;
	t_time	time;
	t_floor	floor;

	ft_pre_loop(sdl, &cam);
	while (sdl->loop)
	{
		sdl->buffer = SDL_CreateRGBSurface(0,
			sdl->m_t.pxl_s_w, sdl->m_t.pxl_s_h, 32, 0, 0, 0, 0);
		sdl->tex_t.pxl2 = sdl->buffer->pixels;
		sdl->x = 0;
		if (sdl->flag & MENU)
			ft_draw_menu(sdl);
		else if (sdl->flag & HELP)
			ft_draw_help(sdl);
		else if (sdl->flag & GAME)
			ft_draw_game(sdl, &cam, &ray, &floor);
		SDL_DestroyTexture(sdl->pre_ren);
		SDL_FreeSurface(sdl->buffer);
		ft_set_time(&time);
		event(sdl, &cam, &time);
		SDL_RenderPresent(sdl->ren);
		SDL_RenderClear(sdl->ren);
	}
}
