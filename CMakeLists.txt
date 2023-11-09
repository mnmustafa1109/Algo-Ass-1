cmake_minimum_required(VERSION 3.26)
project(Algo_Ass_1)

set(CMAKE_CXX_STANDARD 23)

# Copy the data folder from the root directory to the binary directory
add_custom_target(copy_data_directory
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data
    ${CMAKE_BINARY_DIR}/data
)

# Add your executable and make it depend on the custom target
add_executable(Algo_Ass_1 main.cpp Sorter.cxx Passenger.hxx Parser.hxx Sorter.hxx MaxHeap.hxx)

# Make the executable depend on the custom target, so data folder is copied before building the executable
add_dependencies(Algo_Ass_1 copy_data_directory)
