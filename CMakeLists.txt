cmake_minimum_required(VERSION 3.10)
project(OptionFuturesTrading)

set(CMAKE_CXX_STANDARD 11)

# Adjust the path to the location where you extracted libtorch
set(Torch_DIR "/Users/user/libtorch/share/cmake/Torch")

find_package(Torch REQUIRED)

add_executable(OptionFuturesTrading main.cpp)
target_link_libraries(OptionFuturesTrading "${TORCH_LIBRARIES}")
set_property(TARGET OptionFuturesTrading PROPERTY CXX_STANDARD 11)
