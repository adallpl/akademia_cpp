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
include CMakeFiles/io_exceptions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/io_exceptions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/io_exceptions.dir/flags.make

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o: CMakeFiles/io_exceptions.dir/flags.make
CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o: /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/io/exceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o -c /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/io/exceptions.cpp

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/io/exceptions.cpp > CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.i

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/PROJECT/akademia_cpp/cmake-gtest-master2/src/io/exceptions.cpp -o CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.s

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.requires:

.PHONY : CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.requires

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.provides: CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.requires
	$(MAKE) -f CMakeFiles/io_exceptions.dir/build.make CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.provides.build
.PHONY : CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.provides

CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.provides.build: CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o


# Object files for target io_exceptions
io_exceptions_OBJECTS = \
"CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o"

# External object files for target io_exceptions
io_exceptions_EXTERNAL_OBJECTS =

io_exceptions: CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o
io_exceptions: CMakeFiles/io_exceptions.dir/build.make
io_exceptions: CMakeFiles/io_exceptions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable io_exceptions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/io_exceptions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/io_exceptions.dir/build: io_exceptions

.PHONY : CMakeFiles/io_exceptions.dir/build

CMakeFiles/io_exceptions.dir/requires: CMakeFiles/io_exceptions.dir/src/io/exceptions.cpp.o.requires

.PHONY : CMakeFiles/io_exceptions.dir/requires

CMakeFiles/io_exceptions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/io_exceptions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/io_exceptions.dir/clean

CMakeFiles/io_exceptions.dir/depend:
	cd /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/PROJECT/akademia_cpp/cmake-gtest-master2 /home/user/PROJECT/akademia_cpp/cmake-gtest-master2 /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default /home/user/PROJECT/akademia_cpp/build-cmake-gtest-master2-Desktop-Default/CMakeFiles/io_exceptions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/io_exceptions.dir/depend

