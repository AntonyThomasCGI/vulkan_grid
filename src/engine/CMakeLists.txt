set(LIBRARY_NAME engine)

find_package(Vulkan REQUIRED)

add_library(${LIBRARY_NAME}
    app.hpp
    app.cpp
    engine.cpp
    engine.hpp
    devices/window.cpp
    devices/window.hpp
    geometry/primitives/square.hpp
    geometry/mesh.cpp
    geometry/mesh.hpp
    geometry/vertex.hpp
    graphics/command_buffer.cpp
    graphics/command_buffer.hpp
    graphics/command_pool.cpp
    graphics/command_pool.hpp
    graphics/graphics.cpp
    graphics/graphics.hpp
    graphics/instance.cpp
    graphics/instance.hpp
    graphics/logical_device.cpp
    graphics/logical_device.hpp
    graphics/physical_device.cpp
    graphics/physical_device.hpp
    graphics/pipeline.cpp
    graphics/pipeline.hpp
    graphics/render_pass.cpp
    graphics/render_pass.hpp
    graphics/shader.cpp
    graphics/shader.hpp
    graphics/surface.cpp
    graphics/surface.hpp
    graphics/swap_chain.cpp
    graphics/swap_chain.hpp
)

include_directories(
    external/glfw/include
    external/rocket
)

message(STATUS "vulkan include dir: ${Vulkan_INCLUDE_DIR}")

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Vulkan_INCLUDE_DIR})

target_link_libraries(${LIBRARY_NAME} glfw glm ${GLFW_LIBRARIES} Vulkan::Vulkan)
