# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /Users/hank08tw/Desktop/資訊之芽/69

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/69.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/69.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/69.dir/flags.make

CMakeFiles/69.dir/main.cpp.o: CMakeFiles/69.dir/flags.make
CMakeFiles/69.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/69.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/69.dir/main.cpp.o -c /Users/hank08tw/Desktop/資訊之芽/69/main.cpp

CMakeFiles/69.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/69.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hank08tw/Desktop/資訊之芽/69/main.cpp > CMakeFiles/69.dir/main.cpp.i

CMakeFiles/69.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/69.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hank08tw/Desktop/資訊之芽/69/main.cpp -o CMakeFiles/69.dir/main.cpp.s

CMakeFiles/69.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/69.dir/main.cpp.o.requires

CMakeFiles/69.dir/main.cpp.o.provides: CMakeFiles/69.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/69.dir/build.make CMakeFiles/69.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/69.dir/main.cpp.o.provides

CMakeFiles/69.dir/main.cpp.o.provides.build: CMakeFiles/69.dir/main.cpp.o


# Object files for target 69
69_OBJECTS = \
"CMakeFiles/69.dir/main.cpp.o"

# External object files for target 69
69_EXTERNAL_OBJECTS =

69: CMakeFiles/69.dir/main.cpp.o
69: CMakeFiles/69.dir/build.make
69: CMakeFiles/69.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 69"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/69.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/69.dir/build: 69

.PHONY : CMakeFiles/69.dir/build

CMakeFiles/69.dir/requires: CMakeFiles/69.dir/main.cpp.o.requires

.PHONY : CMakeFiles/69.dir/requires

CMakeFiles/69.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/69.dir/cmake_clean.cmake
.PHONY : CMakeFiles/69.dir/clean

CMakeFiles/69.dir/depend:
	cd /Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hank08tw/Desktop/資訊之芽/69 /Users/hank08tw/Desktop/資訊之芽/69 /Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug /Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug /Users/hank08tw/Desktop/資訊之芽/69/cmake-build-debug/CMakeFiles/69.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/69.dir/depend
