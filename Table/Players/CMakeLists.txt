project(players)

add_library(players STATIC IPlayer.cpp IPlayer.h Dealer.cpp Dealer.h)

target_include_directories(players PUBLIC .)

target_link_libraries(players cards)