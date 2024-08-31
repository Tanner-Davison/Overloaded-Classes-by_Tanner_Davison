cmake_minimum_required(VERSION 3.29)
project(Overloaded_Classes_by_Tanner_Davison)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_executable Class_Overloading_by_Tanner_Davison/main.cpp
        Class_Overloading_by_Tanner_Davison/stdafx.h
        Class_Overloading_by_Tanner_Davison/ArrayList.cpp
        Class_Overloading_by_Tanner_Davison/Enemies.cpp
        Class_Overloading_by_Tanner_Davison/Entity.cpp
        Class_Overloading_by_Tanner_Davison/main.cpp
        Class_Overloading_by_Tanner_Davison/Vector2D.cpp
        Class_Overloading_by_Tanner_Davison/Vector3D.cpp
        Class_Overloading_by_Tanner_Davison/Family.cpp
        Class_Overloading_by_Tanner_Davison/Family.h
)

target_precompile_headers(my_executable PRIVATE Class_Overloading_by_Tanner_Davison/stdafx.h)