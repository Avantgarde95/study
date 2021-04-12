cmake_minimum_required(VERSION 3.8)
project(cpp-practice)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

function(ADD_TARGET name)
    add_executable(${name} ${name}.cpp)
endfunction()

ADD_TARGET(SmartPointers)
ADD_TARGET(VirtualFunction)
ADD_TARGET(VirtualDestructor)
ADD_TARGET(Tree)
ADD_TARGET(WeakPointer)

if (MSVC)
    ADD_TARGET(Registry)
endif ()
