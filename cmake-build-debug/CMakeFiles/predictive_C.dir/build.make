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
CMAKE_COMMAND = /home/niarkx/Documents/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/niarkx/Documents/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/predictive_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/predictive_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/predictive_C.dir/flags.make

CMakeFiles/predictive_C.dir/bibli_doc.c.o: CMakeFiles/predictive_C.dir/flags.make
CMakeFiles/predictive_C.dir/bibli_doc.c.o: ../bibli_doc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/predictive_C.dir/bibli_doc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/predictive_C.dir/bibli_doc.c.o   -c /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_doc.c

CMakeFiles/predictive_C.dir/bibli_doc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/predictive_C.dir/bibli_doc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_doc.c > CMakeFiles/predictive_C.dir/bibli_doc.c.i

CMakeFiles/predictive_C.dir/bibli_doc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/predictive_C.dir/bibli_doc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_doc.c -o CMakeFiles/predictive_C.dir/bibli_doc.c.s

CMakeFiles/predictive_C.dir/bibli_doc.c.o.requires:

.PHONY : CMakeFiles/predictive_C.dir/bibli_doc.c.o.requires

CMakeFiles/predictive_C.dir/bibli_doc.c.o.provides: CMakeFiles/predictive_C.dir/bibli_doc.c.o.requires
	$(MAKE) -f CMakeFiles/predictive_C.dir/build.make CMakeFiles/predictive_C.dir/bibli_doc.c.o.provides.build
.PHONY : CMakeFiles/predictive_C.dir/bibli_doc.c.o.provides

CMakeFiles/predictive_C.dir/bibli_doc.c.o.provides.build: CMakeFiles/predictive_C.dir/bibli_doc.c.o


CMakeFiles/predictive_C.dir/bibli_pred.c.o: CMakeFiles/predictive_C.dir/flags.make
CMakeFiles/predictive_C.dir/bibli_pred.c.o: ../bibli_pred.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/predictive_C.dir/bibli_pred.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/predictive_C.dir/bibli_pred.c.o   -c /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_pred.c

CMakeFiles/predictive_C.dir/bibli_pred.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/predictive_C.dir/bibli_pred.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_pred.c > CMakeFiles/predictive_C.dir/bibli_pred.c.i

CMakeFiles/predictive_C.dir/bibli_pred.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/predictive_C.dir/bibli_pred.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/bibli_pred.c -o CMakeFiles/predictive_C.dir/bibli_pred.c.s

CMakeFiles/predictive_C.dir/bibli_pred.c.o.requires:

.PHONY : CMakeFiles/predictive_C.dir/bibli_pred.c.o.requires

CMakeFiles/predictive_C.dir/bibli_pred.c.o.provides: CMakeFiles/predictive_C.dir/bibli_pred.c.o.requires
	$(MAKE) -f CMakeFiles/predictive_C.dir/build.make CMakeFiles/predictive_C.dir/bibli_pred.c.o.provides.build
.PHONY : CMakeFiles/predictive_C.dir/bibli_pred.c.o.provides

CMakeFiles/predictive_C.dir/bibli_pred.c.o.provides.build: CMakeFiles/predictive_C.dir/bibli_pred.c.o


CMakeFiles/predictive_C.dir/testFunction.c.o: CMakeFiles/predictive_C.dir/flags.make
CMakeFiles/predictive_C.dir/testFunction.c.o: ../testFunction.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/predictive_C.dir/testFunction.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/predictive_C.dir/testFunction.c.o   -c /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/testFunction.c

CMakeFiles/predictive_C.dir/testFunction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/predictive_C.dir/testFunction.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/testFunction.c > CMakeFiles/predictive_C.dir/testFunction.c.i

CMakeFiles/predictive_C.dir/testFunction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/predictive_C.dir/testFunction.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/testFunction.c -o CMakeFiles/predictive_C.dir/testFunction.c.s

CMakeFiles/predictive_C.dir/testFunction.c.o.requires:

.PHONY : CMakeFiles/predictive_C.dir/testFunction.c.o.requires

CMakeFiles/predictive_C.dir/testFunction.c.o.provides: CMakeFiles/predictive_C.dir/testFunction.c.o.requires
	$(MAKE) -f CMakeFiles/predictive_C.dir/build.make CMakeFiles/predictive_C.dir/testFunction.c.o.provides.build
.PHONY : CMakeFiles/predictive_C.dir/testFunction.c.o.provides

CMakeFiles/predictive_C.dir/testFunction.c.o.provides.build: CMakeFiles/predictive_C.dir/testFunction.c.o


# Object files for target predictive_C
predictive_C_OBJECTS = \
"CMakeFiles/predictive_C.dir/bibli_doc.c.o" \
"CMakeFiles/predictive_C.dir/bibli_pred.c.o" \
"CMakeFiles/predictive_C.dir/testFunction.c.o"

# External object files for target predictive_C
predictive_C_EXTERNAL_OBJECTS =

predictive_C: CMakeFiles/predictive_C.dir/bibli_doc.c.o
predictive_C: CMakeFiles/predictive_C.dir/bibli_pred.c.o
predictive_C: CMakeFiles/predictive_C.dir/testFunction.c.o
predictive_C: CMakeFiles/predictive_C.dir/build.make
predictive_C: CMakeFiles/predictive_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable predictive_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/predictive_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/predictive_C.dir/build: predictive_C

.PHONY : CMakeFiles/predictive_C.dir/build

CMakeFiles/predictive_C.dir/requires: CMakeFiles/predictive_C.dir/bibli_doc.c.o.requires
CMakeFiles/predictive_C.dir/requires: CMakeFiles/predictive_C.dir/bibli_pred.c.o.requires
CMakeFiles/predictive_C.dir/requires: CMakeFiles/predictive_C.dir/testFunction.c.o.requires

.PHONY : CMakeFiles/predictive_C.dir/requires

CMakeFiles/predictive_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/predictive_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/predictive_C.dir/clean

CMakeFiles/predictive_C.dir/depend:
	cd /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug /home/niarkx/Seafile/Documents/Ismin_EI_2017/semestre2/algo_prog2/projet/predictive_C/cmake-build-debug/CMakeFiles/predictive_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/predictive_C.dir/depend

