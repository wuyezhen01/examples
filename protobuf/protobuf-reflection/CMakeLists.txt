
#
cmake_minimum_required (VERSION 3.0)

project ("pbreflect")

include_directories("../../3rdparty/protobuf-3.15.5/src")

# Add source to this project's executable.
add_executable (pbreflect "main.cpp" "msg_api.h" "msg_api.cpp" "message.pb.h" "message.pb.cc")

if (MSVC)
  #set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  target_link_libraries(pbreflect "../../3rdparty/protobuf-3.15.5/dist/libprotobuf.lib")
endif()
