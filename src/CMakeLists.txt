add_library(swadecore Stub.cpp)
add_executable(swade main.cpp)
target_link_libraries(swade swadecore)