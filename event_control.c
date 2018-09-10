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

enum {wall, space};

int8_t	ft_sp_cll(t_sdl *sdl, int16_t map)
{
	if ((map > greystone && map < barrel))
		return (wall);
	if ((map == barrel || map == pillar) && sdl->sp[sdl->m_t.sprit_num - 1].dist < 0.2)
		return (wall);
	return (space);
}

void	ft_move(t_sdl *sdl, t_cam *cam, t_time *t)
{
	t_v2d wall_box;
	double x;

	x = 0.1;
	if (cam->dir.x < 0)
		wall_box.x = -x;
	else
		wall_box.x = x;
	if (cam->dir.y < 0)
		wall_box.y = -x;
	else
		wall_box.y = x;
	if (sdl->cur_key[SDL_SCANCODE_UP] || sdl->cur_key[SDL_SCANCODE_W])
	{
		if (ft_sp_cll(sdl, sdl->m_t.map[(int)(cam->pos.x + cam->dir.x * t->move_speed + wall_box.x)][(int)(cam->pos.y + wall_box.y)]) == space)
			cam->pos.x += cam->dir.x * t->move_speed;
		if (ft_sp_cll(sdl, sdl->m_t.map[(int)(cam->pos.x + wall_box.x)][(int)(cam->pos.y + cam->dir.y * t->move_speed + wall_box.y)]) == space)
			cam->pos.y += cam->dir.y * t->move_speed;
	}
	if (sdl->cur_key[SDL_SCANCODE_DOWN] || sdl->cur_key[SDL_SCANCODE_S])
	{
		if (ft_sp_cll(sdl, sdl->m_t.map[(int)(cam->pos.x - cam->dir.x * t->move_speed - wall_box.x)][(int)(cam->pos.y - wall_box.y)]) == space)
			cam->pos.x -= cam->dir.x * t->move_speed;
		if (ft_sp_cll(sdl, sdl->m_t.map[(int)(cam->pos.x - wall_box.x)][(int)(cam->pos.y - cam->dir.y * t->move_speed - wall_box.y)]) == space)
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
