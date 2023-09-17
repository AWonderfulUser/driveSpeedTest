# Minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Project name and description
project(driveSpeedTest CXX)

# Add source files
add_executable(drivespeedtest src/main.cpp)

# Set C++ standard (optional)
target_compile_features(drivespeedtest PRIVATE cxx_std_11)

target_include_directories(drivespeedtest PRIVATE include/)