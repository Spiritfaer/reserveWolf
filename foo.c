/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:41:17 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 10:41:18 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	print_arg(t_arg ar)
{
	printf("m_t - %s\nWidth - %d\nHeight - %d\n",
			ar.map_name, ar.screen_w, ar.screen_h);
	if (ar.flag & MAPN)
		printf("Map + ");
	else
		printf("Map - ");
	if (ar.flag & MAPW)
		printf("Width + ");
	else
		printf("Width - ");
	if (ar.flag & MAPH)
		printf("Height +\n");
	else
		printf("Height -\n");
}

void	ft_print_map(t_map *map_t)
{
	t_v2i	i;

	i.x = 0;
	i.y = 0;
	while (i.y < map_t->map_h)
	{
		i.x = 0;
		while (i.x < map_t->map_w)
		{
			printf("%d ", map_t->map[i.y][i.x]);
			i.x++;
		}
		printf("\n");
		i.y++;
	}
}
