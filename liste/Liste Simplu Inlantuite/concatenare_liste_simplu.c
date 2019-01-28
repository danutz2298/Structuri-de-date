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

void concatenare_lista(struct Node** lista1, struct Node** lista2){
    struct Node *ptr,*ptr1;

    ptr = *lista1;
    ptr1 = *lista2;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        ptr->next = ptr1; // Schimba adresa ultimului element din lista 1
                          // din NULL o sa devina prima adresa din lista 2
    }

}

int main(){
    // Pointeri catre primul element al listei
    struct Node* lista1 = NULL;
    struct Node* lista2 = NULL;

    // Punem elemente in lista 1
    push_li(&lista1, 10);
    push_li(&lista1, 120);
    push_li(&lista1, 40);

    // Punem elemente in lista 2
    push_li(&lista2, 32);
    push_li(&lista2, 11);
    push_li(&lista2, 44);

    concatenare_lista(&lista1,&lista2);
    printf("Lista concatenata este:");
    afiseaza_li(lista1);
    printf("\n");

}