# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wolf3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wolf3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wolf3d.dir/flags.make

CMakeFiles/wolf3d.dir/main.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wolf3d.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/main.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/main.c

CMakeFiles/wolf3d.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/main.c > CMakeFiles/wolf3d.dir/main.c.i

CMakeFiles/wolf3d.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/main.c -o CMakeFiles/wolf3d.dir/main.c.s

CMakeFiles/wolf3d.dir/main.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/main.c.o.requires

CMakeFiles/wolf3d.dir/main.c.o.provides: CMakeFiles/wolf3d.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/main.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/main.c.o.provides

CMakeFiles/wolf3d.dir/main.c.o.provides.build: CMakeFiles/wolf3d.dir/main.c.o


CMakeFiles/wolf3d.dir/foo.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/foo.c.o: ../foo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/wolf3d.dir/foo.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/foo.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/foo.c

CMakeFiles/wolf3d.dir/foo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/foo.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/foo.c > CMakeFiles/wolf3d.dir/foo.c.i

CMakeFiles/wolf3d.dir/foo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/foo.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/foo.c -o CMakeFiles/wolf3d.dir/foo.c.s

CMakeFiles/wolf3d.dir/foo.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/foo.c.o.requires

CMakeFiles/wolf3d.dir/foo.c.o.provides: CMakeFiles/wolf3d.dir/foo.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/foo.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/foo.c.o.provides

CMakeFiles/wolf3d.dir/foo.c.o.provides.build: CMakeFiles/wolf3d.dir/foo.c.o


CMakeFiles/wolf3d.dir/init.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/init.c.o: ../init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/wolf3d.dir/init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/init.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/init.c

CMakeFiles/wolf3d.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/init.c > CMakeFiles/wolf3d.dir/init.c.i

CMakeFiles/wolf3d.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/init.c -o CMakeFiles/wolf3d.dir/init.c.s

CMakeFiles/wolf3d.dir/init.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/init.c.o.requires

CMakeFiles/wolf3d.dir/init.c.o.provides: CMakeFiles/wolf3d.dir/init.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/init.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/init.c.o.provides

CMakeFiles/wolf3d.dir/init.c.o.provides.build: CMakeFiles/wolf3d.dir/init.c.o


CMakeFiles/wolf3d.dir/list.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/wolf3d.dir/list.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/list.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/list.c

CMakeFiles/wolf3d.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/list.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/list.c > CMakeFiles/wolf3d.dir/list.c.i

CMakeFiles/wolf3d.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/list.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/list.c -o CMakeFiles/wolf3d.dir/list.c.s

CMakeFiles/wolf3d.dir/list.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/list.c.o.requires

CMakeFiles/wolf3d.dir/list.c.o.provides: CMakeFiles/wolf3d.dir/list.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/list.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/list.c.o.provides

CMakeFiles/wolf3d.dir/list.c.o.provides.build: CMakeFiles/wolf3d.dir/list.c.o


CMakeFiles/wolf3d.dir/pars.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/pars.c.o: ../pars.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/wolf3d.dir/pars.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/pars.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/pars.c

CMakeFiles/wolf3d.dir/pars.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/pars.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/pars.c > CMakeFiles/wolf3d.dir/pars.c.i

CMakeFiles/wolf3d.dir/pars.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/pars.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/pars.c -o CMakeFiles/wolf3d.dir/pars.c.s

CMakeFiles/wolf3d.dir/pars.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/pars.c.o.requires

CMakeFiles/wolf3d.dir/pars.c.o.provides: CMakeFiles/wolf3d.dir/pars.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/pars.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/pars.c.o.provides

CMakeFiles/wolf3d.dir/pars.c.o.provides.build: CMakeFiles/wolf3d.dir/pars.c.o


CMakeFiles/wolf3d.dir/map.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/map.c.o: ../map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/wolf3d.dir/map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/map.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/map.c

CMakeFiles/wolf3d.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/map.c > CMakeFiles/wolf3d.dir/map.c.i

CMakeFiles/wolf3d.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/map.c -o CMakeFiles/wolf3d.dir/map.c.s

CMakeFiles/wolf3d.dir/map.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/map.c.o.requires

CMakeFiles/wolf3d.dir/map.c.o.provides: CMakeFiles/wolf3d.dir/map.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/map.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/map.c.o.provides

CMakeFiles/wolf3d.dir/map.c.o.provides.build: CMakeFiles/wolf3d.dir/map.c.o


CMakeFiles/wolf3d.dir/renderer.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/renderer.c.o: ../renderer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/wolf3d.dir/renderer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/renderer.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/renderer.c

CMakeFiles/wolf3d.dir/renderer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/renderer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/renderer.c > CMakeFiles/wolf3d.dir/renderer.c.i

CMakeFiles/wolf3d.dir/renderer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/renderer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/renderer.c -o CMakeFiles/wolf3d.dir/renderer.c.s

CMakeFiles/wolf3d.dir/renderer.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/renderer.c.o.requires

CMakeFiles/wolf3d.dir/renderer.c.o.provides: CMakeFiles/wolf3d.dir/renderer.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/renderer.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/renderer.c.o.provides

CMakeFiles/wolf3d.dir/renderer.c.o.provides.build: CMakeFiles/wolf3d.dir/renderer.c.o


CMakeFiles/wolf3d.dir/raycast.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/raycast.c.o: ../raycast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/wolf3d.dir/raycast.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/raycast.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/raycast.c

CMakeFiles/wolf3d.dir/raycast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/raycast.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/raycast.c > CMakeFiles/wolf3d.dir/raycast.c.i

CMakeFiles/wolf3d.dir/raycast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/raycast.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/raycast.c -o CMakeFiles/wolf3d.dir/raycast.c.s

CMakeFiles/wolf3d.dir/raycast.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/raycast.c.o.requires

CMakeFiles/wolf3d.dir/raycast.c.o.provides: CMakeFiles/wolf3d.dir/raycast.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/raycast.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/raycast.c.o.provides

CMakeFiles/wolf3d.dir/raycast.c.o.provides.build: CMakeFiles/wolf3d.dir/raycast.c.o


CMakeFiles/wolf3d.dir/drawing.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/drawing.c.o: ../drawing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/wolf3d.dir/drawing.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/drawing.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/drawing.c

CMakeFiles/wolf3d.dir/drawing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/drawing.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/drawing.c > CMakeFiles/wolf3d.dir/drawing.c.i

CMakeFiles/wolf3d.dir/drawing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/drawing.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/drawing.c -o CMakeFiles/wolf3d.dir/drawing.c.s

CMakeFiles/wolf3d.dir/drawing.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/drawing.c.o.requires

CMakeFiles/wolf3d.dir/drawing.c.o.provides: CMakeFiles/wolf3d.dir/drawing.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/drawing.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/drawing.c.o.provides

CMakeFiles/wolf3d.dir/drawing.c.o.provides.build: CMakeFiles/wolf3d.dir/drawing.c.o


CMakeFiles/wolf3d.dir/event.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/event.c.o: ../event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/wolf3d.dir/event.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/event.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event.c

CMakeFiles/wolf3d.dir/event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/event.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event.c > CMakeFiles/wolf3d.dir/event.c.i

CMakeFiles/wolf3d.dir/event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/event.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event.c -o CMakeFiles/wolf3d.dir/event.c.s

CMakeFiles/wolf3d.dir/event.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/event.c.o.requires

CMakeFiles/wolf3d.dir/event.c.o.provides: CMakeFiles/wolf3d.dir/event.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/event.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/event.c.o.provides

CMakeFiles/wolf3d.dir/event.c.o.provides.build: CMakeFiles/wolf3d.dir/event.c.o


CMakeFiles/wolf3d.dir/floor.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/floor.c.o: ../floor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/wolf3d.dir/floor.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/floor.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/floor.c

CMakeFiles/wolf3d.dir/floor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/floor.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/floor.c > CMakeFiles/wolf3d.dir/floor.c.i

CMakeFiles/wolf3d.dir/floor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/floor.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/floor.c -o CMakeFiles/wolf3d.dir/floor.c.s

CMakeFiles/wolf3d.dir/floor.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/floor.c.o.requires

CMakeFiles/wolf3d.dir/floor.c.o.provides: CMakeFiles/wolf3d.dir/floor.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/floor.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/floor.c.o.provides

CMakeFiles/wolf3d.dir/floor.c.o.provides.build: CMakeFiles/wolf3d.dir/floor.c.o


CMakeFiles/wolf3d.dir/set_struct.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/set_struct.c.o: ../set_struct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/wolf3d.dir/set_struct.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/set_struct.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/set_struct.c

CMakeFiles/wolf3d.dir/set_struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/set_struct.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/set_struct.c > CMakeFiles/wolf3d.dir/set_struct.c.i

CMakeFiles/wolf3d.dir/set_struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/set_struct.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/set_struct.c -o CMakeFiles/wolf3d.dir/set_struct.c.s

CMakeFiles/wolf3d.dir/set_struct.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/set_struct.c.o.requires

CMakeFiles/wolf3d.dir/set_struct.c.o.provides: CMakeFiles/wolf3d.dir/set_struct.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/set_struct.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/set_struct.c.o.provides

CMakeFiles/wolf3d.dir/set_struct.c.o.provides.build: CMakeFiles/wolf3d.dir/set_struct.c.o


CMakeFiles/wolf3d.dir/maker.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/maker.c.o: ../maker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/wolf3d.dir/maker.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/maker.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/maker.c

CMakeFiles/wolf3d.dir/maker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/maker.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/maker.c > CMakeFiles/wolf3d.dir/maker.c.i

CMakeFiles/wolf3d.dir/maker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/maker.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/maker.c -o CMakeFiles/wolf3d.dir/maker.c.s

CMakeFiles/wolf3d.dir/maker.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/maker.c.o.requires

CMakeFiles/wolf3d.dir/maker.c.o.provides: CMakeFiles/wolf3d.dir/maker.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/maker.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/maker.c.o.provides

CMakeFiles/wolf3d.dir/maker.c.o.provides.build: CMakeFiles/wolf3d.dir/maker.c.o


CMakeFiles/wolf3d.dir/event_control.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/event_control.c.o: ../event_control.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/wolf3d.dir/event_control.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/event_control.c.o   -c /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event_control.c

CMakeFiles/wolf3d.dir/event_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/event_control.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event_control.c > CMakeFiles/wolf3d.dir/event_control.c.i

CMakeFiles/wolf3d.dir/event_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/event_control.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/event_control.c -o CMakeFiles/wolf3d.dir/event_control.c.s

CMakeFiles/wolf3d.dir/event_control.c.o.requires:

.PHONY : CMakeFiles/wolf3d.dir/event_control.c.o.requires

CMakeFiles/wolf3d.dir/event_control.c.o.provides: CMakeFiles/wolf3d.dir/event_control.c.o.requires
	$(MAKE) -f CMakeFiles/wolf3d.dir/build.make CMakeFiles/wolf3d.dir/event_control.c.o.provides.build
.PHONY : CMakeFiles/wolf3d.dir/event_control.c.o.provides

CMakeFiles/wolf3d.dir/event_control.c.o.provides.build: CMakeFiles/wolf3d.dir/event_control.c.o


# Object files for target wolf3d
wolf3d_OBJECTS = \
"CMakeFiles/wolf3d.dir/main.c.o" \
"CMakeFiles/wolf3d.dir/foo.c.o" \
"CMakeFiles/wolf3d.dir/init.c.o" \
"CMakeFiles/wolf3d.dir/list.c.o" \
"CMakeFiles/wolf3d.dir/pars.c.o" \
"CMakeFiles/wolf3d.dir/map.c.o" \
"CMakeFiles/wolf3d.dir/renderer.c.o" \
"CMakeFiles/wolf3d.dir/raycast.c.o" \
"CMakeFiles/wolf3d.dir/drawing.c.o" \
"CMakeFiles/wolf3d.dir/event.c.o" \
"CMakeFiles/wolf3d.dir/floor.c.o" \
"CMakeFiles/wolf3d.dir/set_struct.c.o" \
"CMakeFiles/wolf3d.dir/maker.c.o" \
"CMakeFiles/wolf3d.dir/event_control.c.o"

# External object files for target wolf3d
wolf3d_EXTERNAL_OBJECTS =

wolf3d: CMakeFiles/wolf3d.dir/main.c.o
wolf3d: CMakeFiles/wolf3d.dir/foo.c.o
wolf3d: CMakeFiles/wolf3d.dir/init.c.o
wolf3d: CMakeFiles/wolf3d.dir/list.c.o
wolf3d: CMakeFiles/wolf3d.dir/pars.c.o
wolf3d: CMakeFiles/wolf3d.dir/map.c.o
wolf3d: CMakeFiles/wolf3d.dir/renderer.c.o
wolf3d: CMakeFiles/wolf3d.dir/raycast.c.o
wolf3d: CMakeFiles/wolf3d.dir/drawing.c.o
wolf3d: CMakeFiles/wolf3d.dir/event.c.o
wolf3d: CMakeFiles/wolf3d.dir/floor.c.o
wolf3d: CMakeFiles/wolf3d.dir/set_struct.c.o
wolf3d: CMakeFiles/wolf3d.dir/maker.c.o
wolf3d: CMakeFiles/wolf3d.dir/event_control.c.o
wolf3d: CMakeFiles/wolf3d.dir/build.make
wolf3d: CMakeFiles/wolf3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable wolf3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wolf3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wolf3d.dir/build: wolf3d

.PHONY : CMakeFiles/wolf3d.dir/build

CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/main.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/foo.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/init.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/list.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/pars.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/map.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/renderer.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/raycast.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/drawing.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/event.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/floor.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/set_struct.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/maker.c.o.requires
CMakeFiles/wolf3d.dir/requires: CMakeFiles/wolf3d.dir/event_control.c.o.requires

.PHONY : CMakeFiles/wolf3d.dir/requires

CMakeFiles/wolf3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wolf3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wolf3d.dir/clean

CMakeFiles/wolf3d.dir/depend:
	cd /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug /Users/istalevs/CLionProjects/wolf3d_V1.2/reserveWolf/cmake-build-debug/CMakeFiles/wolf3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wolf3d.dir/depend

