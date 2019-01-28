// Program pentru aflarea lungimii si maximului unei stive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definim 2 variabile globale pentru a retine maximul si lungimea stivei
int maxim_stiva = 0;
int lungime_stiva = 0;

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
}

// Functie ce afiseaza elementele unei stive
void afisareStiva(struct Stack* n){
    if(n == NULL){
        printf("stiva goala");
        return;
    }
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

// Functie ce sterge un element din stiva
int pop(struct Stack** root){
    // Verifica daca stiva este goala
    if(isEmpty(*root)){
        return 0;
    }

    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Functie ce foloseste recursivitatea pentru aflarea maximului
void maximStiva(struct Stack **root){
    int element;
     if(isEmpty(*root)){
        return;
    }else{
        element = pop(root);
        lungime_stiva++;
        if(element > maxim_stiva){
            maxim_stiva = element;
        }
        maximStiva(root);
        push(root,element);
    }
}

int main(){
    struct Stack *root = NULL;

    //Adaugam elemente in stiva
    push(&root, 90);
    push(&root, 10);
    push(&root, 24);
    push(&root, 2);
    push(&root, 80);

    maximStiva(&root);
    printf("Valoare maxima din stiva este: %d\n", maxim_stiva);
    printf("Lungimea stivei este: %d", lungime_stiva);
    printf("\n");
}   