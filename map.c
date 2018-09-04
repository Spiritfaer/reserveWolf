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
			return (ft_errors("error incorect mapW!\n"));
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
	if (!tmp || !(mapT->map = (int16_t**)malloc(sizeof(int16_t*) * (mapT->mapH + 1))))
		return ;
	point.Y = 0;
	while (point.Y < mapT->mapH)
	{
		point.X = 0;
		str = ft_strsplit(tmp->content, ' ');
		mapT->map[point.Y] = (int16_t*)malloc(sizeof(int16_t) * mapT->mapW);
		while (point.X < mapT->mapW)
		{
			mapT->map[point.Y][point.X] = (int16_t)ft_atoi(str[point.X]);
			point.X++;
		}
		tmp = ft_smooth(&tmp);
		ft_split_del(str);
		point.Y++;
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

	i.Y = 0;
	while (i.Y < mapT->mapH)
	{
		i.X = 0;
		while (i.X < mapT->mapW)
		{
			if (i.Y == 0)
				while (i.X < mapT->mapW - 1)
					mapT->map[i.Y][i.X++] = 1;
			if (i.Y == (mapT->mapH - 1))
				while (i.X < mapT->mapW - 1)
					mapT->map[i.Y][i.X++] = 1;
			if (!checkTexture(mapT->map[i.Y][i.X]))
				mapT->map[i.Y][i.X] = 0;
			if (i.X == 0 || i.X == mapT->mapW - 1)
				mapT->map[i.Y][i.X] = 1;
			i.X++;
		}
		i.Y++;
	}
}
