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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ysc/ExampleJoystick

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ysc/ExampleJoystick/build

# Include any dependencies generated for this target.
include CMakeFiles/ControllerApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ControllerApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ControllerApp.dir/flags.make

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o: CMakeFiles/ControllerApp.dir/flags.make
CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o: ../src/controller/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ysc/ExampleJoystick/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o -c /home/ysc/ExampleJoystick/src/controller/controller.cpp

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ysc/ExampleJoystick/src/controller/controller.cpp > CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.i

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ysc/ExampleJoystick/src/controller/controller.cpp -o CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.s

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.requires:

.PHONY : CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.requires

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.provides: CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/ControllerApp.dir/build.make CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.provides.build
.PHONY : CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.provides

CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.provides.build: CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o


CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o: CMakeFiles/ControllerApp.dir/flags.make
CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o: ../src/controller/retroid_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ysc/ExampleJoystick/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o -c /home/ysc/ExampleJoystick/src/controller/retroid_controller.cpp

CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ysc/ExampleJoystick/src/controller/retroid_controller.cpp > CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.i

CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ysc/ExampleJoystick/src/controller/retroid_controller.cpp -o CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.s

CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.requires:

.PHONY : CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.requires

CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.provides: CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/ControllerApp.dir/build.make CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.provides.build
.PHONY : CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.provides

CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.provides.build: CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o


CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o: CMakeFiles/ControllerApp.dir/flags.make
CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o: ../src/network/udp_receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ysc/ExampleJoystick/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o -c /home/ysc/ExampleJoystick/src/network/udp_receiver.cpp

CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ysc/ExampleJoystick/src/network/udp_receiver.cpp > CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.i

CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ysc/ExampleJoystick/src/network/udp_receiver.cpp -o CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.s

CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.requires:

.PHONY : CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.requires

CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.provides: CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/ControllerApp.dir/build.make CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.provides.build
.PHONY : CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.provides

CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.provides.build: CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o


CMakeFiles/ControllerApp.dir/src/main.cpp.o: CMakeFiles/ControllerApp.dir/flags.make
CMakeFiles/ControllerApp.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ysc/ExampleJoystick/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ControllerApp.dir/src/main.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ControllerApp.dir/src/main.cpp.o -c /home/ysc/ExampleJoystick/src/main.cpp

CMakeFiles/ControllerApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ControllerApp.dir/src/main.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ysc/ExampleJoystick/src/main.cpp > CMakeFiles/ControllerApp.dir/src/main.cpp.i

CMakeFiles/ControllerApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ControllerApp.dir/src/main.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ysc/ExampleJoystick/src/main.cpp -o CMakeFiles/ControllerApp.dir/src/main.cpp.s

CMakeFiles/ControllerApp.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/ControllerApp.dir/src/main.cpp.o.requires

CMakeFiles/ControllerApp.dir/src/main.cpp.o.provides: CMakeFiles/ControllerApp.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ControllerApp.dir/build.make CMakeFiles/ControllerApp.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/ControllerApp.dir/src/main.cpp.o.provides

CMakeFiles/ControllerApp.dir/src/main.cpp.o.provides.build: CMakeFiles/ControllerApp.dir/src/main.cpp.o


# Object files for target ControllerApp
ControllerApp_OBJECTS = \
"CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o" \
"CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o" \
"CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o" \
"CMakeFiles/ControllerApp.dir/src/main.cpp.o"

# External object files for target ControllerApp
ControllerApp_EXTERNAL_OBJECTS =

ControllerApp: CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o
ControllerApp: CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o
ControllerApp: CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o
ControllerApp: CMakeFiles/ControllerApp.dir/src/main.cpp.o
ControllerApp: CMakeFiles/ControllerApp.dir/build.make
ControllerApp: fmt/libfmt.a
ControllerApp: CMakeFiles/ControllerApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ysc/ExampleJoystick/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ControllerApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ControllerApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ControllerApp.dir/build: ControllerApp

.PHONY : CMakeFiles/ControllerApp.dir/build

CMakeFiles/ControllerApp.dir/requires: CMakeFiles/ControllerApp.dir/src/controller/controller.cpp.o.requires
CMakeFiles/ControllerApp.dir/requires: CMakeFiles/ControllerApp.dir/src/controller/retroid_controller.cpp.o.requires
CMakeFiles/ControllerApp.dir/requires: CMakeFiles/ControllerApp.dir/src/network/udp_receiver.cpp.o.requires
CMakeFiles/ControllerApp.dir/requires: CMakeFiles/ControllerApp.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/ControllerApp.dir/requires

CMakeFiles/ControllerApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ControllerApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ControllerApp.dir/clean

CMakeFiles/ControllerApp.dir/depend:
	cd /home/ysc/ExampleJoystick/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ysc/ExampleJoystick /home/ysc/ExampleJoystick /home/ysc/ExampleJoystick/build /home/ysc/ExampleJoystick/build /home/ysc/ExampleJoystick/build/CMakeFiles/ControllerApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ControllerApp.dir/depend
