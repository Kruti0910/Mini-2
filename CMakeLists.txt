cmake_minimum_required(VERSION 3.10)
project(Mini2_Project)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)

# Include Protobuf and gRPC libraries from vcpkg
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# Add the C++ directory which contains all servers
add_subdirectory(C++)
