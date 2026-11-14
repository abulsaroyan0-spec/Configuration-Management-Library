# Library Management System

A console-based C++17 library management application.

## Features

- Register and remove books, magazines, and digital books.
- Find publications by ID.
- Borrow and return physical publications.
- Search by title or publication year.
- Display library statistics.
- Validate invalid operations with exceptions.

## Architecture

- `Publication`: abstract base class.
- `PhysicalPublication`: shared borrowing behavior for physical items.
- `Book`, `Magazine`, `DigitalBook`: concrete publication types.
- `PublicationFactory`: centralized, extensible object creation.
- `SearchStrategy`: interchangeable title/year search strategies.
- `Library`: owns publications using `std::unique_ptr`.
- `ConsoleApp`: console interface, separated from library logic.

## Build

```bash
cmake -S . -B build
cmake --build build
./build/library
```

Alternatively:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src/*.cpp -o library
./library
```

## Notes

- Publication IDs must be unique.
- Digital books are always accessible and cannot be borrowed or returned.
- Search by title is case-sensitive.
