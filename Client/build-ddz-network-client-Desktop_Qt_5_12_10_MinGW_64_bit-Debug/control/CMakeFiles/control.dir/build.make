# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\DDZ-network\Client\ddz-network-client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug

# Include any dependencies generated for this target.
include control/CMakeFiles/control.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include control/CMakeFiles/control.dir/compiler_depend.make

# Include the progress variables for this target.
include control/CMakeFiles/control.dir/progress.make

# Include the compile flags for this target's objects.
include control/CMakeFiles/control.dir/flags.make

control/CMakeFiles/control.dir/codegen:
.PHONY : control/CMakeFiles/control.dir/codegen

control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj: control/CMakeFiles/control.dir/flags.make
control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj: control/CMakeFiles/control.dir/includes_CXX.rsp
control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj: control/control_autogen/mocs_compilation.cpp
control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj: control/CMakeFiles/control.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\control.dir\control_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\control.dir\control_autogen\mocs_compilation.cpp.obj -c D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control\control_autogen\mocs_compilation.cpp

control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.i"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control\control_autogen\mocs_compilation.cpp > CMakeFiles\control.dir\control_autogen\mocs_compilation.cpp.i

control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.s"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control\control_autogen\mocs_compilation.cpp -o CMakeFiles\control.dir\control_autogen\mocs_compilation.cpp.s

control/CMakeFiles/control.dir/bgmcontrol.cpp.obj: control/CMakeFiles/control.dir/flags.make
control/CMakeFiles/control.dir/bgmcontrol.cpp.obj: control/CMakeFiles/control.dir/includes_CXX.rsp
control/CMakeFiles/control.dir/bgmcontrol.cpp.obj: D:/DDZ-network/Client/ddz-network-client/control/bgmcontrol.cpp
control/CMakeFiles/control.dir/bgmcontrol.cpp.obj: control/CMakeFiles/control.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object control/CMakeFiles/control.dir/bgmcontrol.cpp.obj"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT control/CMakeFiles/control.dir/bgmcontrol.cpp.obj -MF CMakeFiles\control.dir\bgmcontrol.cpp.obj.d -o CMakeFiles\control.dir\bgmcontrol.cpp.obj -c D:\DDZ-network\Client\ddz-network-client\control\bgmcontrol.cpp

control/CMakeFiles/control.dir/bgmcontrol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/control.dir/bgmcontrol.cpp.i"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DDZ-network\Client\ddz-network-client\control\bgmcontrol.cpp > CMakeFiles\control.dir\bgmcontrol.cpp.i

control/CMakeFiles/control.dir/bgmcontrol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/control.dir/bgmcontrol.cpp.s"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\DDZ-network\Client\ddz-network-client\control\bgmcontrol.cpp -o CMakeFiles\control.dir\bgmcontrol.cpp.s

control/CMakeFiles/control.dir/gamecontrol.cpp.obj: control/CMakeFiles/control.dir/flags.make
control/CMakeFiles/control.dir/gamecontrol.cpp.obj: control/CMakeFiles/control.dir/includes_CXX.rsp
control/CMakeFiles/control.dir/gamecontrol.cpp.obj: D:/DDZ-network/Client/ddz-network-client/control/gamecontrol.cpp
control/CMakeFiles/control.dir/gamecontrol.cpp.obj: control/CMakeFiles/control.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object control/CMakeFiles/control.dir/gamecontrol.cpp.obj"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT control/CMakeFiles/control.dir/gamecontrol.cpp.obj -MF CMakeFiles\control.dir\gamecontrol.cpp.obj.d -o CMakeFiles\control.dir\gamecontrol.cpp.obj -c D:\DDZ-network\Client\ddz-network-client\control\gamecontrol.cpp

control/CMakeFiles/control.dir/gamecontrol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/control.dir/gamecontrol.cpp.i"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DDZ-network\Client\ddz-network-client\control\gamecontrol.cpp > CMakeFiles\control.dir\gamecontrol.cpp.i

control/CMakeFiles/control.dir/gamecontrol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/control.dir/gamecontrol.cpp.s"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && D:\Qt5\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\DDZ-network\Client\ddz-network-client\control\gamecontrol.cpp -o CMakeFiles\control.dir\gamecontrol.cpp.s

# Object files for target control
control_OBJECTS = \
"CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/control.dir/bgmcontrol.cpp.obj" \
"CMakeFiles/control.dir/gamecontrol.cpp.obj"

# External object files for target control
control_EXTERNAL_OBJECTS =

control/libcontrol.a: control/CMakeFiles/control.dir/control_autogen/mocs_compilation.cpp.obj
control/libcontrol.a: control/CMakeFiles/control.dir/bgmcontrol.cpp.obj
control/libcontrol.a: control/CMakeFiles/control.dir/gamecontrol.cpp.obj
control/libcontrol.a: control/CMakeFiles/control.dir/build.make
control/libcontrol.a: control/CMakeFiles/control.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libcontrol.a"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && $(CMAKE_COMMAND) -P CMakeFiles\control.dir\cmake_clean_target.cmake
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\control.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
control/CMakeFiles/control.dir/build: control/libcontrol.a
.PHONY : control/CMakeFiles/control.dir/build

control/CMakeFiles/control.dir/clean:
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control && $(CMAKE_COMMAND) -P CMakeFiles\control.dir\cmake_clean.cmake
.PHONY : control/CMakeFiles/control.dir/clean

control/CMakeFiles/control.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\DDZ-network\Client\ddz-network-client D:\DDZ-network\Client\ddz-network-client\control D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\control\CMakeFiles\control.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : control/CMakeFiles/control.dir/depend

