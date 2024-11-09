cmake_minimum_required(VERSION 3.16)
project(Gregory VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.ui)

qt_add_executable(Gregory
    ${SOURCES}
)

target_include_directories(Gregory PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Gregory PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)

set_target_properties(Gregory PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

enable_testing()

add_executable( TestEvent src/Event.cpp test/test_Event.cpp )
add_test( NAME Event COMMAND TestEvent )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)