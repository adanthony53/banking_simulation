# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ad/CLionProjects/banking_simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ad/CLionProjects/banking_simulation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/banking_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/banking_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/banking_project.dir/flags.make

CMakeFiles/banking_project.dir/main.cpp.o: CMakeFiles/banking_project.dir/flags.make
CMakeFiles/banking_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ad/CLionProjects/banking_simulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/banking_project.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/banking_project.dir/main.cpp.o -c /Users/ad/CLionProjects/banking_simulation/main.cpp

CMakeFiles/banking_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/banking_project.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ad/CLionProjects/banking_simulation/main.cpp > CMakeFiles/banking_project.dir/main.cpp.i

CMakeFiles/banking_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/banking_project.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ad/CLionProjects/banking_simulation/main.cpp -o CMakeFiles/banking_project.dir/main.cpp.s

CMakeFiles/banking_project.dir/Account.cpp.o: CMakeFiles/banking_project.dir/flags.make
CMakeFiles/banking_project.dir/Account.cpp.o: ../Account.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ad/CLionProjects/banking_simulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/banking_project.dir/Account.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/banking_project.dir/Account.cpp.o -c /Users/ad/CLionProjects/banking_simulation/Account.cpp

CMakeFiles/banking_project.dir/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/banking_project.dir/Account.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ad/CLionProjects/banking_simulation/Account.cpp > CMakeFiles/banking_project.dir/Account.cpp.i

CMakeFiles/banking_project.dir/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/banking_project.dir/Account.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ad/CLionProjects/banking_simulation/Account.cpp -o CMakeFiles/banking_project.dir/Account.cpp.s

CMakeFiles/banking_project.dir/Date.cpp.o: CMakeFiles/banking_project.dir/flags.make
CMakeFiles/banking_project.dir/Date.cpp.o: ../Date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ad/CLionProjects/banking_simulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/banking_project.dir/Date.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/banking_project.dir/Date.cpp.o -c /Users/ad/CLionProjects/banking_simulation/Date.cpp

CMakeFiles/banking_project.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/banking_project.dir/Date.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ad/CLionProjects/banking_simulation/Date.cpp > CMakeFiles/banking_project.dir/Date.cpp.i

CMakeFiles/banking_project.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/banking_project.dir/Date.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ad/CLionProjects/banking_simulation/Date.cpp -o CMakeFiles/banking_project.dir/Date.cpp.s

# Object files for target banking_project
banking_project_OBJECTS = \
"CMakeFiles/banking_project.dir/main.cpp.o" \
"CMakeFiles/banking_project.dir/Account.cpp.o" \
"CMakeFiles/banking_project.dir/Date.cpp.o"

# External object files for target banking_project
banking_project_EXTERNAL_OBJECTS =

banking_project: CMakeFiles/banking_project.dir/main.cpp.o
banking_project: CMakeFiles/banking_project.dir/Account.cpp.o
banking_project: CMakeFiles/banking_project.dir/Date.cpp.o
banking_project: CMakeFiles/banking_project.dir/build.make
banking_project: CMakeFiles/banking_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ad/CLionProjects/banking_simulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable banking_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/banking_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/banking_project.dir/build: banking_project

.PHONY : CMakeFiles/banking_project.dir/build

CMakeFiles/banking_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/banking_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/banking_project.dir/clean

CMakeFiles/banking_project.dir/depend:
	cd /Users/ad/CLionProjects/banking_simulation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ad/CLionProjects/banking_simulation /Users/ad/CLionProjects/banking_simulation /Users/ad/CLionProjects/banking_simulation/cmake-build-debug /Users/ad/CLionProjects/banking_simulation/cmake-build-debug /Users/ad/CLionProjects/banking_simulation/cmake-build-debug/CMakeFiles/banking_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/banking_project.dir/depend

