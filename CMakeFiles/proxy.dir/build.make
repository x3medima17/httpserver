# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/dumitru/httpserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dumitru/httpserver

# Include any dependencies generated for this target.
include CMakeFiles/proxy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proxy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proxy.dir/flags.make

CMakeFiles/proxy.dir/src/HttpApplication.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpApplication.cpp.o: src/HttpApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proxy.dir/src/HttpApplication.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpApplication.cpp.o -c /home/dumitru/httpserver/src/HttpApplication.cpp

CMakeFiles/proxy.dir/src/HttpApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpApplication.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpApplication.cpp > CMakeFiles/proxy.dir/src/HttpApplication.cpp.i

CMakeFiles/proxy.dir/src/HttpApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpApplication.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpApplication.cpp -o CMakeFiles/proxy.dir/src/HttpApplication.cpp.s

CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpApplication.cpp.o


CMakeFiles/proxy.dir/src/HttpServer.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpServer.cpp.o: src/HttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proxy.dir/src/HttpServer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpServer.cpp.o -c /home/dumitru/httpserver/src/HttpServer.cpp

CMakeFiles/proxy.dir/src/HttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpServer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpServer.cpp > CMakeFiles/proxy.dir/src/HttpServer.cpp.i

CMakeFiles/proxy.dir/src/HttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpServer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpServer.cpp -o CMakeFiles/proxy.dir/src/HttpServer.cpp.s

CMakeFiles/proxy.dir/src/HttpServer.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpServer.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpServer.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpServer.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpServer.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpServer.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpServer.cpp.o


CMakeFiles/proxy.dir/src/HttpResponse.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpResponse.cpp.o: src/HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proxy.dir/src/HttpResponse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpResponse.cpp.o -c /home/dumitru/httpserver/src/HttpResponse.cpp

CMakeFiles/proxy.dir/src/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpResponse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpResponse.cpp > CMakeFiles/proxy.dir/src/HttpResponse.cpp.i

CMakeFiles/proxy.dir/src/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpResponse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpResponse.cpp -o CMakeFiles/proxy.dir/src/HttpResponse.cpp.s

CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpResponse.cpp.o


CMakeFiles/proxy.dir/src/Logger.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/Logger.cpp.o: src/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/proxy.dir/src/Logger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/Logger.cpp.o -c /home/dumitru/httpserver/src/Logger.cpp

CMakeFiles/proxy.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/Logger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/Logger.cpp > CMakeFiles/proxy.dir/src/Logger.cpp.i

CMakeFiles/proxy.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/Logger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/Logger.cpp -o CMakeFiles/proxy.dir/src/Logger.cpp.s

CMakeFiles/proxy.dir/src/Logger.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/Logger.cpp.o.requires

CMakeFiles/proxy.dir/src/Logger.cpp.o.provides: CMakeFiles/proxy.dir/src/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/Logger.cpp.o.provides

CMakeFiles/proxy.dir/src/Logger.cpp.o.provides.build: CMakeFiles/proxy.dir/src/Logger.cpp.o


CMakeFiles/proxy.dir/src/HttpMessage.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpMessage.cpp.o: src/HttpMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/proxy.dir/src/HttpMessage.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpMessage.cpp.o -c /home/dumitru/httpserver/src/HttpMessage.cpp

CMakeFiles/proxy.dir/src/HttpMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpMessage.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpMessage.cpp > CMakeFiles/proxy.dir/src/HttpMessage.cpp.i

CMakeFiles/proxy.dir/src/HttpMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpMessage.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpMessage.cpp -o CMakeFiles/proxy.dir/src/HttpMessage.cpp.s

CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpMessage.cpp.o


CMakeFiles/proxy.dir/src/socket.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/socket.cpp.o: src/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/proxy.dir/src/socket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/socket.cpp.o -c /home/dumitru/httpserver/src/socket.cpp

CMakeFiles/proxy.dir/src/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/socket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/socket.cpp > CMakeFiles/proxy.dir/src/socket.cpp.i

CMakeFiles/proxy.dir/src/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/socket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/socket.cpp -o CMakeFiles/proxy.dir/src/socket.cpp.s

CMakeFiles/proxy.dir/src/socket.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/socket.cpp.o.requires

CMakeFiles/proxy.dir/src/socket.cpp.o.provides: CMakeFiles/proxy.dir/src/socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/socket.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/socket.cpp.o.provides

CMakeFiles/proxy.dir/src/socket.cpp.o.provides.build: CMakeFiles/proxy.dir/src/socket.cpp.o


CMakeFiles/proxy.dir/src/HttpClient.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpClient.cpp.o: src/HttpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/proxy.dir/src/HttpClient.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpClient.cpp.o -c /home/dumitru/httpserver/src/HttpClient.cpp

CMakeFiles/proxy.dir/src/HttpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpClient.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpClient.cpp > CMakeFiles/proxy.dir/src/HttpClient.cpp.i

CMakeFiles/proxy.dir/src/HttpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpClient.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpClient.cpp -o CMakeFiles/proxy.dir/src/HttpClient.cpp.s

CMakeFiles/proxy.dir/src/HttpClient.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpClient.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpClient.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpClient.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpClient.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpClient.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpClient.cpp.o


CMakeFiles/proxy.dir/src/RequestHandler.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/RequestHandler.cpp.o: src/RequestHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/proxy.dir/src/RequestHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/RequestHandler.cpp.o -c /home/dumitru/httpserver/src/RequestHandler.cpp

CMakeFiles/proxy.dir/src/RequestHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/RequestHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/RequestHandler.cpp > CMakeFiles/proxy.dir/src/RequestHandler.cpp.i

CMakeFiles/proxy.dir/src/RequestHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/RequestHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/RequestHandler.cpp -o CMakeFiles/proxy.dir/src/RequestHandler.cpp.s

CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.requires

CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.provides: CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.provides

CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.provides.build: CMakeFiles/proxy.dir/src/RequestHandler.cpp.o


CMakeFiles/proxy.dir/src/HttpRequest.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/src/HttpRequest.cpp.o: src/HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/proxy.dir/src/HttpRequest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/src/HttpRequest.cpp.o -c /home/dumitru/httpserver/src/HttpRequest.cpp

CMakeFiles/proxy.dir/src/HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/src/HttpRequest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/src/HttpRequest.cpp > CMakeFiles/proxy.dir/src/HttpRequest.cpp.i

CMakeFiles/proxy.dir/src/HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/src/HttpRequest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/src/HttpRequest.cpp -o CMakeFiles/proxy.dir/src/HttpRequest.cpp.s

CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.requires

CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.provides: CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.provides

CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.provides.build: CMakeFiles/proxy.dir/src/HttpRequest.cpp.o


CMakeFiles/proxy.dir/proxy.cpp.o: CMakeFiles/proxy.dir/flags.make
CMakeFiles/proxy.dir/proxy.cpp.o: proxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/proxy.dir/proxy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/proxy.cpp.o -c /home/dumitru/httpserver/proxy.cpp

CMakeFiles/proxy.dir/proxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/proxy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dumitru/httpserver/proxy.cpp > CMakeFiles/proxy.dir/proxy.cpp.i

CMakeFiles/proxy.dir/proxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/proxy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dumitru/httpserver/proxy.cpp -o CMakeFiles/proxy.dir/proxy.cpp.s

CMakeFiles/proxy.dir/proxy.cpp.o.requires:

.PHONY : CMakeFiles/proxy.dir/proxy.cpp.o.requires

CMakeFiles/proxy.dir/proxy.cpp.o.provides: CMakeFiles/proxy.dir/proxy.cpp.o.requires
	$(MAKE) -f CMakeFiles/proxy.dir/build.make CMakeFiles/proxy.dir/proxy.cpp.o.provides.build
.PHONY : CMakeFiles/proxy.dir/proxy.cpp.o.provides

CMakeFiles/proxy.dir/proxy.cpp.o.provides.build: CMakeFiles/proxy.dir/proxy.cpp.o


# Object files for target proxy
proxy_OBJECTS = \
"CMakeFiles/proxy.dir/src/HttpApplication.cpp.o" \
"CMakeFiles/proxy.dir/src/HttpServer.cpp.o" \
"CMakeFiles/proxy.dir/src/HttpResponse.cpp.o" \
"CMakeFiles/proxy.dir/src/Logger.cpp.o" \
"CMakeFiles/proxy.dir/src/HttpMessage.cpp.o" \
"CMakeFiles/proxy.dir/src/socket.cpp.o" \
"CMakeFiles/proxy.dir/src/HttpClient.cpp.o" \
"CMakeFiles/proxy.dir/src/RequestHandler.cpp.o" \
"CMakeFiles/proxy.dir/src/HttpRequest.cpp.o" \
"CMakeFiles/proxy.dir/proxy.cpp.o"

# External object files for target proxy
proxy_EXTERNAL_OBJECTS =

proxy: CMakeFiles/proxy.dir/src/HttpApplication.cpp.o
proxy: CMakeFiles/proxy.dir/src/HttpServer.cpp.o
proxy: CMakeFiles/proxy.dir/src/HttpResponse.cpp.o
proxy: CMakeFiles/proxy.dir/src/Logger.cpp.o
proxy: CMakeFiles/proxy.dir/src/HttpMessage.cpp.o
proxy: CMakeFiles/proxy.dir/src/socket.cpp.o
proxy: CMakeFiles/proxy.dir/src/HttpClient.cpp.o
proxy: CMakeFiles/proxy.dir/src/RequestHandler.cpp.o
proxy: CMakeFiles/proxy.dir/src/HttpRequest.cpp.o
proxy: CMakeFiles/proxy.dir/proxy.cpp.o
proxy: CMakeFiles/proxy.dir/build.make
proxy: CMakeFiles/proxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dumitru/httpserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable proxy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proxy.dir/build: proxy

.PHONY : CMakeFiles/proxy.dir/build

CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpApplication.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpServer.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpResponse.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/Logger.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpMessage.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/socket.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpClient.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/RequestHandler.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/src/HttpRequest.cpp.o.requires
CMakeFiles/proxy.dir/requires: CMakeFiles/proxy.dir/proxy.cpp.o.requires

.PHONY : CMakeFiles/proxy.dir/requires

CMakeFiles/proxy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proxy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proxy.dir/clean

CMakeFiles/proxy.dir/depend:
	cd /home/dumitru/httpserver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dumitru/httpserver /home/dumitru/httpserver /home/dumitru/httpserver /home/dumitru/httpserver /home/dumitru/httpserver/CMakeFiles/proxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proxy.dir/depend
