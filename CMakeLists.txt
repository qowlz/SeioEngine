cmake_minimum_required(VERSION 3.5.0)
project(Seio VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp

    # GL classes
    src/GL/VertexArrayObject.cpp
    src/GL/VertexBufferObject.cpp
    src/GL/Shader.cpp

    # glad
    vendor/glad/src/glad.c

    # imgui
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_demo.cpp
    vendor/imgui/backends/imgui_impl_glfw.cpp
    vendor/imgui/backends/imgui_impl_opengl3.cpp
    vendor/imgui/misc/cpp/imgui_stdlib.cpp

    # stb_image
    vendor/stb/stb_image.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# include glad
target_include_directories(${PROJECT_NAME} PRIVATE vendor/glad/include)

# include imgui
target_include_directories(${PROJECT_NAME} PRIVATE vendor/imgui)
target_include_directories(${PROJECT_NAME} PRIVATE vendor/imgui/backends)
target_include_directories(${PROJECT_NAME} PRIVATE vendor/imgui/misc/cpp)

# link glfw
add_subdirectory(vendor/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

# include stb_image
target_include_directories(${PROJECT_NAME} PRIVATE vendor/stb)

#include glm
target_include_directories(${PROJECT_NAME} PRIVATE vendor/glm)

#include src headers
target_include_directories(${PROJECT_NAME} PRIVATE src)