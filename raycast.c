//
// Created by Igor STALEVSKIY on 8/18/18.
//

#include "includes/wolf3d.h"

void	InitRay(t_SDL *sdlT, t_cam *cam, t_ray *ray, uint16_t x)
{
	cam->camX = 2 * x / (double)sdlT->mapT.PixelSizeW - 1;
	cam->rayDir.X = cam->dir.X + cam->plane.X * cam->camX;
	cam->rayDir.Y = cam->dir.Y + cam->plane.Y * cam->camX;
	ray->map.X = (int32_t)cam->pos.X;
	ray->map.Y = (int32_t)cam->pos.Y;
	ray->hit = 0;
	ray->side = 0;
	ray->deltaDist.X = fabs(1 / cam->rayDir.X);
	ray->deltaDist.Y = fabs(1 / cam->rayDir.Y);
}

void	Ray(t_cam *cam, t_ray *ray)
{
	if (cam->rayDir.X < 0)
	{
		ray->step.X = -1;
		ray->sideDist.X = (cam->pos.X - ray->map.X) * ray->deltaDist.X;
	}
	else
	{
		ray->step.X = 1;
		ray->sideDist.X = (ray->map.X + 1.0 - cam->pos.X) * ray->deltaDist.X;
	}
	if (cam->rayDir.Y < 0)
	{
		ray->step.Y = -1;
		ray->sideDist.Y = (cam->pos.Y - ray->map.Y) * ray->deltaDist.Y;
	}
	else
	{
		ray->step.Y = 1;
		ray->sideDist.Y = (ray->map.Y + 1.0 - cam->pos.Y) * ray->deltaDist.Y;
	}
}

void	Cast(t_ray *ray, t_map *mapT)
{
	while (ray->hit == 0)
	{
		if (ray->sideDist.X < ray->sideDist.Y)
		{
			ray->sideDist.X += ray->deltaDist.X;
			ray->map.X += ray->step.X;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.Y += ray->deltaDist.Y;
			ray->map.Y += ray->step.Y;
			ray->side = 1;
		}
		if (mapT->map[ray->map.X][ray->map.Y] > 0)
			ray->hit = 1;
	}
	ray->texture = mapT->map[ray->map.X][ray->map.Y];
}
