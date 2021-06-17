# cpp-practice

Simple codes for my C++ study

### How to build

- Linux, WSL
  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```
- Windows
  - You can use Visual Studio to open the folder as a CMake project.

### Examples

- SmartPointers: Usage & reference counting of the smart pointers (`std::shared_ptr`, `std::unique_ptr`)
- VirtualFunction: Comparison of virtual function & non-virtual function
- VirtualDestructor: Comparison of virtual destructor & non-virtual destructor
- Tree: Creating a simple tree using the smart pointer
- WeakPointer: Using the weak pointer to avoid the memory leak in the circular references
- IPC: Sending the simple data using Windows IPC & copydata
  - Run IPCServer first
  - While IPCServer is running, run IPCClient and press Enter.
- Container: Some experiments using the containers (ex. Storing the smart pointers in `std::map`)
- Template: Fun applications of template.
  - Compile-time computation
  - CRTP (Curiously Recurring Template Pattern)
