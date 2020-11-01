project(table)

add_library(table Table.h Table.cpp)

target_include_directories(table PUBLIC .)

add_subdirectory(Cards)

target_link_libraries(table cards)