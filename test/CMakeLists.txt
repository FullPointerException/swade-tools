include_directories(${swade_SOURCE_DIR}/src)
add_executable(swadetest testmain.cpp)
target_link_libraries(swadetest swadecore)
add_test(NAME swadetest COMMAND swadetest)