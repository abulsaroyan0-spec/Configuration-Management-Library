cmake_minimum_required(VERSION 3.16)

project(LibraryManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(library
    src/main.cpp
    src/ConsoleApp.cpp
    src/Publication.cpp
    src/PhysicalPublication.cpp
    src/Book.cpp
    src/Magazine.cpp
    src/DigitalBook.cpp
    src/PublicationFactory.cpp
    src/SearchStrategy.cpp
    src/Library.cpp
)

target_include_directories(library PRIVATE include)

if (MSVC)
    target_compile_options(library PRIVATE /W4)
else()
    target_compile_options(library PRIVATE -Wall -Wextra -Wpedantic)
endif()
