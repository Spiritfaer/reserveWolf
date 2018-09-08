/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:57:56 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 11:57:57 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RED 0x0000FF
# define GREEN 0x00FF00
# define BLUE 0xFF0000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000

# define DEF_SCREEN_WIDTH 1440
# define DEF_SCREEN_HEIGHT 840
# define AR const char**
# define TEXTURS 11

# define MAPN 0x000001
# define MAPW 0x000002
# define MAPH 0x000004

# define MENU 0x000001
# define GAME 0x000002
# define HELP 0x000004

enum textures {greystone, wood, eagle, purplestone, redbrick,
	mossy, bluestone, colorstone, barrel, greenlight, pillar};

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

typedef struct		s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef struct		s_wall
{
	int32_t			draw_start;
	int32_t			draw_end;
	t_rgb			clr;
	int32_t			line_h;
}					t_wall;

typedef struct		s_v2d
{
	double			x;
	double			y;
}					t_v2d;

typedef struct		s_v2i
{
	int32_t			x;
	int32_t			y;
}					t_v2i;

typedef struct		s_arg {
	const char		*map_name;
	Uint16			screen_w;
	Uint16			screen_h;
	Uint8			flag;
}					t_arg;

typedef struct		s_map {
	t_list			*head;
	int16_t			**map;
	int16_t			map_w;
	int16_t			map_h;
	int16_t			pxl_s_w;
	int16_t			pxl_s_h;
}					t_map;

typedef struct		s_time
{
	double			time;
	double			old_time;
	double			frame_time;
	double			move_speed;
	double			rot_s;
}					t_time;

typedef struct		s_cam
{
	double			cam_x;
	t_v2d			r_dir;
	t_v2d			pos;
	t_v2d			dir;
	t_v2d			pl;
}					t_cam;

typedef struct		s_ray
{
	t_v2i			map;
	t_v2i			step;
	t_v2d			side_d;
	t_v2d			delt_d;
	int8_t			hit;
	int8_t			side;
	int16_t			texture;
	double			pwd;
	t_wall			wall;
}					t_ray;

typedef struct		s_floor
{
	t_v2d			f_wall;
	t_v2d			f_cur;
	t_v2i			f_tex;
	double			d_wall;
	double			cur_dist;
	double			weight;
}					t_floor;

typedef struct		s_tex
{
	double			wall_x;
	int32_t			d;
	t_v2i			txy;
	t_v2i			twh;
	uint32_t		*pixel;
	uint32_t		*pixel2;
}					t_tex;

typedef struct		s_text
{
	SDL_Rect		r_q;
	SDL_Texture		*bl;
	SDL_Texture		*red;
}					t_text;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*ren;
	SDL_Event		event;
	const uint8_t	*cur_key;
	SDL_Surface		**textures;
	t_tex			tex_t;
	int8_t			loop;
	t_arg			argv_t;
	t_map			m_t;
	Uint16			num_track;
	Mix_Music		*music[2];
	Mix_Chunk		*move;
	int16_t			volume;
	SDL_Surface		*buffer;
	SDL_Texture		*pre_ren;
	uint16_t		x;
	uint32_t		color;
	int32_t			flag;
	SDL_Surface		*menu_bg;
	TTF_Font		*g_font;
	t_text			wrds[10];
	int16_t			menu_f;
}					t_sdl;

void				ft_read_argv(int argc, AR argv, t_arg *arg);
int8_t				ft_init(t_sdl *sdl_t);
int8_t				ft_make_map(t_sdl *sdl_t);
int8_t				ft_errors(const char *error);
void				ft_revers_list(t_list **head);
void				ft_print_map(t_map *map_t);
uint_fast32_t		ft_count_list(t_list *head);
int8_t				ft_check_w_map(t_list *head, int16_t map_w);
void				ft_list_del(t_list **head);
void				ft_remap(t_map *map_t);
void				ft_fix_map(t_map *map_t);
void				ft_split_del(char **head);
void				ft_process(t_sdl *sdl);
void				ft_ray(t_cam *cam, t_ray *ray);
void				ft_cast(t_ray *ray, t_map *map_t);
void				ft_wall(t_cam *cam, t_ray *ray, int16_t pxl_h);
void				ft_set_cam(t_cam *cam);
void				ft_draw_wall(SDL_Renderer *render, uint16_t x, t_ray *ray);
void				ft_set_time(t_time *t);
void				event(t_sdl *sdl_t, t_cam *cam, t_time *time);
void				ft_end(t_sdl *sdl_t);
void				ft_print_list(t_list *head);
void				ft_draw_tex_w(t_sdl *sdl_t, t_cam *cam,
									t_ray *ray, uint16_t x);
void				ft_init_ray(t_sdl *sdl_t, t_cam *cam,
									t_ray *ray, uint16_t x);
uint32_t			ft_d_color(Uint32 in_c, t_ray *ray);
uint32_t			ft_d_c_wall(Uint32 in_c, int y, t_ray *ray, t_map *m_t);
void				ft_floor_cast(t_ray *ray, t_tex *tex_t,
									t_cam *cam_t, t_floor *floor_t);
void				ft_floor_add(t_floor *floor, t_ray *ray,
									t_sdl *sdl_t, t_cam *cam_t);
void				ft_set_pix_for(SDL_PixelFormat *p_format);
void				ft_set_music(t_sdl *sdl_t);
void				ft_helper(void);
void				ft_make_texture(SDL_Surface **tex, t_tex *tex_t);
void				ft_make_text(t_sdl *sdl_t);
t_list				*ft_pars_file(int16_t fd);
int8_t				ft_mapping(t_map *map_t);
void				ft_move(t_sdl *sdl_t, t_cam *cam, t_time *t);
void				ft_rotate(t_sdl *sdl_t, t_cam *cam, t_time *t);
void				ft_audio_v(t_sdl *sdl_t);
SDL_Color			ft_set_color(uint8_t red, uint8_t green, uint8_t blue);
void				ft_flag_argv(int i, AR argv, t_arg *arg);
t_list				*ft_smooth(t_list **head);

#endif
