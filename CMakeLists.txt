cmake_minimum_required(VERSION 3.11)

project(engine)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/Core
    ${PROJECT_SOURCE_DIR}/src/GameObject
    ${PROJECT_SOURCE_DIR}/src/GameObject/Button
    ${PROJECT_SOURCE_DIR}/src/GameObject/Entity
    ${PROJECT_SOURCE_DIR}/src/Renderer
)

file(GLOB SOURCES
    src/Core/Core.cpp
    src/GameObject/Button/AButton.cpp
    src/GameObject/Button/MenuButton.cpp
    src/GameObject/Entity/AEntity.cpp
    src/Renderer/Renderer.cpp
    src/main.cpp
)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_CPP_COMPILER "/usr/bin/g++")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-deprecated-copy")
endif (UNIX)
    
if (WIN32)
    set(SFML_DIR "./SFML_WIN32/lib/cmake/SFML")
endif (WIN32)

find_package(SFML 2 COMPONENTS graphics window system)
add_executable(${PROJECT_NAME} ${INCLUDE_DIRECTORIES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)