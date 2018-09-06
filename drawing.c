//
// Created by Igor STALEVSKIY on 8/18/18.
//

#include "includes/wolf3d.h"

void	Wall(t_cam *cam, t_ray *ray, int16_t pixelHeight)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->map.X - cam->pos.X + (1 - ray->step.X) / 2) / cam->rayDir.X;
	else
		ray->perpWallDist = (ray->map.Y - cam->pos.Y + (1 - ray->step.Y) / 2) / cam->rayDir.Y;

	ray->wall.lineHeight = (int32_t)(pixelHeight / ray->perpWallDist);
	ray->wall.drawStart = -ray->wall.lineHeight / 2 + pixelHeight / 2;
	if (ray->wall.drawStart < 0)
		ray->wall.drawStart = 0;

	ray->wall.drawEnd = ray->wall.lineHeight / 2 + pixelHeight / 2;
	if (ray->wall.drawEnd >= pixelHeight)
		ray->wall.drawEnd = pixelHeight - 1;
}

void	drawWall(SDL_Renderer *render, uint16_t x, t_ray *ray)
{
	int color;

	color = GREEN;
	if (ray->texture == (int16_t)1)
		color = RED;
	else if (ray->texture == (int16_t)2)
		color = GREEN;
	else if (ray->texture == (int16_t)3)
		color = BLUE;
	else if (ray->texture == (int16_t)4)
		color = WHITE;
	if (ray->side == 1)
		color /= 2;
	ray->wall.color.red = (uint8_t)((color >> 16) & 0xFF);
	ray->wall.color.green = (uint8_t)((color >> 8) & 0xFF);
	ray->wall.color.blue = (uint8_t)((color) & 0xFF);
	SDL_SetRenderDrawColor(render, ray->wall.color.red, ray->wall.color.green, ray->wall.color.blue, 0xFF);
	SDL_RenderDrawLine(render, x, ray->wall.drawStart, x, ray->wall.drawEnd);
}

uint32_t	deepColor(Uint32 clearColor, t_ray *ray)
{
	Uint32	deepColor;
	int		cof;

	cof = 3;
	ray->wall.color.red = (uint8_t)((clearColor >> 16) & 0xFF);
	ray->wall.color.green = (uint8_t)((clearColor >> 8) & 0xFF);
	ray->wall.color.blue = (uint8_t)((clearColor) & 0xFF);
	if (ray->perpWallDist > cof)
	{
		ray->wall.color.red = (uint8_t)(((clearColor & 0xFF0000) >> 16) / (1 + (ray->perpWallDist - cof) / 2));
		ray->wall.color.green = (uint8_t)(((clearColor & 0xFF00) >> 8) / (1 + (ray->perpWallDist - cof) / 2));
		ray->wall.color.blue = (uint8_t)((clearColor & 0xFF) / (1 + (ray->perpWallDist - cof) / 2));
	}
	deepColor = (ray->wall.color.red << 16) | (ray->wall.color.green << 8) | ray->wall.color.blue;
	return (deepColor);
}

uint32_t	deepColorWall(Uint32 clearColor, int y, t_ray *ray, t_map *mapT)
{
	double centre;
	double end;
	double cof;
	Uint32	deepColor;

	ray->wall.color.red = (uint8_t)((clearColor >> 16) & 0xFF);
	ray->wall.color.green = (uint8_t)((clearColor >> 8) & 0xFF);
	ray->wall.color.blue = (uint8_t)((clearColor) & 0xFF);
	centre = mapT->PixelSizeH / 2;
	end = mapT->PixelSizeH - (centre * 0.5);
	cof = ((double)y - centre) / end;
	if (y > mapT->PixelSizeH / 2)
	{
		ray->wall.color.red = (uint8_t)(((clearColor & 0xFF0000) >> 16) * (cof));
		ray->wall.color.green = (uint8_t)(((clearColor & 0xFF00) >> 8) * (cof));
		ray->wall.color.blue = (uint8_t)((clearColor & 0xFF) * (cof));
	}
	deepColor = (ray->wall.color.red << 16) | (ray->wall.color.green << 8) | ray->wall.color.blue;
	return (deepColor);
}
void drawTextureWall(t_SDL *sdlT, t_cam *cam, t_ray *ray, uint16_t x)
{
	if (ray->side == 0)
		sdlT->texT.wallX = cam->pos.Y + ray->perpWallDist * cam->rayDir.Y;
	else
		sdlT->texT.wallX = cam->pos.X + ray->perpWallDist * cam->rayDir.X;
	sdlT->texT.wallX -= floor((sdlT->texT.wallX));

	sdlT->texT.texX = (int)(sdlT->texT.wallX * (double)sdlT->texT.texWidth);
	if(ray->side == 0 && cam->rayDir.X > 0)
		sdlT->texT.texX = sdlT->texT.texWidth - sdlT->texT.texX - 1;
	if(ray->side == 1 && cam->rayDir.Y < 0)
		sdlT->texT.texX = sdlT->texT.texWidth - sdlT->texT.texX - 1;

	for(int y = ray->wall.drawStart; y < ray->wall.drawEnd; y++)
	{
		sdlT->texT.d = y * 256 - sdlT->mapT.PixelSizeH * 128 + ray->wall.lineHeight * 128;
		sdlT->texT.texY = ((sdlT->texT.d * sdlT->texT.texWidth) / ray->wall.lineHeight) / 256;
		sdlT->texT.pixel = (uint32_t*)sdlT->textures[ray->texture]->pixels;
		Uint32 color = (uint32_t)sdlT->texT.pixel[(sdlT->texT.texHeight * sdlT->texT.texY + sdlT->texT.texX)];
		color = deepColor(color, ray);
		if(ray->side == 1)
			color = (color >> 1) & 8355711;
		sdlT->texT.pixel2[sdlT->mapT.PixelSizeW * y + x] = color;
	}
}