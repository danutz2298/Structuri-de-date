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

void valori_Interval(struct Stack *n,struct Stack **newList, int a, int b){
    struct Stack *ptr;

    ptr = n;

    while(ptr->next != NULL){
        if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
        }
        ptr = ptr->next;
    }
    // Verifica ultimul element
    if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
    }
}


// Functie ce afiseaza elementele unei stive
void afisareStiva(struct Stack* n){
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

int main(){
    struct Stack *root = NULL;
    struct Stack *newList = NULL;
    push(&root, 10); // adauga element in stiva
    push(&root, 24);
    push(&root, 2);
    push(&root, 80);

    valori_Interval(root,&newList,2,40); // intervalul [2,40]
    printf("Valorile din intervalul dat sunt:");
    afisareStiva(newList); // afiseaza valorile din intervalul dat
}