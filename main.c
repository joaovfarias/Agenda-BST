/*

Implementar uma agenda (nome, idade, telefone) que armazena os dados numa árvore binária de busca
(usuário escolhe qual dado é o fator de precedência). A agenda deve permitir incluir, buscar, remover 
e imprimir toda a árvore usando pré-ordem, central e pós-ordem.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[20];
    int idade;
    int telefone;
} info;

typedef struct treeNode{
    info pessoa;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

void insertByAge(treeNode **root, char *nome, int age, int phone);
void printTree(treeNode *root);
treeNode *createElement(char *nome, int age, int phone);
void searchElement(treeNode *root, int age);


int main(){

    treeNode *myTree = NULL;

    insertByAge(&myTree, "joao", 25, 984);
    insertByAge(&myTree, "andirea", 50, 984);
    insertByAge(&myTree, "lairssa", 19, 984);
    insertByAge(&myTree, "luiza", 18, 984);

    printTree(myTree);
    printf("-----------------\n");
    searchElement(myTree, 18);
}

treeNode *createElement(char *nome, int age, int phone){

    treeNode *tmp = malloc(sizeof(treeNode));
    tmp->pessoa.idade = age;
    strcpy(tmp->pessoa.nome, nome);
    tmp->pessoa.telefone = phone;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;

}

void insertByAge(treeNode **root, char *nome, int age, int phone){

    if (*root == NULL){
        *root = createElement(nome, age, phone);
        return;
    }

    if ((*root)->pessoa.idade == age){
        printf("Idades iguais detectada, nao foi possivel a inserção");
        return;
    }

    if (age < (*root)->pessoa.idade){
        insertByAge(&((*root)->left), nome, age, phone);
    }
    else{
        insertByAge(&((*root)->right), nome, age, phone);
    }
}

void printTree(treeNode *root){

    if (root != NULL){
        printf("\n");

        printf("Nome: %s | ", root->pessoa.nome);
        printf("Idade: %d |", root->pessoa.idade);
        printf("Telefone: %d |", root->pessoa.telefone);
        printTree(root->left);
        printTree(root->right);
    }
}

void searchElement(treeNode *root, int age){

    if (root == NULL){
        printf("Not Found");
        return;
    }

    if (root->pessoa.idade == age){
        printf("Nome: %s | ", root->pessoa.nome);
        printf("Idade: %d |", root->pessoa.idade);
        printf("Telefone: %d |", root->pessoa.telefone);
        return;
    }

    if (age < root->pessoa.idade){
        searchElement(root->left, age);
    }
    else{
        searchElement(root->right, age);
    }
}