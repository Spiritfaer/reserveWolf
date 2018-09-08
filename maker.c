/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:00:04 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 11:00:06 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

SDL_Surface	*ft_load_texture(char *name, SDL_PixelFormat *format)
{
	SDL_Surface *opt_sur;
	SDL_Surface *load_sur;

	opt_sur = NULL;
	load_sur = IMG_Load(name);
	if (!load_sur)
		printf("Unload img %s! %s\n", name, IMG_GetError());
	else
	{
		opt_sur = SDL_ConvertSurface(load_sur, format, 0);
		if (!opt_sur)
			printf("Unable to optimize image %s!"
					"SDL Error: %s\n", name, SDL_GetError());
		SDL_FreeSurface(load_sur);
	}
	return (opt_sur);
}

void		ft_make_texture(SDL_Surface **tex, t_tex *tex_t)
{
	int16_t			x;
	SDL_PixelFormat	format;
	static char		*path[8] = {"pics/greystone.png",
					"pics/wood.png",
					"pics/eagle.png",
					"pics/purplestone.png",
					"pics/redbrick.png",
					"pics/mossy.png",
					"pics/bluestone.png",
					"pics/colorstone.png"};

	x = 7;
	ft_set_pix_for(&format);
	while (x >= 0)
	{
		tex[x] = ft_load_texture(path[x], &format);
		x--;
	}
	tex_t->pixel = NULL;
	tex_t->pixel2 = NULL;
	tex_t->twh.x = 64;
	tex_t->twh.y = 64;
}

void		ft_set_w(t_sdl *sdl_t, TTF_Font *f, SDL_Surface *tmp, char **str)
{
	SDL_Color	black;
	SDL_Color	red;
	int16_t		i;

	black = ft_set_color(0, 0, 0);
	red = ft_set_color(200, 0, 0);
	i = 0;
	while (i < 3)
	{
		tmp = TTF_RenderText_Blended(f, str[i], black);
		TTF_SizeText(f, str[i], &sdl_t->wrds[i].r_q.w, &sdl_t->wrds[i].r_q.h);
		sdl_t->wrds[i].r_q.y = 200 + i * 100;
		sdl_t->wrds[i].r_q.x = (int)((sdl_t->m_t.pxl_s_w / 4) * 2.5);
		sdl_t->wrds[i].bl = SDL_CreateTextureFromSurface(sdl_t->ren, tmp);
		SDL_FreeSurface(tmp);
		tmp = TTF_RenderText_Blended(f, str[i], red);
		sdl_t->wrds[i].red = SDL_CreateTextureFromSurface(sdl_t->ren, tmp);
		SDL_FreeSurface(tmp);
		i++;
	}
}

void		ft_make_text(t_sdl *sdl_t)
{
	static char	*str[] = {"START GAME", "SETTINGS", "QUIT"};
	static char	*font = "font/wolfenstein.ttf";
	SDL_Surface *tmp;
	TTF_Font	*g_font;
	TTF_Font	*g_font_big;

	tmp = NULL;
	g_font = TTF_OpenFont(font, 88);
	g_font_big = TTF_OpenFont(font, 150);
	ft_set_w(sdl_t, g_font, tmp, str);
	tmp = TTF_RenderText_Blended(g_font, "_%", ft_set_color(200, 0, 0));
	TTF_SizeText(g_font_big, "_%",
				&sdl_t->wrds[3].r_q.w, &sdl_t->wrds[3].r_q.h);
	sdl_t->wrds[3].bl = SDL_CreateTextureFromSurface(sdl_t->ren, tmp);
	sdl_t->wrds[3].r_q.y = (int)(sdl_t->m_t.pxl_s_h / 2.5)
						- sdl_t->wrds[3].r_q.h / 2;
	sdl_t->wrds[3].r_q.x = (int)(sdl_t->m_t.pxl_s_w / 3.2)
						- sdl_t->wrds[3].r_q.w / 2;
	SDL_FreeSurface(tmp);
	TTF_CloseFont(g_font);
	TTF_CloseFont(g_font_big);
}

int8_t		ft_make_map(t_sdl *sdl_t)
{
	int16_t	fd;

	if (!(sdl_t->argv_t.flag & MAPN))
		return (ft_errors("error m_t flag"));
	else
	{
		fd = (int16_t)open(sdl_t->argv_t.map_name, O_RDONLY);
		if (fd < 1)
			return (ft_errors("error fd"));
		else
			sdl_t->m_t.head = ft_pars_file(fd);
	}
	ft_revers_list(&sdl_t->m_t.head);
	if (!ft_mapping(&sdl_t->m_t))
		return (0);
	close(fd);
	return (1);
}
