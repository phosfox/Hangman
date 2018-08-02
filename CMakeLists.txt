cmake_minimum_required(VERSION 3.12)
project(Hangman C)

set(CMAKE_C_STANDARD 99)

add_executable(Hangman main.c dictionary.h)