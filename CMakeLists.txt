cmake_minimum_required(VERSION 3.24)
project(cache_SolicitarPagina C)

set(CMAKE_C_STANDARD 11)

add_executable(cache_SolicitarPagina main.c cache.h cache.c)
