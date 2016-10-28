# CMake generated Testfile for 
# Source directory: /home/dumitru/httpserver
# Build directory: /home/dumitru/httpserver
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test1 "httpserver_test")
subdirs(ext/gtest)
