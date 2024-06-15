cmake_minimum_required(VERSION 3.21)
project(vulkan_grid VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(Vulkan REQUIRED)

add_subdirectory(external/glfw)

include_directories(
    external/glfw/include
)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp" "src/*.c" "src/*.h" "src/**/*.cpp" "src/**/*.c" "src/**/*.hpp" "src/**/*.h")

message(STATUS "Adding Source(s) to executable: ${SOURCES}")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)
