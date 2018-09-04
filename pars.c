//
// Created by Igor STALEVSKIY on 8/12/18.
//

#include <get_next_line.h>
#include "includes/wolf3d.h"

void		readArgv(int argc, AR argv, t_arg *arg)
{
	int i = 1;
	arg->flag = 0x000000;
	if (argc == 1 || (argc - 1) % 2 != 0)
	{
		ft_putendl_fd("Wrong arguments!", 2);
	}
	else
	{
		while (i < argc)
		{
			if (argv[i][0] == '-' && ft_strlen(argv[i]) == 2 && i + 2 <= argc)
			{
				if (argv[i][1] == 'm')
				{
					if (arg->flag & MAPN)
						ft_putendl("Warning! You set the mapT a second time");
					arg->mapName = argv[i + 1];
					arg->flag |= MAPN;
				}
				else if (argv[i][1] == 'w')
				{
					arg->screenW = (Uint16)ft_atoi(argv[i + 1]);
					arg->flag |= MAPW;
				}
				else if (argv[i][1] == 'h')
				{
					arg->screenH = (uint16_t)ft_atoi(argv[i + 1]);
					arg->flag |= MAPH;
				}
				else
				{
					ft_putendl("Uncorrected argument");
				}
			}
			i += 2;
		}
	}
}

int8_t		mapping(t_map *mapT)
{
	mapT->mapW = (int16_t)ft_splitter(mapT->head->content, ' ');
	mapT->mapH = (int16_t)ft_count_list(mapT->head);
	mapT->sizeMap = (uint16_t)(mapT->mapW * mapT->mapH);

	if (checkWidthMap(mapT->head, mapT->mapW) != 1)
	{
		ft_list_del(&mapT->head);
		return (0);
	}
	ft_remap(mapT);
	fixMap(mapT);
	return (1);
}

t_list		*ft_pars_file(int16_t fd)
{
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	while (get_next_line(fd,&line) > 0)
	{
		ft_lstadd(&head, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	return (head);
}

int8_t		ft_make_map(t_SDL *sdlT)
{
	int16_t		fd;

	if (!(sdlT->argvT.flag & MAPN))
		return (ft_errors("error mapT flag"));
	else
	{
		fd = (int16_t)open(sdlT->argvT.mapName, O_RDONLY);
		if (fd < 1)
			return (ft_errors("error fd"));
		else
			sdlT->mapT.head = ft_pars_file(fd);
	}
	ft_revers_list(&sdlT->mapT.head);
	if (!mapping(&sdlT->mapT))
		return (0);
	close(fd);
	print_map(&sdlT->mapT);
	return (1);
}
