#include "includes/wolf3d.h"


#define TEXTURE_0 0
#define TEXTURE_1 1
#define TEXTURE_2 2
#define TEXTURE_3 3
#define TEXTURE_4 4

t_list		*ft_smooth(t_list **head)
{
	t_list *next;

	next = (*head)->next;
	if ((*head)->content)
		free((*head)->content);
	(*head)->content_size = 0;
	free(*head);
	return (next);
}

int8_t		checkWidthMap(t_list *head, int16_t mapW)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (mapW != (int16_t)ft_splitter(tmp->content, ' '))
			return (ft_errors("error incorect map_w!\n"));
		tmp = tmp->next;
	}
	return (1);
}

void		ft_remap(t_map *mapT)
{
	char 	**str;
	t_v2i	point;
	t_list	*tmp;

	tmp = mapT->head;
	if (!tmp || !(mapT->map = (int16_t**)malloc(sizeof(int16_t*) * (mapT->map_h + 1))))
		return ;
	point.y = 0;
	while (point.y < mapT->map_h)
	{
		point.x = 0;
		str = ft_strsplit(tmp->content, ' ');
		mapT->map[point.y] = (int16_t*)malloc(sizeof(int16_t) * mapT->map_w);
		while (point.x < mapT->map_w)
		{
			mapT->map[point.y][point.x] = (int16_t)ft_atoi(str[point.x]);
			point.x++;
		}
		tmp = ft_smooth(&tmp);
		ft_split_del(str);
		point.y++;
	}
}

int8_t		checkTexture(int16_t map)
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

void		fixMap(t_map *mapT)
{
	t_v2i		i;

	i.y = 0;
	while (i.y < mapT->map_h)
	{
		i.x = 0;
		while (i.x < mapT->map_w)
		{
			if (i.y == 0)
				while (i.x < mapT->map_w - 1)
					mapT->map[i.y][i.x++] = 1;
			if (i.y == (mapT->map_h - 1))
				while (i.x < mapT->map_w - 1)
					mapT->map[i.y][i.x++] = 1;
			if (!checkTexture(mapT->map[i.y][i.x]))
				mapT->map[i.y][i.x] = 0;
			if (i.x == 0 || i.x == mapT->map_w - 1)
				mapT->map[i.y][i.x] = 1;
			i.x++;
		}
		i.y++;
	}
}
