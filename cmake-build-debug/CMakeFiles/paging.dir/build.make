# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/axelzucho/Apps/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/axelzucho/Apps/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/axelzucho/CLionProjects/paging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/axelzucho/CLionProjects/paging/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/paging.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/paging.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paging.dir/flags.make

CMakeFiles/paging.dir/main.cpp.o: CMakeFiles/paging.dir/flags.make
CMakeFiles/paging.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axelzucho/CLionProjects/paging/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/paging.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/paging.dir/main.cpp.o -c /home/axelzucho/CLionProjects/paging/main.cpp

CMakeFiles/paging.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paging.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axelzucho/CLionProjects/paging/main.cpp > CMakeFiles/paging.dir/main.cpp.i

CMakeFiles/paging.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paging.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axelzucho/CLionProjects/paging/main.cpp -o CMakeFiles/paging.dir/main.cpp.s

# Object files for target paging
paging_OBJECTS = \
"CMakeFiles/paging.dir/main.cpp.o"

# External object files for target paging
paging_EXTERNAL_OBJECTS =

paging: CMakeFiles/paging.dir/main.cpp.o
paging: CMakeFiles/paging.dir/build.make
paging: CMakeFiles/paging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/axelzucho/CLionProjects/paging/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable paging"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paging.dir/build: paging

.PHONY : CMakeFiles/paging.dir/build

CMakeFiles/paging.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/paging.dir/cmake_clean.cmake
.PHONY : CMakeFiles/paging.dir/clean

CMakeFiles/paging.dir/depend:
	cd /home/axelzucho/CLionProjects/paging/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/axelzucho/CLionProjects/paging /home/axelzucho/CLionProjects/paging /home/axelzucho/CLionProjects/paging/cmake-build-debug /home/axelzucho/CLionProjects/paging/cmake-build-debug /home/axelzucho/CLionProjects/paging/cmake-build-debug/CMakeFiles/paging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paging.dir/depend
