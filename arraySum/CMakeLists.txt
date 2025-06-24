cmake_minimum_required(VERSION 3.10)

project(OpenACC_VectorAdd CXX)

# Set the compiler to nvc++
set(CMAKE_CXX_COMPILER nvc++)

# Set OpenACC flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -acc -Minfo=accel")

# Define the target name
set(TARGET_NAME vector_sum)

# Create the executable
add_executable(${TARGET_NAME} main.cpp)
