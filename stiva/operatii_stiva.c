#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structura de reprezentare a unei stive o lista inlantuita
struct Stack{
    int data;
    struct Stack *next;
};

// Functie ce creaza un nod nou in stiva
struct Stack* newNode(int data){
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
    node->data = data;
    node->next = NULL;

    return node;
}

// Verifica daca stiva este goala
int isEmpty(struct Stack* root){
    return !root;
}

void push(struct Stack** root, int data){
    struct Stack* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d a fost adaugat in stiva\n", data);
}


// Functie ce sterge un element din stiva
int pop(struct Stack** root){
    if(isEmpty(*root)){
        return INT_MIN;
    }

    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Functie ce returneaza capul stivei
int peek(struct Stack* root){
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main(){
    struct Stack* root = NULL;
    push(&root, 10);
    push(&root, 24);
    push(&root, 2);

    printf("%d a fost sters din stiva\n", pop(&root));
    printf("Primul element este %d\n", peek(root));
}