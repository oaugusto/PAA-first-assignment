# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/WorkSpace/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/WorkSpace/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PAA_first_assignment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PAA_first_assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PAA_first_assignment.dir/flags.make

CMakeFiles/PAA_first_assignment.dir/main.cpp.o: CMakeFiles/PAA_first_assignment.dir/flags.make
CMakeFiles/PAA_first_assignment.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PAA_first_assignment.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PAA_first_assignment.dir/main.cpp.o -c /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/main.cpp

CMakeFiles/PAA_first_assignment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PAA_first_assignment.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/main.cpp > CMakeFiles/PAA_first_assignment.dir/main.cpp.i

CMakeFiles/PAA_first_assignment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PAA_first_assignment.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/main.cpp -o CMakeFiles/PAA_first_assignment.dir/main.cpp.s

CMakeFiles/PAA_first_assignment.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PAA_first_assignment.dir/main.cpp.o.requires

CMakeFiles/PAA_first_assignment.dir/main.cpp.o.provides: CMakeFiles/PAA_first_assignment.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PAA_first_assignment.dir/build.make CMakeFiles/PAA_first_assignment.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PAA_first_assignment.dir/main.cpp.o.provides

CMakeFiles/PAA_first_assignment.dir/main.cpp.o.provides.build: CMakeFiles/PAA_first_assignment.dir/main.cpp.o


# Object files for target PAA_first_assignment
PAA_first_assignment_OBJECTS = \
"CMakeFiles/PAA_first_assignment.dir/main.cpp.o"

# External object files for target PAA_first_assignment
PAA_first_assignment_EXTERNAL_OBJECTS =

PAA_first_assignment.exe: CMakeFiles/PAA_first_assignment.dir/main.cpp.o
PAA_first_assignment.exe: CMakeFiles/PAA_first_assignment.dir/build.make
PAA_first_assignment.exe: CMakeFiles/PAA_first_assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PAA_first_assignment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PAA_first_assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PAA_first_assignment.dir/build: PAA_first_assignment.exe

.PHONY : CMakeFiles/PAA_first_assignment.dir/build

CMakeFiles/PAA_first_assignment.dir/requires: CMakeFiles/PAA_first_assignment.dir/main.cpp.o.requires

.PHONY : CMakeFiles/PAA_first_assignment.dir/requires

CMakeFiles/PAA_first_assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PAA_first_assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PAA_first_assignment.dir/clean

CMakeFiles/PAA_first_assignment.dir/depend:
	cd /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug /cygdrive/c/Users/WorkSpace/CLionProjects/PAA-first-assignment/cmake-build-debug/CMakeFiles/PAA_first_assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PAA_first_assignment.dir/depend

