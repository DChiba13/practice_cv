# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build

# Include any dependencies generated for this target.
include CMakeFiles/tutorial_cv_color.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tutorial_cv_color.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial_cv_color.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial_cv_color.dir/flags.make

CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o: CMakeFiles/tutorial_cv_color.dir/flags.make
CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o: ../src/tutorial_cv_color.cpp
CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o: CMakeFiles/tutorial_cv_color.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o -MF CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o.d -o CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o -c /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/src/tutorial_cv_color.cpp

CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/src/tutorial_cv_color.cpp > CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.i

CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/src/tutorial_cv_color.cpp -o CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.s

# Object files for target tutorial_cv_color
tutorial_cv_color_OBJECTS = \
"CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o"

# External object files for target tutorial_cv_color
tutorial_cv_color_EXTERNAL_OBJECTS =

tutorial_cv_color: CMakeFiles/tutorial_cv_color.dir/src/tutorial_cv_color.cpp.o
tutorial_cv_color: CMakeFiles/tutorial_cv_color.dir/build.make
tutorial_cv_color: CMakeFiles/tutorial_cv_color.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tutorial_cv_color"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial_cv_color.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tutorial_cv_color.dir/build: tutorial_cv_color
.PHONY : CMakeFiles/tutorial_cv_color.dir/build

CMakeFiles/tutorial_cv_color.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial_cv_color.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial_cv_color.dir/clean

CMakeFiles/tutorial_cv_color.dir/depend:
	cd /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build /home/chiba/workspace/cxx/practice_cv/tutorial_cv_color/build/CMakeFiles/tutorial_cv_color.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial_cv_color.dir/depend
