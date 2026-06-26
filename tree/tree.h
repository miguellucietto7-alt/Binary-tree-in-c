#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node
{
    size_t value;
    struct node* left;
    struct node* right;
} node;

/* Criação */
node* new_node(size_t value);

/* Inserção */
void add_node(node* root, size_t value);

/* Função auxiliar da inserção (uso interno) */
void add_node_impl(node* root, node* node);

/* Busca */
node* get_node(node* root, size_t value);
bool contains_node(node* root, size_t value);

/* Informações da árvore */
size_t get_size(node* root);
size_t get_height(node* root);

/* Menor e maior elemento */
node* min_node(node* root);
node* max_node(node* root);

/* Remoção */
node* remove_node(node* root, size_t value);

/* Destruição */
void delete_tree(node* root);

/* Impressão da árvore */
void print_tree(node* root);

/* Percursos */
void print_preorder(node* root);
void print_inorder(node* root);
void print_postorder(node* root);

/* Percursos para arquivo */
void fprint_preorder(FILE* file, node* root);
void fprint_inorder(FILE* file, node* root);
void fprint_postorder(FILE* file, node* root);

#endif /* TREE_H */
