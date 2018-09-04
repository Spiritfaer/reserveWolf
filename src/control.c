#include "../includes/including.h"


//void		ft_event(t_base *base)
//{
//	const Uint8 *current;
//	Uint16 maxW;
//	Uint16 maxH;
//
//	current = SDL_GetKeyboardState(NULL);
//	SDL_PollEvent(&base->event);
//	maxW = (base->aruments.flag & MAPW) ? base->aruments.screenW : (Uint16)DEF_SCREEN_WIDTH;
//	maxH = (base->aruments.flag & MAPH) ? base->aruments.screenH : (Uint16)DEF_SCREEN_HEIGHT;
//	if (base->event.type == SDL_QUIT || current[SDL_SCANCODE_ESCAPE])
//		base->loop = 0;
//	if (current[SDL_SCANCODE_UP] && base->Win_Point.y >= 1)
//		base->Win_Point.y -= 1;
//	if (current[SDL_SCANCODE_DOWN] && base->Win_Point.y < (maxH - 11))
//		base->Win_Point.y += 1;
//	if (current[SDL_SCANCODE_LEFT] && base->Win_Point.x >= 1)
//		base->Win_Point.x -= 1;
//	if (current[SDL_SCANCODE_RIGHT] && base->Win_Point.x < (maxW - 11))
//		base->Win_Point.x += 1;
//}

void	ft_move(t_SDL *sdlT, t_allV *all, t_time *t, t_map *mapT)
{
	int16_t point;

	point = (int16_t)(all->m.X + all->m.Y * mapT->mapW);
	if (sdlT->currentKey[SDL_SCANCODE_UP] || sdlT->currentKey[SDL_SCANCODE_W])
	{
		if (mapT->map[
					(int)(all->pos.X + all->dir.X * t->moveSpeed)
			+
					(int)(all->pos.Y * mapT->mapW)
			] == false)
			all->pos.X += all->dir.X * t->moveSpeed;
//		if (worldMap[(int)(all->pos.X)][(int)(all->pos.Y + all->dir.Y * t->moveSpeed)] == false)
//			all->pos.Y += all->dir.Y * t->moveSpeed;
	}
	if (sdlT->currentKey[SDL_SCANCODE_DOWN] || sdlT->currentKey[SDL_SCANCODE_S])
	{
//		if(worldMap[(int)(all->pos.X - all->dir.X * t->moveSpeed)][(int)(all->pos.Y)] == false)
//			all->pos.X -= all->dir.X * t->moveSpeed;
//		if(worldMap[(int)(all->pos.X)][(int)(all->pos.Y - all->dir.Y * t->moveSpeed)] == false)
//			all->pos.Y -= all->dir.Y * t->moveSpeed;
	}
}

void	ft_rotate(t_SDL *sdlT, t_allV *all, t_time *t)
{
	int16_t point;
	double oldDirX;
	double oldPlaneX;

	point = (int16_t)(all->m.X + all->m.Y * sdlT->mapT.mapW);
	if (sdlT->currentKey[SDL_SCANCODE_RIGHT])
	{
		oldDirX = all->dir.X;
		all->dir.X = all->dir.X * cos(-t->rotSpeed) - all->dir.Y * sin(-t->rotSpeed);
		all->dir.Y = oldDirX * sin(-t->rotSpeed) + all->dir.Y * cos(-t->rotSpeed);

		oldPlaneX = all->plane.X;
		all->plane.X = all->plane.X * cos(-t->rotSpeed) - all->plane.Y * sin(-t->rotSpeed);
		all->plane.Y = oldPlaneX * sin(-t->rotSpeed) + all->plane.Y * cos(-t->rotSpeed);
	}
	if (sdlT->currentKey[SDL_SCANCODE_LEFT])
	{
		oldDirX = all->dir.X;
		all->dir.X = all->dir.X * cos(t->rotSpeed) - all->dir.Y * sin(t->rotSpeed);
		all->dir.Y = oldDirX * sin(t->rotSpeed) + all->dir.Y * cos(t->rotSpeed);

		oldPlaneX = all->plane.X;
		all->plane.X = all->plane.X * cos(t->rotSpeed) - all->plane.Y * sin(t->rotSpeed);
		all->plane.Y = oldPlaneX * sin(t->rotSpeed) + all->plane.Y * cos(t->rotSpeed);
	}
}