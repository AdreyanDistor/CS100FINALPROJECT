# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001

# Include any dependencies generated for this target.
include test/CMakeFiles/runAllTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/runAllTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runAllTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runAllTests.dir/flags.make

test/CMakeFiles/runAllTests.dir/test.cpp.o: test/CMakeFiles/runAllTests.dir/flags.make
test/CMakeFiles/runAllTests.dir/test.cpp.o: test/test.cpp
test/CMakeFiles/runAllTests.dir/test.cpp.o: test/CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runAllTests.dir/test.cpp.o"
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runAllTests.dir/test.cpp.o -MF CMakeFiles/runAllTests.dir/test.cpp.o.d -o CMakeFiles/runAllTests.dir/test.cpp.o -c /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test/test.cpp

test/CMakeFiles/runAllTests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/test.cpp.i"
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test/test.cpp > CMakeFiles/runAllTests.dir/test.cpp.i

test/CMakeFiles/runAllTests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/test.cpp.s"
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test/test.cpp -o CMakeFiles/runAllTests.dir/test.cpp.s

# Object files for target runAllTests
runAllTests_OBJECTS = \
"CMakeFiles/runAllTests.dir/test.cpp.o"

# External object files for target runAllTests
runAllTests_EXTERNAL_OBJECTS =

bin/runAllTests: test/CMakeFiles/runAllTests.dir/test.cpp.o
bin/runAllTests: test/CMakeFiles/runAllTests.dir/build.make
bin/runAllTests: lib/libgmock.a
bin/runAllTests: lib/libgtest.a
bin/runAllTests: lib/libgtest_main.a
bin/runAllTests: lib/libsimpleLibrary.a
bin/runAllTests: lib/libgtest.a
bin/runAllTests: /usr/lib64/libm.so
bin/runAllTests: test/CMakeFiles/runAllTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/runAllTests"
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runAllTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runAllTests.dir/build: bin/runAllTests
.PHONY : test/CMakeFiles/runAllTests.dir/build

test/CMakeFiles/runAllTests.dir/clean:
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test && $(CMAKE_COMMAND) -P CMakeFiles/runAllTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runAllTests.dir/clean

test/CMakeFiles/runAllTests.dir/depend:
	cd /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001 /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001 /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test /home/csmajs/adist003/final-project-scelo002-nvern003-adist003-ogodh001/test/CMakeFiles/runAllTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runAllTests.dir/depend

