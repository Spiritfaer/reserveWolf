#include "includes/wolf3d.h"

void print_arg(t_arg ar)
{
	printf("m_t - %s\nWidth - %d\nHeight - %d\n", ar.map_name, ar.screen_w, ar.screen_h);
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

	while (i.y < mapT->map_h)
	{
		i.x = 0;
		while (i.x < mapT->map_w)
		{
			printf("%d ", mapT->map[i.y][i.x]);
			i.x++;
		}
		printf("\n");
		i.y++;
	}
}
