cmake_minimum_required(VERSION 3.9)
project(wolf3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

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

set(SOURCE_FILES src/main.c includes/wolf3d.h
		src/foo.c src/init.c src/list.c src/pars.c src/map.c src/renderer.c src/raycast.c src/drawing.c src/event.c src/floor.c
		src/set_struct.c src/maker.c src/event_control.c src/sprite.c src/event_mix.c src/checks.c src/weapon.c)
add_executable(wolf3d ${SOURCE_FILES})

target_link_libraries(wolf3d -lft
		-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
		"-framework OpenGL" "-framework AppKit")