cmake_minimum_required(VERSION 3.10)
project(Mini2_Project)

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

add_executable(serverA A/serverA.cpp)
target_link_libraries(serverA PRIVATE grpc++ protobuf)

add_executable(serverB B/serverB.cpp)
target_link_libraries(serverB PRIVATE grpc++ protobuf)

add_executable(serverC C/serverC.cpp)
target_link_libraries(serverC PRIVATE grpc++ protobuf)

add_executable(serverD D/serverD.cpp)
target_link_libraries(serverD PRIVATE grpc++ protobuf)

add_executable(serverE E/serverE.cpp)
target_link_libraries(serverE PRIVATE grpc++ protobuf)
