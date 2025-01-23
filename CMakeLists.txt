cmake_minimum_required(VERSION 3.11)
project(timeline)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 5.5)
set(CMAKE_CXX_STANDARD 17)

# download raylib
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    endif()
endif()

# generate embedded resource file
file(GLOB resource_files "res/*")
set(embedded_resource_file ${CMAKE_BINARY_DIR}/embedded_resources.cpp)
# file(WRITE ${embedded_resource_file} "struct Resource { const unsigned char *data; unsigned size; };\n\nnamespace Resources {\n")
file(WRITE ${embedded_resource_file} "#include \"resources.hpp\"\n\nnamespace resources {\n")
foreach(resource_file ${resource_files})
    get_filename_component(resource_name ${resource_file} NAME_WE)
    file(READ ${resource_file} resource_data HEX)
    string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1," resource_data ${resource_data})
    file(APPEND ${embedded_resource_file} "    constexpr unsigned char __${resource_name}_data[] = {${resource_data}};\n    const resource ${resource_name} = {__${resource_name}_data, sizeof(__${resource_name}_data)};\n")
endforeach()
file(APPEND ${embedded_resource_file} "}")

# build project
file(GLOB_RECURSE source_files "src/*.cpp")
add_executable(${PROJECT_NAME} ${source_files} ${embedded_resource_file})
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PRIVATE src lib/raylib)

# setup for different platforms
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
