cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp RungeKutta.cpp RungeKutta.h ODESystem.h Projectile.cpp Projectile.h Helper.cpp Helper.h Environment.cpp Environment.h EnvironmentException.cpp EnvironmentException.h)