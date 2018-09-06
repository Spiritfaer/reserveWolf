//
// Created by Igor STALEVSKIY on 8/7/18.
//

#ifndef WOLF3D_H
#define WOLF3D_H

//#define DEBUG

#define RED 0x0000FF
#define GREEN 0x00FF00
#define BLUE 0xFF0000
#define WHITE 0xFFFFFF
#define YELLOW 0xFFFF00
#define BLACK 0x000000

#include "libft.h"

#include <stdbool.h>
#include <stdio.h>

#include <math.h>
#include <fcntl.h>
#include <stdlib.h>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "wolf3d.h"

typedef struct		s_rgb
{
	uint8_t			red;
	uint8_t			green;
	uint8_t 		blue;
}					t_rgb;

typedef struct		s_wall
{
	int32_t			drawStart;
	int32_t			drawEnd;
	t_rgb			color;
	int32_t			lineHeight;
}					t_wall;

typedef struct		s_v2d
{
	double			X;
	double			Y;
}					t_v2d;

typedef struct		s_v2i
{
	int32_t			X;
	int32_t			Y;
}					t_v2i;

typedef struct		s_arg {
	const char		*mapName;
	Uint16 			screenW;
	Uint16			screenH;
	Uint8			flag;
}					t_arg;

typedef struct		s_map {
	t_list			*head;
	int16_t			**map;
	int16_t			mapW;
	int16_t 		mapH;
	int16_t			PixelSizeW;
	int16_t			PixelSizeH;
	uint16_t 		sizeMap;
}					t_map;

typedef struct		s_time
{
	double 			time;
	double 			oldTime;
	double 			frameTime;
	double			moveSpeed;
	double 			rotSpeed;
}					t_time;

typedef struct		s_cam
{
	double 			camX;
	t_v2d			rayDir;
	t_v2d			pos;
	t_v2d			dir;
	t_v2d			plane;
}					t_cam;

typedef struct		s_ray
{
	t_v2i			map;
	t_v2i			step;
	t_v2d			sideDist;
	t_v2d			deltaDist;
	int8_t			hit;
	int8_t			side;
	int16_t			texture;
	double			perpWallDist;
	t_wall			wall;
}					t_ray;

typedef struct		s_floor
{
	t_v2d			fWall;
	t_v2d			fCur;
	t_v2i			fTex;
	double 			distWall;
	double			currentDist;
	double			weight;

	int16_t			floorTexX;
	int16_t 		floorTexY;
}					t_floor;

typedef struct		s_tex
{
	double 			wallX;
	int32_t			d;
	int32_t			texX;
	int32_t			texY;
	int16_t			texWidth;
	int16_t			texHeight;
	uint32_t		*pixel;
	uint32_t		*pixel2;
}					t_tex;

typedef struct		s_SDL
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	const uint8_t	*currentKey;
	SDL_Surface		**textures;
	t_tex			texT;
	int8_t			loop;
	t_arg			argvT;
	t_map			mapT;
	Uint16 			numTrack;
	Mix_Music		*music[2];
	Mix_Chunk		*move;
	int16_t			volume;
	SDL_Surface		*buffer;
	SDL_Texture		*preRender;
	uint16_t		x;
	uint32_t		color;
	int32_t			flag;
	SDL_Surface		*menuBG;
	TTF_Font		*gFont;
}					t_SDL;

#define DEF_SCREEN_WIDTH 1440
#define DEF_SCREEN_HEIGHT 840
#define AR const char**

#define MAPN 0x000001
#define MAPW 0x000002
#define MAPH 0x000004
#define MENU 0x000001
#define GAME 0x000002

void				readArgv(int argc, AR argv, t_arg *arg);
int8_t			 	ft_initSDL(t_SDL *sdlT);
int8_t				ft_make_map(t_SDL *sdlT);
int8_t 				ft_errors(const char *error);
void				ft_revers_list(t_list **head);
void				print_map(t_map *mapT);
uint_fast32_t		ft_count_list(t_list *head);
int8_t				checkWidthMap(t_list *head, int16_t mapW);
void				ft_list_del(t_list **head);
void				ft_remap(t_map *mapT);
void				fixMap(t_map *mapT);
void 				ft_split_del(char **head);
//---------------------------------------------------------------------------------------------

void 				ft_process(t_SDL *sdlT);
void				Ray(t_cam *cam, t_ray *ray);
void				Cast(t_ray *ray, t_map *mapT);
void				Wall(t_cam *cam, t_ray *ray, int16_t pixelHeight);
void				setCam(t_cam *cam);
void				drawWall(SDL_Renderer *render, uint16_t x, t_ray *ray);
void				setTime(t_time *t);
void				event(t_SDL *sdlT, t_cam *cam, t_time *time);

void				ft_end(t_SDL *sdlT);
void				ft_print_list(t_list *head);
void				drawTextureWall(t_SDL *sdlT, t_cam *cam, t_ray *ray, uint16_t x);
void				InitRay(t_SDL *sdlT, t_cam *cam, t_ray *ray, uint16_t x);
uint32_t			deepColor(Uint32 clearColor, t_ray *ray);
uint32_t			deepColorWall(Uint32 clearColor, int y, t_ray *ray, t_map *mapT);
void 				floorCast(t_ray *ray, t_tex *texT, t_cam *camT, t_floor *floorT);
void				floorAdd(t_floor *floor, t_ray *ray, t_SDL *sdlT, t_cam *camT);





#endif
