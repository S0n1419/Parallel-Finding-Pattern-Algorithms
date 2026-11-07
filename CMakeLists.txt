cmake_minimum_required(VERSION 3.15)

# Tên dự án
project(ParallelPatternMatching LANGUAGES CXX)

# Thiết lập chuẩn C++17 (hoặc C++20 nếu cần)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm thư mục chứa header
include_directories(include)

# Định nghĩa file thực thi từ file source
add_executable(app_test source/main.cpp)