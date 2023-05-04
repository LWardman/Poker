cmake_minimum_required(VERSION 3.24)
project(Cards)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cards main.cpp Card.h Deck.h Player.h Table.h)
