//
// Created by Igor STALEVSKIY on 9/6/18.
//

#include "includes/wolf3d.h"

void floorCast(t_ray *ray, t_tex *texT, t_cam *camT, t_floor *floorT)
{
	if(ray->side == 0 && camT->rayDir.X > 0)
	{
		floorT->fWall.X = ray->map.X;
		floorT->fWall.Y = ray->map.Y + texT->wallX;
	}
	else if(ray->side == 0 && camT->rayDir.X < 0)
	{
		floorT->fWall.X = ray->map.X + 1.0;
		floorT->fWall.Y = ray->map.Y + texT->wallX;
	}
	else if(ray->side == 1 && camT->rayDir.Y > 0)
	{
		floorT->fWall.X = ray->map.X + texT->wallX;
		floorT->fWall.Y = ray->map.Y;
	}
	else
	{
		floorT->fWall.X = ray->map.X + texT->wallX;
		floorT->fWall.Y = ray->map.Y + 1.0;
	}
}

static void floorDrawing(t_SDL *sdlT, t_floor *floor, t_ray *ray, int32_t y)
{
	sdlT->texT.pixel = (uint32_t*)sdlT->textures[0]->pixels;
	sdlT->color = (uint32_t)sdlT->texT.pixel[(sdlT->texT.texHeight * floor->fTex.Y + floor->fTex.X)];
	sdlT->color = deepColorWall(sdlT->color, y, ray, &sdlT->mapT);
	sdlT->texT.pixel2[sdlT->mapT.PixelSizeW * y + sdlT->x] = sdlT->color;
	sdlT->texT.pixel2[(sdlT->mapT.PixelSizeH - y) * sdlT->mapT.PixelSizeW + sdlT->x] = sdlT->color;
}

void floorAdd(t_floor *floor, t_ray *ray, t_SDL *sdlT, t_cam *camT)
{
	int32_t y;
	floor->distWall = ray->perpWallDist;
	if (ray->wall.drawEnd < 0) ray->wall.drawEnd = sdlT->mapT.PixelSizeH;

	y = ray->wall.drawEnd + 1;
	while (y < sdlT->mapT.PixelSizeH)
	{
		floor->currentDist = sdlT->mapT.PixelSizeH / (2.0 * y - sdlT->mapT.PixelSizeH);
		floor->weight = floor->currentDist / floor->distWall;
		floor->fCur.X = floor->weight * floor->fWall.X + (1.0 - floor->weight) * camT->pos.X;
		floor->fCur.Y = floor->weight * floor->fWall.Y + (1.0 - floor->weight) * camT->pos.Y;
		floor->fTex.X = (int)(floor->fCur.X * sdlT->texT.texWidth) % sdlT->texT.texWidth;
		floor->fTex.Y = (int)(floor->fCur.Y * sdlT->texT.texHeight) % sdlT->texT.texHeight;
		floorDrawing(sdlT, floor, ray, y);
		y++;
	}
}