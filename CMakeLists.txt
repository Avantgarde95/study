cmake_minimum_required(VERSION 3.8)
project(cpp-practice)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

function(ADD_TARGET name)
    add_executable(${name} ${name}.cpp)
endfunction()

ADD_TARGET(SmartPointers)
ADD_TARGET(VirtualFunction)
ADD_TARGET(VirtualDestructor)
ADD_TARGET(Tree)
ADD_TARGET(WeakPointer)
ADD_TARGET(Container)
ADD_TARGET(Template)

if (MSVC)
    ADD_TARGET(Registry)
    add_executable(IPCClient IPC/IPCClient.cpp)
    add_executable(IPCServer WIN32 IPC/IPCServer.cpp)
endif ()
