#include "includes/wolf3d.h"

int main(int argc, AR argv)
{
	t_SDL sdlT;

	readArgv(argc, argv, &sdlT.argvT);
	if (ft_initSDL(&sdlT))
	{
		if (ft_make_map(&sdlT))
		{
			ft_process(&sdlT);
		} else
			return (ft_errors("Error make_map false!"));
	} else
		return (ft_errors("Error initSDL false!"));
	ft_end(&sdlT);
	return 0;
}
