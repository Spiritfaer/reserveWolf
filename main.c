#include "includes/wolf3d.h"

int main(int argc, AR argv)
{
	t_sdl sdlT;

	readArgv(argc, argv, &sdlT.argv_t);
	if (ft_INIT(&sdlT))
	{
		if (makeMap(&sdlT))
		{
			ft_helper();
			ft_process(&sdlT);
		} else
			return (ft_errors("Error make_map false!"));
	} else
		return (ft_errors("Error initSDL false!"));
	ft_end(&sdlT);
	return 0;
}

void ft_helper(void)
{
	ft_putendl("/-------------------  PRESS  --------------------/");
	ft_putendl("--------------  P to poused music  ---------------");
	ft_putendl("------  UP, DOWN, LEFT and RIGHT to moving  ------");
	ft_putendl("-----------  W, S, A and D to moving  ------------");
	ft_putendl("--  NUM_MIN or NUM_PLUS to change music volume  --");
	ft_putendl("--------------  * to change track  ---------------");
}

int8_t ft_errors(const char *error)
{
	ft_putstr_fd(error, 2);
	return (-1);
}

void	ft_end(t_sdl *sdlT)
{
	if (sdlT->ren != NULL)
	{
		SDL_DestroyRenderer(sdlT->ren);
		sdlT->ren = NULL;
	}
	if (sdlT->window != NULL)
	{
		SDL_DestroyWindow(sdlT->window);
		sdlT->window = NULL;
	}
	for (int i = 0; i < 2; i++)
	{
		if (sdlT->music[i])
		{
			Mix_FreeMusic(sdlT->music[i]);
			sdlT->music[i] = NULL;
		}
	}
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
#ifdef DEBUG
	system("leaks wolf3d");
#endif
}