# CMakeList.txt : CMake project for purecpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0)

project ("purecpp")

# Add source to this project's executable.
add_executable (purecpp "main.cpp" "protocol.h" "protocol.cpp")

# TODO: Add tests and install targets if needed.
