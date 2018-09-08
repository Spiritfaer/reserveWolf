/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:54:01 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/08 10:54:01 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int			main(int argc, AR argv)
{
	t_sdl	sdl_t;

	ft_read_argv(argc, argv, &sdl_t.argv_t);
	if (ft_init(&sdl_t))
	{
		if (ft_make_map(&sdl_t))
		{
			ft_helper();
			ft_process(&sdl_t);
		}
		else
			return (ft_errors("Error make_map false!"));
	}
	else
		return (ft_errors("Error initSDL false!"));
	ft_end(&sdl_t);
	return (0);
}

void		ft_helper(void)
{
	ft_putendl("/-------------------  PRESS  --------------------/");
	ft_putendl("--------------  P to poused music  ---------------");
	ft_putendl("------  UP, DOWN, LEFT and RIGHT to moving  ------");
	ft_putendl("-----------  W, S, A and D to moving  ------------");
	ft_putendl("--  NUM_MIN or NUM_PLUS to change music volume  --");
	ft_putendl("--------------  * to change track  ---------------");
}

int8_t		ft_errors(const char *error)
{
	ft_putstr_fd(error, 2);
	return (-1);
}

void		ft_end(t_sdl *sdl_t)
{
	int32_t	i;

	i = 0;
	if (sdl_t->ren != NULL)
	{
		SDL_DestroyRenderer(sdl_t->ren);
		sdl_t->ren = NULL;
	}
	if (sdl_t->window != NULL)
	{
		SDL_DestroyWindow(sdl_t->window);
		sdl_t->window = NULL;
	}
	while (i < 2)
	{
		Mix_FreeMusic(sdl_t->music[i]);
		sdl_t->music[i] = NULL;
		i++;
	}
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
