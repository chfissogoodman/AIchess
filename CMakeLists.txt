cmake_minimum_required(VERSION 3.26)
project(chessforMInggw)

set(CMAKE_CXX_STANDARD 17)

link_libraries(libeasyx.a)
include_directories(./include)
aux_source_directory(./src SRC_LIST)
add_executable(
        main ${SRC_LIST}
)

