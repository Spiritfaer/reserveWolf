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

void	ft_audio_v(t_sdl *sdl_t)
{
	if (sdl_t->cur_key[SDL_SCANCODE_KP_PLUS])
	{
		sdl_t->volume += 1;
		if (sdl_t->volume > 100)
			sdl_t->volume = 100;
		Mix_VolumeMusic(sdl_t->volume);
	}
	if (sdl_t->cur_key[SDL_SCANCODE_KP_MINUS])
	{
		sdl_t->volume -= 1;
		if (sdl_t->volume <= 0)
			sdl_t->volume = 0;
		Mix_VolumeMusic(sdl_t->volume);
	}
}

void	ft_audio_s(t_sdl *sdl_t)
{
	if (sdl_t->event.type == SDL_KEYDOWN)
	{
		if (sdl_t->cur_key[SDL_SCANCODE_P])
		{
			if (Mix_PausedMusic() == 1)
				Mix_ResumeMusic();
			else
				Mix_PauseMusic();
		}
		if (sdl_t->cur_key[SDL_SCANCODE_KP_MULTIPLY])
		{
			if (sdl_t->num_track == 1)
				sdl_t->num_track = 0;
			else
				sdl_t->num_track = 1;
			Mix_PlayMusic(sdl_t->music[sdl_t->num_track], -1);
		}
	}
}

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
		if (sdl_t->cur_key[SDL_SCANCODE_UP])
		{
			sdl_t->menu_f--;
			SDL_Delay(100);
		}
		if (sdl_t->cur_key[SDL_SCANCODE_DOWN])
		{
			sdl_t->menu_f++;
			SDL_Delay(100);
		}
		sdl_t->menu_f = (sdl_t->menu_f < 0) ? (short)0 : sdl_t->menu_f;
		sdl_t->menu_f = (sdl_t->menu_f > 2) ? (short)2 : sdl_t->menu_f;
	}
	if (sdl_t->cur_key[SDL_SCANCODE_RETURN]
		|| sdl_t->cur_key[SDL_SCANCODE_KP_ENTER])
	{
		if (sdl_t->menu_f == 0)
			sdl_t->flag = GAME;
		else if (sdl_t->menu_f == 1)
			system("say 'meow'");
		else if (sdl_t->menu_f == 2)
			sdl_t->loop = false;
	}
}

void	event(t_sdl *sdl_t, t_cam *cam, t_time *time)
{
	SDL_PollEvent(&sdl_t->event);
	sdl_t->cur_key = SDL_GetKeyboardState(NULL);
	if (sdl_t->cur_key[SDL_SCANCODE_ESCAPE])
		sdl_t->loop = false;
	if (sdl_t->event.type == SDL_QUIT)
		sdl_t->loop = false;
	ft_game_s(sdl_t);
	if (sdl_t->flag == GAME)
	{
		ft_audio_s(sdl_t);
		ft_audio_v(sdl_t);
		ft_move(sdl_t, cam, time);
		ft_rotate(sdl_t, cam, time);
	}
	else if (sdl_t->flag == MENU)
	{
		ft_game_menu_e(sdl_t);
	}
}
