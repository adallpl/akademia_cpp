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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/PROJECT/akademia_cpp/cmake-gtest-master2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/guarantees.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/guarantees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/guarantees.dir/flags.make

CMakeFiles/guarantees.dir/src/guarantees.cpp.o: CMakeFiles/guarantees.dir/flags.make
CMakeFiles/guarantees.dir/src/guarantees.cpp.o: /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/guarantees.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/guarantees.dir/src/guarantees.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/guarantees.dir/src/guarantees.cpp.o -c /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/guarantees.cpp

CMakeFiles/guarantees.dir/src/guarantees.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/guarantees.dir/src/guarantees.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/guarantees.cpp > CMakeFiles/guarantees.dir/src/guarantees.cpp.i

CMakeFiles/guarantees.dir/src/guarantees.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/guarantees.dir/src/guarantees.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/guarantees.cpp -o CMakeFiles/guarantees.dir/src/guarantees.cpp.s

CMakeFiles/guarantees.dir/src/guarantees.cpp.o.requires:

.PHONY : CMakeFiles/guarantees.dir/src/guarantees.cpp.o.requires

CMakeFiles/guarantees.dir/src/guarantees.cpp.o.provides: CMakeFiles/guarantees.dir/src/guarantees.cpp.o.requires
	$(MAKE) -f CMakeFiles/guarantees.dir/build.make CMakeFiles/guarantees.dir/src/guarantees.cpp.o.provides.build
.PHONY : CMakeFiles/guarantees.dir/src/guarantees.cpp.o.provides

CMakeFiles/guarantees.dir/src/guarantees.cpp.o.provides.build: CMakeFiles/guarantees.dir/src/guarantees.cpp.o


# Object files for target guarantees
guarantees_OBJECTS = \
"CMakeFiles/guarantees.dir/src/guarantees.cpp.o"

# External object files for target guarantees
guarantees_EXTERNAL_OBJECTS =

guarantees: CMakeFiles/guarantees.dir/src/guarantees.cpp.o
guarantees: CMakeFiles/guarantees.dir/build.make
guarantees: CMakeFiles/guarantees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable guarantees"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/guarantees.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/guarantees.dir/build: guarantees

.PHONY : CMakeFiles/guarantees.dir/build

CMakeFiles/guarantees.dir/requires: CMakeFiles/guarantees.dir/src/guarantees.cpp.o.requires

.PHONY : CMakeFiles/guarantees.dir/requires

CMakeFiles/guarantees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/guarantees.dir/cmake_clean.cmake
.PHONY : CMakeFiles/guarantees.dir/clean

CMakeFiles/guarantees.dir/depend:
	cd /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/PROJECT/akademia_cpp/cmake-gtest-master2 /home/user/PROJECT/akademia_cpp/cmake-gtest-master2 /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles/guarantees.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/guarantees.dir/depend

