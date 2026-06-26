# Binary Tree in C

A comprehensive implementation of binary tree data structures in C for educational purposes.

## Overview

This repository contains implementations of various binary tree operations and algorithms, including:
- Binary Search Trees (BST)
- Tree traversal methods
- Node insertion and deletion
- Tree balancing operations

## Features

- **Easy to understand** - Well-commented code suitable for learning
- **Complete implementation** - Core operations and common algorithms
- **Educational focus** - Great for students learning data structures

## Getting Started

### Prerequisites
- GCC compiler or compatible C compiler
- Make (optional)

### Compilation

```bash
gcc -o binary_tree *.c -lm
```

Or if using Make:

```bash
make
```

### Running the Program

```bash
./binary_tree
```

## Project Structure

```
.
├── README.md
├── main.c           # Entry point and demo code
├── tree.c           # Tree implementation
├── tree.h           # Tree header file
└── Makefile         # Build configuration
```

## Usage Example

```c
#include "tree.h"

int main() {
    BinaryTree *tree = create_tree();
    
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    
    inorder_traversal(tree);
    
    free_tree(tree);
    return 0;
}
```

## Operations

### Insertion
Add new nodes to the tree while maintaining structure.

### Deletion
Remove nodes from the tree with proper restructuring.

### Traversal
Explore the tree in different orders:
- **In-order** - Left, Root, Right
- **Pre-order** - Root, Left, Right
- **Post-order** - Left, Right, Root

## Learning Resources

For more information about binary trees, refer to:
- [GeeksforGeeks - Binary Tree](https://www.geeksforgeeks.org/binary-tree-data-structure/)
- [MIT OpenCourseWare - Data Structures](https://ocw.mit.edu/)

## License

This project is open source and available for educational use.

## Contributing

Feel free to fork this repository and submit pull requests with improvements or fixes!

## Author

Created by [miguellucietto7-alt](https://github.com/miguellucietto7-alt) for educational purposes.
