set(LIBRARY_NAME engine)

find_package(Vulkan REQUIRED)

add_library(${LIBRARY_NAME}
    engine.hpp
    devices/window.cpp
    devices/window.hpp
    graphics/graphics.cpp
    graphics/graphics.hpp
    graphics/instance.cpp
    graphics/instance.hpp
    graphics/physical_device.cpp
    graphics/physical_device.hpp
    graphics/surface.cpp
    graphics/surface.hpp
)

include_directories(
    external/glfw/include
)

message(STATUS "vulkan include dir: ${Vulkan_INCLUDE_DIR}")

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Vulkan_INCLUDE_DIR})

target_link_libraries(${LIBRARY_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)
