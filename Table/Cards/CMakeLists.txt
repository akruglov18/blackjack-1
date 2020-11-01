project(cards)

add_library(cards Card.h Card.cpp CardShoe.cpp CardShoe.h Hand.cpp Hand.h)

target_include_directories(cards PUBLIC .)