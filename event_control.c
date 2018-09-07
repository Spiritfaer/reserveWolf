//
// Created by Igor STALEVSKIY on 9/7/18.
//

#include "includes/wolf3d.h"

void	ft_move(t_sdl *sdl_t, t_cam *cam, t_time *t)
{
	if (sdl_t->cur_key[SDL_SCANCODE_UP] || sdl_t->cur_key[SDL_SCANCODE_W])
	{
		if (sdl_t->m_t.map[(int)(cam->pos.x + cam->dir.x * t->move_speed)][(int)cam->pos.y] == false)
			cam->pos.x += cam->dir.x * t->move_speed;
		if (sdl_t->m_t.map[(int)cam->pos.x][(int)(cam->pos.y + cam->dir.y * t->move_speed)] == false)
			cam->pos.y += cam->dir.y * t->move_speed;
	}
	if (sdl_t->cur_key[SDL_SCANCODE_DOWN] || sdl_t->cur_key[SDL_SCANCODE_S])
	{
		if (sdl_t->m_t.map[(int)(cam->pos.x - cam->dir.x * t->move_speed)][(int)cam->pos.y] == false)
			cam->pos.x -= cam->dir.x * t->move_speed;
		if (sdl_t->m_t.map[(int)cam->pos.x][(int)(cam->pos.y - cam->dir.y * t->move_speed)] == false)
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
		cam->dir.x = cam->dir.x * cos(-t->rot_speed) - cam->dir.y * sin(-t->rot_speed);
		cam->dir.y = o_d_x * sin(-t->rot_speed) + cam->dir.y * cos(-t->rot_speed);
		o_p_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(-t->rot_speed) - cam->plane.y * sin(-t->rot_speed);
		cam->plane.y = o_p_x * sin(-t->rot_speed) + cam->plane.y * cos(-t->rot_speed);
	}
	if (sdl_t->cur_key[SDL_SCANCODE_LEFT] || sdl_t->cur_key[SDL_SCANCODE_A])
	{
		o_d_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(t->rot_speed) - cam->dir.y * sin(t->rot_speed);
		cam->dir.y = o_d_x * sin(t->rot_speed) + cam->dir.y * cos(t->rot_speed);
		o_p_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(t->rot_speed) - cam->plane.y * sin(t->rot_speed);
		cam->plane.y = o_p_x * sin(t->rot_speed) + cam->plane.y * cos(t->rot_speed);
	}
}