# CLAUDE.md

## Project Overview

This is an interview preparation repository containing implementations of common data structures and algorithms in **C++** and **Python**.

## Repository Structure

```
Interview/
├── bst.cpp               # Binary Search Tree (insert, search, traversals)
├── double_link.cpp       # Doubly Linked List implementation
├── hash.cpp / hash.h     # Hash table implementation
├── link.cpp              # Singly Linked List with various operations
├── palindrome.cpp        # Palindrome detection using linked list
├── replace-whitespace.cpp# String: replace whitespace in-place
├── rotate.cpp            # Array/string rotation
├── morse_code.py         # Morse code encoder/decoder (Python)
├── Interview/
│   ├── compressstr.cpp   # String compression (run-length encoding)
│   └── linklist/
│       └── link.cpp      # Linked list variant
└── *.pdf                 # Reference problem sets (BinaryTrees, LinkedList)
```

## Build & Run

### C++ files

Compile with g++:

```bash
g++ -o out <file>.cpp
./out
```

Example:
```bash
g++ -o bst bst.cpp && ./bst
g++ -o link link.cpp && ./link
```

### Python files

```bash
python3 morse_code.py
```

## Topics Covered

| Topic | File(s) |
|---|---|
| Binary Search Tree | `bst.cpp` |
| Singly Linked List | `link.cpp`, `Interview/linklist/link.cpp` |
| Doubly Linked List | `double_link.cpp` |
| Hash Table | `hash.cpp`, `hash.h` |
| String Compression | `Interview/compressstr.cpp` |
| Palindrome (linked list) | `palindrome.cpp` |
| String Manipulation | `replace-whitespace.cpp`, `rotate.cpp` |
| Morse Code (tree/trie) | `morse_code.py` |

## Code Style

- C++ files use `#include<iostream>` and `using namespace std;`
- Structs are used for node definitions (not classes)
- No external dependencies or build system — plain single-file compilation
- Python code uses Python 3 class-based style

## Notes for Claude

- All source files are self-contained; there are no project-wide build scripts
- `hash.h` is a shared header included by `hash.cpp`, `link.cpp`, and `palindrome.cpp`
- The `Interview/` subdirectory contains earlier/alternate versions of some implementations
- `a.out` files are compiled artifacts and can be ignored
- When adding new implementations, follow the existing single-file, no-dependency pattern
