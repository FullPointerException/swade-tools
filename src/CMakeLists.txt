file(GLOB SOURCES *.cpp)
list(REMOVE_ITEM SOURCES main.cpp)

add_library(swadecore ${SOURCES})
add_executable(swade main.cpp)
target_link_libraries(swade swadecore)