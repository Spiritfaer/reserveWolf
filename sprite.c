//
// Created by Igor STALEVSKIY on 9/9/18.
//

#include "includes/wolf3d.h"

uint32_t	deep_color_spite(uint32_t in_c, double dist)
{
	double	dalnost;
	double	vidimost;
	double	cof;
	Uint32	out_c;
	t_rgb	clr;
	clr.r = (uint8_t)((in_c >> 16) & 0xFF);
	clr.g = (uint8_t)((in_c >> 8) & 0xFF);
	clr.b = (uint8_t)((in_c) & 0xFF);
	dalnost = 2;
	if (dist > 20)
		dist = 20;

	vidimost = 25;
	cof = fabs((dist - dalnost) / vidimost);
	if (dist < vidimost)
	{
		clr.r = (uint8_t)(((in_c & 0xFF0000) >> 16) * (1 - cof));
		clr.g = (uint8_t)(((in_c & 0xFF00) >> 8) * (1 - cof));
		clr.b = (uint8_t)((in_c & 0xFF) * (1 - cof));
	}
	out_c = (clr.r << 16) | (clr.g << 8) | clr.b;
	return (out_c);
}

void	ft_spline(t_sdl *sdl, t_cam *cam)
{
	t_sp s_calc;

	s_calc.i = 0;
	while (s_calc.i < sdl->m_t.sprit_num)
	{
		sdl->sprite[s_calc.i].dist = ((cam->pos.x - sdl->sprite[s_calc.i].p.x)
									* (cam->pos.x - sdl->sprite[s_calc.i].p.x)
									+ (cam->pos.y - sdl->sprite[s_calc.i].p.y)
									* (cam->pos.y - sdl->sprite[s_calc.i].p.y));
		s_calc.i++;
	}
	if (sdl->m_t.sprit_num > 1)
		ft_sort((void**)sdl->sprite, sdl->m_t.sprit_num);
	s_calc.i = 0;
	while (s_calc.i < sdl->m_t.sprit_num)
	{
		sdl->tex_t.pixel3 = sdl->textures[sdl->sprite[s_calc.i].texture]->pixels;
		s_calc.sprite.x = sdl->sprite[s_calc.i].p.x - cam->pos.x;
		s_calc.sprite.y = sdl->sprite[s_calc.i].p.y - cam->pos.y;
		s_calc.invDet = 1.0 / (cam->pl.x * cam->dir.y - cam->dir.x * cam->pl.y);
		s_calc.transform.x = s_calc.invDet * (cam->dir.y * s_calc.sprite.x - cam->dir.x * s_calc.sprite.y);
		s_calc.transform.y = s_calc.invDet * (-cam->pl.y * s_calc.sprite.x + cam->pl.x * s_calc.sprite.y);
		s_calc.spriteScreenX = (int)((sdl->m_t.pxl_s_w / 2) * (1 + s_calc.transform.x / s_calc.transform.y));
		s_calc.spriteHeight = abs((int)(sdl->m_t.pxl_s_h / s_calc.transform.y));
		s_calc.drawstart.y = (int)(-s_calc.spriteHeight / 2.0 + sdl->m_t.pxl_s_h / 2.0);
		if (s_calc.drawstart.y < 0)
			s_calc.drawstart.y = 0;
		s_calc.drawend.y = (int)(s_calc.spriteHeight / 2.0 + sdl->m_t.pxl_s_h / 2.0);
		if (s_calc.drawend.y >= sdl->m_t.pxl_s_h)
			s_calc.drawend.y = sdl->m_t.pxl_s_h - 1;
		s_calc.spriteWidth = abs((int)(sdl->m_t.pxl_s_h / s_calc.transform.y));
		s_calc.drawstart.x = (int)(-s_calc.spriteWidth / 2.0 + s_calc.spriteScreenX);
		if (s_calc.drawstart.x < 0)
			s_calc.drawstart.x = 0;
		s_calc.drawend.x = (int)(s_calc.spriteWidth / 2.0 + s_calc.spriteScreenX);
		if (s_calc.drawend.x >= sdl->m_t.pxl_s_w)
			s_calc.drawend.x = sdl->m_t.pxl_s_w - 1;
		while (s_calc.drawstart.x <= s_calc.drawend.x)
		{
			s_calc.tex.x = (int)(256 * (s_calc.drawstart.x - (-s_calc.spriteWidth / 2.0 + s_calc.spriteScreenX)) * sdl->tex_t.twh.x / s_calc.spriteWidth) / 256;
			if (s_calc.transform.y > 0 && s_calc.drawstart.x < sdl->m_t.pxl_s_w && s_calc.transform.y < sdl->z_buff[s_calc.drawstart.x])
			{
				s_calc.y = s_calc.drawstart.y;
				while (s_calc.y < s_calc.drawend.y)
				{
					s_calc.d = (int)(s_calc.y - sdl->m_t.pxl_s_h / 2.0 + s_calc.spriteHeight / 2.0);
					s_calc.tex.y = (s_calc.d * sdl->tex_t.twh.y) / s_calc.spriteHeight;
					s_calc.color = (uint32_t)sdl->tex_t.pixel3[(sdl->tex_t.twh.y * s_calc.tex.y + s_calc.tex.x)];
					if ((s_calc.color & 0x00FFFFFF) != 0)
						sdl->tex_t.pixel2[sdl->m_t.pxl_s_w * s_calc.y + s_calc.drawstart.x] = deep_color_spite(s_calc.color, sdl->sprite[s_calc.i].dist);
					s_calc.y++;
				}
			}
			s_calc.drawstart.x++;
		}
		s_calc.i++;
	}
}