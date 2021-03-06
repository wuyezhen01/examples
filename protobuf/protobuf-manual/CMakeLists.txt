# CMakeList.txt : CMake project for pbman, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0)

project ("pbman")

include_directories("../../3rdparty/protobuf-3.15.5/src")

# Add source to this project's executable.
add_executable (pbman "main.cpp" "msg_api.h" "msg_api.cpp" "message.pb.h" "message.pb.cc")

if (MSVC)
  target_link_libraries(pbman "../../3rdparty/protobuf-3.15.5/dist/libprotobufd.lib")
endif()
