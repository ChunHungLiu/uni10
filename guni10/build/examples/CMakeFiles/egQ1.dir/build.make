# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yundasie/TensorNetwork/guni10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yundasie/TensorNetwork/guni10/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/egQ1.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/egQ1.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/egQ1.dir/flags.make

examples/CMakeFiles/egQ1.dir/egQ1.cpp.o: examples/CMakeFiles/egQ1.dir/flags.make
examples/CMakeFiles/egQ1.dir/egQ1.cpp.o: ../examples/egQ1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yundasie/TensorNetwork/guni10/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/egQ1.dir/egQ1.cpp.o"
	cd /home/yundasie/TensorNetwork/guni10/build/examples && /usr/lib64/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/egQ1.dir/egQ1.cpp.o -c /home/yundasie/TensorNetwork/guni10/examples/egQ1.cpp

examples/CMakeFiles/egQ1.dir/egQ1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/egQ1.dir/egQ1.cpp.i"
	cd /home/yundasie/TensorNetwork/guni10/build/examples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yundasie/TensorNetwork/guni10/examples/egQ1.cpp > CMakeFiles/egQ1.dir/egQ1.cpp.i

examples/CMakeFiles/egQ1.dir/egQ1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/egQ1.dir/egQ1.cpp.s"
	cd /home/yundasie/TensorNetwork/guni10/build/examples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yundasie/TensorNetwork/guni10/examples/egQ1.cpp -o CMakeFiles/egQ1.dir/egQ1.cpp.s

examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.requires:
.PHONY : examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.requires

examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.provides: examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/egQ1.dir/build.make examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.provides.build
.PHONY : examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.provides

examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.provides.build: examples/CMakeFiles/egQ1.dir/egQ1.cpp.o

# Object files for target egQ1
egQ1_OBJECTS = \
"CMakeFiles/egQ1.dir/egQ1.cpp.o"

# External object files for target egQ1
egQ1_EXTERNAL_OBJECTS =

bin/egQ1: examples/CMakeFiles/egQ1.dir/egQ1.cpp.o
bin/egQ1: examples/CMakeFiles/egQ1.dir/build.make
bin/egQ1: /usr/lib64/liblapack.so
bin/egQ1: /usr/lib64/libblas.so
bin/egQ1: lib/libuni10.so
bin/egQ1: /usr/lib64/liblapack.so
bin/egQ1: /usr/lib64/libblas.so
bin/egQ1: examples/CMakeFiles/egQ1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/egQ1"
	cd /home/yundasie/TensorNetwork/guni10/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/egQ1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/egQ1.dir/build: bin/egQ1
.PHONY : examples/CMakeFiles/egQ1.dir/build

examples/CMakeFiles/egQ1.dir/requires: examples/CMakeFiles/egQ1.dir/egQ1.cpp.o.requires
.PHONY : examples/CMakeFiles/egQ1.dir/requires

examples/CMakeFiles/egQ1.dir/clean:
	cd /home/yundasie/TensorNetwork/guni10/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/egQ1.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/egQ1.dir/clean

examples/CMakeFiles/egQ1.dir/depend:
	cd /home/yundasie/TensorNetwork/guni10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yundasie/TensorNetwork/guni10 /home/yundasie/TensorNetwork/guni10/examples /home/yundasie/TensorNetwork/guni10/build /home/yundasie/TensorNetwork/guni10/build/examples /home/yundasie/TensorNetwork/guni10/build/examples/CMakeFiles/egQ1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/egQ1.dir/depend
