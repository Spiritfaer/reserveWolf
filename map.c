/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:35:24 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 11:35:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int8_t		ft_check_w_map(t_list *head, int16_t map_w)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (map_w != (int16_t)ft_splitter(tmp->content, ' '))
			return (ft_errors("error incorect map_w!\n"));
		tmp = tmp->next;
	}
	return (1);
}

void		ft_remap(t_map *map_t)
{
	char	**str;
	t_v2i	point;
	t_list	*tmp;

	tmp = map_t->head;
	if (!tmp || !(map_t->map = (int16_t**)malloc(sizeof(int16_t*)
												* (map_t->map_h + 1))))
		return ;
	point.y = 0;
	while (point.y < map_t->map_h)
	{
		point.x = 0;
		str = ft_strsplit(tmp->content, ' ');
		map_t->map[point.y] = (int16_t*)malloc(sizeof(int16_t) * map_t->map_w);
		while (point.x < map_t->map_w)
		{
			map_t->map[point.y][point.x] = (int16_t)ft_atoi(str[point.x]);
			point.x++;
		}
		tmp = ft_smooth(&tmp);
		ft_split_del(str);
		point.y++;
	}
}

int8_t		ft_check_texture(int16_t map)
{
	if (map == TEXTURE_0)
		return (1);
	if (map == TEXTURE_1)
		return (1);
	if (map == TEXTURE_2)
		return (1);
	if (map == TEXTURE_3)
		return (1);
	if (map == TEXTURE_4)
		return (1);
	return (0);
}

void		ft_fix_map(t_map *map_t)
{
	t_v2i		i;

	i.y = 0;
	while (i.y < map_t->map_h)
	{
		i.x = 0;
		while (i.x < map_t->map_w)
		{
			if (i.y == 0)
				while (i.x < map_t->map_w - 1)
					map_t->map[i.y][i.x++] = 1;
			if (i.y == (map_t->map_h - 1))
				while (i.x < map_t->map_w - 1)
					map_t->map[i.y][i.x++] = 1;
			if (!ft_check_texture(map_t->map[i.y][i.x]))
				map_t->map[i.y][i.x] = 0;
			if (i.x == 0 || i.x == map_t->map_w - 1)
				map_t->map[i.y][i.x] = 1;
			i.x++;
		}
		i.y++;
	}
}

int8_t		ft_make_map(t_sdl *sdl_t)
{
	int16_t	fd;

	if (!(sdl_t->argv_t.flag & MAPN))
		return (ft_errors("error m_t flag"));
	else
	{
		fd = (int16_t)open(sdl_t->argv_t.map_name, O_RDONLY);
		if (fd < 1)
			return (ft_errors("error fd"));
		else
			sdl_t->m_t.head = ft_pars_file(fd);
	}
	ft_revers_list(&sdl_t->m_t.head);
	if (!ft_mapping(&sdl_t->m_t))
		return (0);
	close(fd);
	return (1);
}
