/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:48:46 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/07 11:48:47 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	ft_game_s(t_sdl *sdl_t)
{
	if (sdl_t->event.type == SDL_KEYDOWN)
	{
		if (sdl_t->cur_key[SDL_SCANCODE_TAB])
		{
			if (sdl_t->flag == GAME)
			{
				sdl_t->menu_f = 0;
				sdl_t->flag = MENU;
			}
			else
				sdl_t->flag = GAME;
			SDL_Delay(150);
		}
	}
}

void	ft_game_menu_e(t_sdl *sdl_t)
{
	if (sdl_t->event.type == SDL_KEYDOWN)
	{
		SDL_Delay(150);
		if (sdl_t->cur_key[SDL_SCANCODE_UP])
			sdl_t->menu_f--;
		if (sdl_t->cur_key[SDL_SCANCODE_DOWN])
			sdl_t->menu_f++;
		sdl_t->menu_f = (sdl_t->menu_f < 0) ? (short)2 : sdl_t->menu_f;
		sdl_t->menu_f = (sdl_t->menu_f > 2) ? (short)0 : sdl_t->menu_f;
	}
	if (sdl_t->cur_key[SDL_SCANCODE_RETURN]
		|| sdl_t->cur_key[SDL_SCANCODE_KP_ENTER])
	{
		if (sdl_t->menu_f == 0)
			sdl_t->flag = GAME;
		else if (sdl_t->menu_f == 1)
			sdl_t->flag = HELP;
		else if (sdl_t->menu_f == 2)
			sdl_t->loop = false;
		SDL_Delay(150);
	}
}

void	ft_menu_help(t_sdl *sdl_t)
{
	if (sdl_t->cur_key[SDL_SCANCODE_RETURN]
			|| sdl_t->cur_key[SDL_SCANCODE_KP_ENTER])
	{
		sdl_t->flag = MENU;
		SDL_Delay(150);
	}
}

void	ft_event_guard(t_sdl *sdl_t)
{
	ft_game_s(sdl_t);
	if (sdl_t->event.type == SDL_QUIT)
		sdl_t->loop = false;
	if (sdl_t->cur_key[SDL_SCANCODE_ESCAPE])
		sdl_t->loop = false;
}

void	event(t_sdl *sdl_t, t_cam *cam, t_time *time)
{
	if (sdl_t->flag == GAME)
	{
		SDL_PollEvent(&sdl_t->event);
		sdl_t->cur_key = SDL_GetKeyboardState(NULL);
		ft_audio_s(sdl_t);
		ft_audio_v(sdl_t);
		ft_move(sdl_t, cam, time);
		ft_rotate(sdl_t, cam, time);
	}
	else if (sdl_t->flag == MENU)
	{
		SDL_PollEvent(&sdl_t->event);
		sdl_t->cur_key = SDL_GetKeyboardState(NULL);
		ft_game_menu_e(sdl_t);
	}
	else if (sdl_t->flag == HELP)
	{
		SDL_PollEvent(&sdl_t->event);
		sdl_t->cur_key = SDL_GetKeyboardState(NULL);
		ft_menu_help(sdl_t);
	}
	ft_event_guard(sdl_t);
}
