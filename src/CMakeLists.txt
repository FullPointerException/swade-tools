file(GLOB SOURCES ReplApp.cpp InputSanitizer.cpp)
add_library(swadecore ${SOURCES})
add_executable(swade main.cpp)
target_link_libraries(swade swadecore)