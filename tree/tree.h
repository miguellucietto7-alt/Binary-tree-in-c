#ifndef TREE_H
#define TREE_H

#include <stdio.h>

typedef struct node node;
typedef struct node {
    size_t value;

    node* right;
    node* left;
}node;



#endif