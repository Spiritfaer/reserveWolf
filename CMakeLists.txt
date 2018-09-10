cmake_minimum_required(VERSION 3.9)
project(wolf3d C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ft_wall -Wextra -Werror")

include_directories(libft src)
include_directories(~/.brew/Cellar/sdl2/2.0.8/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_image/2.0.3/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_mixer/2.0.2_3/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2/)

link_directories(libft src)
link_directories(~/.brew/Cellar/sdl2/2.0.8/lib/)
link_directories(~/.brew/Cellar/sdl2_image/2.0.3/lib/)
link_directories(~/.brew/Cellar/sdl2_mixer/2.0.2_3/lib/)
link_directories(~/.brew/Cellar/sdl2_ttf/2.0.14/lib/)

#add_executable(wolf3d main.c)

set(SOURCE_FILES main.c includes/wolf3d.h
		foo.c init.c list.c pars.c map.c renderer.c raycast.c drawing.c event.c floor.c
		set_struct.c maker.c event_control.c sprite.c event_mix.c checks.c weapon.c)
add_executable(wolf3d ${SOURCE_FILES})

target_link_libraries(wolf3d -lft
		-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
		"-framework OpenGL" "-framework AppKit")