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

# Utility rule file for thread_autogen.

# Include any custom commands dependencies for this target.
include thread/CMakeFiles/thread_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include thread/CMakeFiles/thread_autogen.dir/progress.make

thread/CMakeFiles/thread_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target thread"
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\thread && D:\cmake\bin\cmake.exe -E cmake_autogen D:/DDZ-network/Client/build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug/thread/CMakeFiles/thread_autogen.dir/AutogenInfo.json Debug

thread/CMakeFiles/thread_autogen.dir/codegen:
.PHONY : thread/CMakeFiles/thread_autogen.dir/codegen

thread_autogen: thread/CMakeFiles/thread_autogen
thread_autogen: thread/CMakeFiles/thread_autogen.dir/build.make
.PHONY : thread_autogen

# Rule to build all files generated by this target.
thread/CMakeFiles/thread_autogen.dir/build: thread_autogen
.PHONY : thread/CMakeFiles/thread_autogen.dir/build

thread/CMakeFiles/thread_autogen.dir/clean:
	cd /d D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\thread && $(CMAKE_COMMAND) -P CMakeFiles\thread_autogen.dir\cmake_clean.cmake
.PHONY : thread/CMakeFiles/thread_autogen.dir/clean

thread/CMakeFiles/thread_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\DDZ-network\Client\ddz-network-client D:\DDZ-network\Client\ddz-network-client\thread D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\thread D:\DDZ-network\Client\build-ddz-network-client-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\thread\CMakeFiles\thread_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : thread/CMakeFiles/thread_autogen.dir/depend

