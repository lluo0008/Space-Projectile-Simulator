# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/lily/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lily/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lily/CMPE320/ProjectileSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lily/CMPE320/ProjectileSimulation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/main.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/main.cpp

CMakeFiles/untitled.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/main.cpp > CMakeFiles/untitled.dir/main.cpp.i

CMakeFiles/untitled.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/main.cpp -o CMakeFiles/untitled.dir/main.cpp.s

CMakeFiles/untitled.dir/RungeKutta.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/RungeKutta.cpp.o: ../RungeKutta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled.dir/RungeKutta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/RungeKutta.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/RungeKutta.cpp

CMakeFiles/untitled.dir/RungeKutta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/RungeKutta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/RungeKutta.cpp > CMakeFiles/untitled.dir/RungeKutta.cpp.i

CMakeFiles/untitled.dir/RungeKutta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/RungeKutta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/RungeKutta.cpp -o CMakeFiles/untitled.dir/RungeKutta.cpp.s

CMakeFiles/untitled.dir/Projectile.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/Projectile.cpp.o: ../Projectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled.dir/Projectile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/Projectile.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/Projectile.cpp

CMakeFiles/untitled.dir/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/Projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/Projectile.cpp > CMakeFiles/untitled.dir/Projectile.cpp.i

CMakeFiles/untitled.dir/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/Projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/Projectile.cpp -o CMakeFiles/untitled.dir/Projectile.cpp.s

CMakeFiles/untitled.dir/Helper.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/Helper.cpp.o: ../Helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled.dir/Helper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/Helper.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/Helper.cpp

CMakeFiles/untitled.dir/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/Helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/Helper.cpp > CMakeFiles/untitled.dir/Helper.cpp.i

CMakeFiles/untitled.dir/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/Helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/Helper.cpp -o CMakeFiles/untitled.dir/Helper.cpp.s

CMakeFiles/untitled.dir/Environment.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/Environment.cpp.o: ../Environment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled.dir/Environment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/Environment.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/Environment.cpp

CMakeFiles/untitled.dir/Environment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/Environment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/Environment.cpp > CMakeFiles/untitled.dir/Environment.cpp.i

CMakeFiles/untitled.dir/Environment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/Environment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/Environment.cpp -o CMakeFiles/untitled.dir/Environment.cpp.s

CMakeFiles/untitled.dir/EnvironmentException.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/EnvironmentException.cpp.o: ../EnvironmentException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled.dir/EnvironmentException.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/EnvironmentException.cpp.o -c /home/lily/CMPE320/ProjectileSimulation/EnvironmentException.cpp

CMakeFiles/untitled.dir/EnvironmentException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/EnvironmentException.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lily/CMPE320/ProjectileSimulation/EnvironmentException.cpp > CMakeFiles/untitled.dir/EnvironmentException.cpp.i

CMakeFiles/untitled.dir/EnvironmentException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/EnvironmentException.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lily/CMPE320/ProjectileSimulation/EnvironmentException.cpp -o CMakeFiles/untitled.dir/EnvironmentException.cpp.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.cpp.o" \
"CMakeFiles/untitled.dir/RungeKutta.cpp.o" \
"CMakeFiles/untitled.dir/Projectile.cpp.o" \
"CMakeFiles/untitled.dir/Helper.cpp.o" \
"CMakeFiles/untitled.dir/Environment.cpp.o" \
"CMakeFiles/untitled.dir/EnvironmentException.cpp.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/main.cpp.o
untitled: CMakeFiles/untitled.dir/RungeKutta.cpp.o
untitled: CMakeFiles/untitled.dir/Projectile.cpp.o
untitled: CMakeFiles/untitled.dir/Helper.cpp.o
untitled: CMakeFiles/untitled.dir/Environment.cpp.o
untitled: CMakeFiles/untitled.dir/EnvironmentException.cpp.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /home/lily/CMPE320/ProjectileSimulation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lily/CMPE320/ProjectileSimulation /home/lily/CMPE320/ProjectileSimulation /home/lily/CMPE320/ProjectileSimulation/cmake-build-debug /home/lily/CMPE320/ProjectileSimulation/cmake-build-debug /home/lily/CMPE320/ProjectileSimulation/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend
