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

# Utility rule file for player_autogen.

# Include any custom commands dependencies for this target.
include player/CMakeFiles/player_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include player/CMakeFiles/player_autogen.dir/progress.make

player/CMakeFiles/player_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target player"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\player && D:\cmake\bin\cmake.exe -E cmake_autogen D:/DDZ-network/Client/build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug/player/CMakeFiles/player_autogen.dir/AutogenInfo.json Debug

player/CMakeFiles/player_autogen.dir/codegen:
.PHONY : player/CMakeFiles/player_autogen.dir/codegen

player_autogen: player/CMakeFiles/player_autogen
player_autogen: player/CMakeFiles/player_autogen.dir/build.make
.PHONY : player_autogen

# Rule to build all files generated by this target.
player/CMakeFiles/player_autogen.dir/build: player_autogen
.PHONY : player/CMakeFiles/player_autogen.dir/build

player/CMakeFiles/player_autogen.dir/clean:
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\player && $(CMAKE_COMMAND) -P CMakeFiles\player_autogen.dir\cmake_clean.cmake
.PHONY : player/CMakeFiles/player_autogen.dir/clean

player/CMakeFiles/player_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\DDZ-network\Client\ddz-network-client D:\DDZ-network\Client\ddz-network-client\player D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\player D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\player\CMakeFiles\player_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : player/CMakeFiles/player_autogen.dir/depend

