# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/SRG/Followgaris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/SRG/Followgaris

# Include any dependencies generated for this target.
include CMakeFiles/garis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/garis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/garis.dir/flags.make

CMakeFiles/garis.dir/Followgaris.cpp.o: CMakeFiles/garis.dir/flags.make
CMakeFiles/garis.dir/Followgaris.cpp.o: Followgaris.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/SRG/Followgaris/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/garis.dir/Followgaris.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/garis.dir/Followgaris.cpp.o -c /home/pi/SRG/Followgaris/Followgaris.cpp

CMakeFiles/garis.dir/Followgaris.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/garis.dir/Followgaris.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/SRG/Followgaris/Followgaris.cpp > CMakeFiles/garis.dir/Followgaris.cpp.i

CMakeFiles/garis.dir/Followgaris.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/garis.dir/Followgaris.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/SRG/Followgaris/Followgaris.cpp -o CMakeFiles/garis.dir/Followgaris.cpp.s

CMakeFiles/garis.dir/Followgaris.cpp.o.requires:

.PHONY : CMakeFiles/garis.dir/Followgaris.cpp.o.requires

CMakeFiles/garis.dir/Followgaris.cpp.o.provides: CMakeFiles/garis.dir/Followgaris.cpp.o.requires
	$(MAKE) -f CMakeFiles/garis.dir/build.make CMakeFiles/garis.dir/Followgaris.cpp.o.provides.build
.PHONY : CMakeFiles/garis.dir/Followgaris.cpp.o.provides

CMakeFiles/garis.dir/Followgaris.cpp.o.provides.build: CMakeFiles/garis.dir/Followgaris.cpp.o


# Object files for target garis
garis_OBJECTS = \
"CMakeFiles/garis.dir/Followgaris.cpp.o"

# External object files for target garis
garis_EXTERNAL_OBJECTS =

garis: CMakeFiles/garis.dir/Followgaris.cpp.o
garis: CMakeFiles/garis.dir/build.make
garis: /usr/local/lib/libopencv_shape.so.3.2.0
garis: /usr/local/lib/libopencv_stitching.so.3.2.0
garis: /usr/local/lib/libopencv_superres.so.3.2.0
garis: /usr/local/lib/libopencv_videostab.so.3.2.0
garis: /usr/local/lib/libopencv_objdetect.so.3.2.0
garis: /usr/local/lib/libopencv_calib3d.so.3.2.0
garis: /usr/local/lib/libopencv_features2d.so.3.2.0
garis: /usr/local/lib/libopencv_flann.so.3.2.0
garis: /usr/local/lib/libopencv_highgui.so.3.2.0
garis: /usr/local/lib/libopencv_ml.so.3.2.0
garis: /usr/local/lib/libopencv_photo.so.3.2.0
garis: /usr/local/lib/libopencv_video.so.3.2.0
garis: /usr/local/lib/libopencv_videoio.so.3.2.0
garis: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
garis: /usr/local/lib/libopencv_imgproc.so.3.2.0
garis: /usr/local/lib/libopencv_core.so.3.2.0
garis: CMakeFiles/garis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/SRG/Followgaris/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable garis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/garis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/garis.dir/build: garis

.PHONY : CMakeFiles/garis.dir/build

CMakeFiles/garis.dir/requires: CMakeFiles/garis.dir/Followgaris.cpp.o.requires

.PHONY : CMakeFiles/garis.dir/requires

CMakeFiles/garis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/garis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/garis.dir/clean

CMakeFiles/garis.dir/depend:
	cd /home/pi/SRG/Followgaris && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/SRG/Followgaris /home/pi/SRG/Followgaris /home/pi/SRG/Followgaris /home/pi/SRG/Followgaris /home/pi/SRG/Followgaris/CMakeFiles/garis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/garis.dir/depend

