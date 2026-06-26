#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


node* new_node(size_t value)
{
    node* nn = malloc(sizeof(node));
    if (!nn) return NULL;

    nn->value = value;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

void add_node(node* root, size_t value)
{
    node* node = new_node(value);
    if (!root || !node || root->value == node->value) return;

    if (root->value < node->value)
    {
        if (root->right == NULL)
        {
            root->right = node;
            return;
        }
        add_node(root->right, node);
        return;
    }
    if (root->left == NULL)
    {
        root->left = node;
        return;
    }
    add_node(root->left, node);
}

node* get_node(node* root, size_t value)
{
    if (!root) return NULL;

    if (root->value == value) return root;

    if (root->value < value)
    {
        return get_node(root->right, value);
    }
    return get_node(root->left, value);
}

void print_tree_pretty(node* root, char* prefix, bool is_left)
{
    if (!root) return;

    printf("%s", prefix);
    printf("%s", is_left ? "├── " : "└── ");
    printf("%zu\n", root->value);

    char new_prefix[256]; 
    
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

    if (root->left && root->right) {
        print_tree_pretty(root->left, new_prefix, true);
        print_tree_pretty(root->right, new_prefix, false);
    } else if (root->left) {
        print_tree_pretty(root->left, new_prefix, false);
    } else if (root->right) {
        print_tree_pretty(root->right, new_prefix, false);
    }
}

void print_tree(node* root)
{
    if (!root) return;
    
    printf("%zu\n", root->value);
    
    if (root->left && root->right) {
        print_tree_pretty(root->left, "", true);
        print_tree_pretty(root->right, "", false);
    } else if (root->left) {
        print_tree_pretty(root->left, "", false);
    } else if (root->right) {
        print_tree_pretty(root->right, "", false);
    }
}

size_t get_size(node* root)
{
    if (!root) return 0;

    return (get_size(root->right) + get_size(root->left)) + 1;
}

size_t get_height(node* root)
{
    if (!root) return 0;

    size_t left = get_height(root->left);
    size_t right = get_height(root->right);

    return (left < right ? right : left) + 1;
}

void delete_tree(node* root)
{
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}


void fprint_postorder(FILE* file, node* root)
{
    if (!root || !file) return;

    fprint_postorder(file, root->left);
    fprint_postorder(file, root->right);
    fprintf(file, "%zu|", root->value);
}

void fprint_preorder(FILE* file, node* root)
{
    if (!root || !file) return;

    fprintf(file, "%zu|", root->value);
    fprint_preorder(file, root->left);
    fprint_preorder(file, root->right);
}

void fprint_inorder(FILE* file, node* root)
{
    if (!root || !file) return;

    fprint_inorder(file, root->left);
    fprintf(file, "%zu|", root->value);
    fprint_inorder(file, root->right);
}


void print_postorder(node* root)
{
    if (!root) return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%zu  ", root->value);
}

void print_preorder(node* root)
{
    if (!root) return;

    printf("%zu  ", root->value);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node* root)
{
    if (!root) return;

    print_inorder(root->left);
    printf("%zu  ", root->value);
    print_inorder(root->right);
}

bool contains_node(node* root, size_t value)
{
    return get_node(root, value) != NULL;
}

node* min_node(node* root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

node* remove_node(node* root, size_t value)
{
    if (!root) return NULL;
    if (root->value < value)
    {
        root->right = remove_node(root->right, value);
        return root;
    }
    if (root->value > value)
    {
        root->left = remove_node(root->left, value);
        return root;
    }

    if (!root->left && !root->right)
    {
        free(root);
        return NULL;
    }
    if (root->left && !root->right)
    {
        node* temp = root->left;
        free(root);
        return temp;
    }
    if (root->right && !root->left)
    {
        node* temp = root->right;
        free(root);
        return temp;
    }

    node* temp = min_node(root->right);
    root->value = temp->value;
    root->right = remove_node(root->right, temp->value);
    
    return root;
}
