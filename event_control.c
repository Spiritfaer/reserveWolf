/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:36:04 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 10:36:10 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

bool	ft_collisions(int map)
{
	if (map > greystone && map < barrel)
		return (true);
	return (false);
}

void	ft_move(t_sdl *sdl_t, t_cam *cam, t_time *t)
{
	if (sdl_t->cur_key[SDL_SCANCODE_UP] || sdl_t->cur_key[SDL_SCANCODE_W])
	{
		if (ft_collisions(sdl_t->m_t.map[(int)(cam->pos.x + cam->dir.x * t->move_speed)]
			[(int)cam->pos.y]) == false)
			cam->pos.x += cam->dir.x * t->move_speed;
		if (ft_collisions(sdl_t->m_t.map[(int)cam->pos.x]
			[(int)(cam->pos.y + cam->dir.y * t->move_speed)]) == false)
			cam->pos.y += cam->dir.y * t->move_speed;
	}
	if (sdl_t->cur_key[SDL_SCANCODE_DOWN] || sdl_t->cur_key[SDL_SCANCODE_S])
	{
		if (ft_collisions(sdl_t->m_t.map[(int)(cam->pos.x - cam->dir.x * t->move_speed)]
			[(int)cam->pos.y]) == false)
			cam->pos.x -= cam->dir.x * t->move_speed;
		if (ft_collisions(sdl_t->m_t.map[(int)cam->pos.x]
			[(int)(cam->pos.y - cam->dir.y * t->move_speed)]) == false)
			cam->pos.y -= cam->dir.y * t->move_speed;
	}
}

void	ft_rotate(t_sdl *sdl_t, t_cam *cam, t_time *t)
{
	double o_d_x;
	double o_p_x;

	if (sdl_t->cur_key[SDL_SCANCODE_RIGHT] || sdl_t->cur_key[SDL_SCANCODE_D])
	{
		o_d_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(-t->rot_s) - cam->dir.y * sin(-t->rot_s);
		cam->dir.y = o_d_x * sin(-t->rot_s) + cam->dir.y * cos(-t->rot_s);
		o_p_x = cam->pl.x;
		cam->pl.x = cam->pl.x * cos(-t->rot_s) - cam->pl.y * sin(-t->rot_s);
		cam->pl.y = o_p_x * sin(-t->rot_s) + cam->pl.y * cos(-t->rot_s);
	}
	if (sdl_t->cur_key[SDL_SCANCODE_LEFT] || sdl_t->cur_key[SDL_SCANCODE_A])
	{
		o_d_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(t->rot_s) - cam->dir.y * sin(t->rot_s);
		cam->dir.y = o_d_x * sin(t->rot_s) + cam->dir.y * cos(t->rot_s);
		o_p_x = cam->pl.x;
		cam->pl.x = cam->pl.x * cos(t->rot_s) - cam->pl.y * sin(t->rot_s);
		cam->pl.y = o_p_x * sin(t->rot_s) + cam->pl.y * cos(t->rot_s);
	}
}
