cmake_minimum_required(VERSION 3.24)

project(project1 LANGUAGES CXX C)

add_executable(project1 src/main.cc)
target_include_directories(project1 PUBLIC include deps/elements/lib/include)
target_link_libraries(project1 elements)

add_subdirectory(deps)