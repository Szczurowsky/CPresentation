cmake_minimum_required(VERSION 3.16)
project(CPresentation)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPresentation main.cpp utils/console.cpp utils/console.h Slide.cpp Slide.h utils/config_parser.cpp utils/config_parser.h utils/slides_parser.cpp utils/slides_parser.h)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(CPresentation ${CURSES_LIBRARIES})
endif()
