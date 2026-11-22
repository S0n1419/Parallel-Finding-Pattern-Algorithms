cmake_minimum_required(VERSION 3.16)
project(Parallel-Finding-Pattern-Algorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(OpenMP REQUIRED)

function(add_app name)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/source/${name}.cpp)
    add_executable(${name} source/${name}.cpp)
    target_link_libraries(${name} PRIVATE OpenMP::OpenMP_CXX)
  endif()
endfunction()

add_app(main)
add_app(dot_product)
add_app(pattern_search)