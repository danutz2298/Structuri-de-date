#include <stdio.h>
#include <stdlib.h>

// Structura listei
struct Node{
    int data;
    struct Node* next;
};

// Functie ce adauga un node in lista
void push_li(struct Node** head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if(!new_node){
        printf("Memory Error");
    }

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

// Functie ce afiseaza lista
 void afiseaza_li(struct Node* n){
    if(n == NULL){
        printf("Lista este goala!\n");
        return;
    }
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

void suma_elemente(struct Node* n){
    int suma = 0;
    while(n){
        suma += n->data;
        n=n->next;
    }
    printf("Suma elementelor listei este:%d\n",suma);
}

int main(){
    struct Node* lista1 = NULL;

    // Punem elemente in lista 1
    push_li(&lista1, 10);
    push_li(&lista1, 120);
    push_li(&lista1, 40);

    suma_elemente(lista1);
}