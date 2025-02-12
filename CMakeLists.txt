cmake_minimum_required(VERSION 3.5.0)
project(SeioEngine VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SeioEngine
    main.cpp

    # glad
    vendor/glad/src/glad.c
)

# include glad
target_include_directories(SeioEngine PRIVATE vendor/glad/include)

# link glfw
add_subdirectory(vendor/glfw)
target_link_libraries(SeioEngine glfw)
