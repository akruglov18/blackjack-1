project(players)

add_library(players STATIC ConsolePlayer.cpp ConsolePlayer.h AmericanDealer.cpp AmericanDealer.h Soft17Bot.cpp Soft17Bot.h)

target_include_directories(players PUBLIC .)

target_link_libraries(players cards)
target_link_libraries(players basics)