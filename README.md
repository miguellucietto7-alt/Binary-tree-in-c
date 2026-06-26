
Uma implementação completa de Árvore Binária de Busca (BST) em C com suporte a operações essenciais e percursos em diferentes ordens.

## 📋 Overview

Este repositório contém uma implementação educacional de Árvore Binária de Busca em C, incluindo:
- Criação e manipulação de nós
- Inserção e remoção de elementos
- Busca e consulta de informações
- Cálculo de altura e tamanho da árvore
- Múltiplas formas de percurso (In-order, Pre-order, Post-order)
- Exportação de dados para arquivo
- Visualização formatada da árvore

## ✨ Características

- **Valores inteiros sem sinal** - Usa `size_t` para armazenar valores
- **Estrutura BST** - Mantém automaticamente a propriedade de Árvore Binária de Busca
- **Código bem documentado** - Ideal para aprendizado
- **Múltiplas operações** - Cobertura completa de operações de árvore

## 🚀 Como Usar

### Pré-requisitos
- Compilador GCC ou compatível
- Make (opcional)

### Compilação

```bash
gcc -o binary_tree tree/tree.c main.c -lm
Ou usando Makefile (se disponível):

bash
make
Estrutura do Projeto
Code
.
├── README.md
├── tree/
│   ├── tree.h          # Definições e protótipos das funções
│   └── tree.c          # Implementação das operações da árvore
└── main.c              # Programa principal com exemplos
📚 Operações Disponíveis
1. Criação de Nós
C
node* new_node(size_t value);
Cria um novo nó com o valor especificado.

2. Inserção
C
void add_node(node* root, size_t value);
void add_node_impl(node* root, node* node);
add_node() - Insere um valor (cria o nó automaticamente)
add_node_impl() - Função auxiliar para inserção de nós já criados
Não permite valores duplicados
3. Busca
C
node* get_node(node* root, size_t value);
bool contains_node(node* root, size_t value);
get_node() - Retorna o ponteiro para o nó com o valor especificado
contains_node() - Verifica se um valor existe na árvore
4. Informações da Árvore
C
size_t get_size(node* root);
size_t get_height(node* root);
get_size() - Retorna a quantidade total de nós
get_height() - Retorna a altura da árvore (profundidade máxima + 1)
5. Valores Extremos
C
node* min_node(node* root);
node* max_node(node* root);
min_node() - Encontra o nó com menor valor
max_node() - Encontra o nó com maior valor
6. Remoção
C
node* remove_node(node* root, size_t value);
Remove um nó com o valor especificado, mantendo a estrutura de BST:

Se o nó é folha, remove diretamente
Se tem um filho, substitui o nó por seu filho
Se tem dois filhos, substitui pelo menor valor da subárvore direita
7. Percursos
Impressão em Console
C
void print_preorder(node* root);   // Raiz, Esquerda, Direita
void print_inorder(node* root);    // Esquerda, Raiz, Direita
void print_postorder(node* root);  // Esquerda, Direita, Raiz
Exportação para Arquivo
C
void fprint_preorder(FILE* file, node* root);
void fprint_inorder(FILE* file, node* root);
void fprint_postorder(FILE* file, node* root);
Escreve os valores separados por |

8. Visualização
C
void print_tree(node* root);
Imprime a árvore de forma formatada com estrutura visual usando caracteres ASCII.

9. Limpeza
C
void delete_tree(node* root);
Libera toda a memória alocada para a árvore (percurso pós-ordem).

💡 Exemplo de Uso
C
#include "tree/tree.h"

int main() {
    // Criar raiz
    node* root = new_node(50);
    
    // Inserir valores
    add_node(root, 30);
    add_node(root, 70);
    add_node(root, 20);
    add_node(root, 40);
    add_node(root, 60);
    add_node(root, 80);
    
    // Visualizar árvore
    printf("Árvore:\n");
    print_tree(root);
    
    // Informações
    printf("\nTamanho: %zu\n", get_size(root));
    printf("Altura: %zu\n", get_height(root));
    
    // Percursos
    printf("\nIn-order: ");
    print_inorder(root);
    printf("\n");
    
    printf("Pre-order: ");
    print_preorder(root);
    printf("\n");
    
    printf("Post-order: ");
    print_postorder(root);
    printf("\n");
    
    // Busca
    if (contains_node(root, 40)) {
        printf("Valor 40 encontrado!\n");
    }
    
    // Remover nó
    root = remove_node(root, 30);
    
    printf("\nApos remover 30:\n");
    print_tree(root);
    
    // Liberar memória
    delete_tree(root);
    
    return 0;
}
📊 Tipos de Dados
C
typedef struct node {
    size_t value;      // Valor armazenado
    struct node* left; // Ponteiro para filho esquerdo
    struct node* right;// Ponteiro para filho direito
} node;
🎓 Conceitos Aprendidos
Este projeto permite aprender:

Estrutura de dados de árvore binária
Propriedades de BST (Binary Search Tree)
Manipulação de ponteiros em C
Alocação e liberação dinâmica de memória
Algoritmos recursivos
Percursos em profundidade (DFS)
📈 Complexidade
Operação	Melhor Caso	Caso Médio	Pior Caso
Busca	O(1)	O(log n)	O(n)
Inserção	O(log n)	O(log n)	O(n)
Remoção	O(log n)	O(log n)	O(n)
Altura	O(n)	O(n)	O(n)
Tamanho	O(n)	O(n)	O(n)
Nota: Casos piores ocorrem quando a árvore fica degenerada (lista encadeada).
📝 Licença
Este projeto é código aberto e disponível para uso educacional.

🤝 Contribuindo
Sinta-se livre para fazer fork deste repositório e enviar pull requests com melhorias, correções de bugs ou novas funcionalidades!

👤 Autor
Criado por miguellucietto7-alt para fins educacionais.
