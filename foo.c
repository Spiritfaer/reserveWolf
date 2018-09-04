#include "includes/wolf3d.h"


int8_t ft_errors(const char *error)
{
	ft_putstr_fd(error, 2);
	return (-1);
}

void print_arg(t_arg ar)
{
	printf("mapT - %s\nWidth - %d\nHeight - %d\n", ar.mapName, ar.screenW, ar.screenH);
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

void	print_map(t_map *mapT)
{
	t_v2i	i = {0, 0};

	while (i.Y < mapT->mapH)
	{
		i.X = 0;
		while (i.X < mapT->mapW)
		{
			printf("%d ", mapT->map[i.Y][i.X]);
			i.X++;
		}
		printf("\n");
		i.Y++;
	}
}
