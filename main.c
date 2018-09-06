#include "includes/wolf3d.h"

void ft_helper(void)
{
	ft_putendl("/-------------------  PRESS  --------------------/");
	ft_putendl("--------------  P to poused music  ---------------");
	ft_putendl("------  UP, DOWN, LEFT and RIGHT to moving  ------");
	ft_putendl("-----------  W, S, A and D to moving  ------------");
	ft_putendl("--  NUM_MIN or NUM_PLUS to change music volume  --");
	ft_putendl("--------------  * to change track  ---------------");
}

int main(int argc, AR argv)
{
	t_SDL sdlT;

	readArgv(argc, argv, &sdlT.argvT);
	if (ft_initSDL(&sdlT))
	{
		if (ft_make_map(&sdlT))
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
