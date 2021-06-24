cmake_minimum_required(VERSION 3.16)

project(swade
    VERSION 0.0.1
    DESCRIPTION "Tools to use when planning a SWADE campaign"
    HOMEPAGE_URL "https://github.com/fullpointerexception/swade-tools")

add_compile_options(-Wall -Werror -Wpedantic -std=c++14)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)