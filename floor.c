//
// Created by Igor STALEVSKIY on 9/6/18.
//

#include "includes/wolf3d.h"

void floorCast(t_ray *ray, t_tex *texT, t_cam *camT, t_floor *floorT)
{
	if(ray->side == 0 && camT->r_dir.x > 0)
	{
		floorT->f_wall.x = ray->map.x;
		floorT->f_wall.y = ray->map.y + texT->wall_x;
	}
	else if(ray->side == 0 && camT->r_dir.x < 0)
	{
		floorT->f_wall.x = ray->map.x + 1.0;
		floorT->f_wall.y = ray->map.y + texT->wall_x;
	}
	else if(ray->side == 1 && camT->r_dir.y > 0)
	{
		floorT->f_wall.x = ray->map.x + texT->wall_x;
		floorT->f_wall.y = ray->map.y;
	}
	else
	{
		floorT->f_wall.x = ray->map.x + texT->wall_x;
		floorT->f_wall.y = ray->map.y + 1.0;
	}
}

static void floorDrawing(t_sdl *sdlT, t_floor *floor, t_ray *ray, int32_t y)
{
	sdlT->tex_t.pixel = (uint32_t*)sdlT->textures[0]->pixels;
	sdlT->color = (uint32_t)sdlT->tex_t.pixel[(sdlT->tex_t.tex_h * floor->f_tex.y + floor->f_tex.x)];
	sdlT->color = ft_d_c_wall(sdlT->color, y, ray, &sdlT->m_t);
	sdlT->tex_t.pixel2[sdlT->m_t.pxl_s_W * y + sdlT->x] = sdlT->color;
	sdlT->tex_t.pixel2[(sdlT->m_t.pxl_s_h - y) * sdlT->m_t.pxl_s_W + sdlT->x] = sdlT->color;
}

void floorAdd(t_floor *floor, t_ray *ray, t_sdl *sdlT, t_cam *camT)
{
	int32_t y;
	floor->d_wall = ray->pwd;
	if (ray->wall.draw_end < 0) ray->wall.draw_end = sdlT->m_t.pxl_s_h;

	y = ray->wall.draw_end + 1;
	while (y < sdlT->m_t.pxl_s_h)
	{
		floor->cur_dist = sdlT->m_t.pxl_s_h / (2.0 * y - sdlT->m_t.pxl_s_h);
		floor->weight = floor->cur_dist / floor->d_wall;
		floor->f_cur.x = floor->weight * floor->f_wall.x + (1.0 - floor->weight) * camT->pos.x;
		floor->f_cur.y = floor->weight * floor->f_wall.y + (1.0 - floor->weight) * camT->pos.y;
		floor->f_tex.x = (int)(floor->f_cur.x * sdlT->tex_t.tex_w) % sdlT->tex_t.tex_w;
		floor->f_tex.y = (int)(floor->f_cur.y * sdlT->tex_t.tex_h) % sdlT->tex_t.tex_h;
		floorDrawing(sdlT, floor, ray, y);
		y++;
	}
}