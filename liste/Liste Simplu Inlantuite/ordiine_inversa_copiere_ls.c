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

void inversare_lista(struct Node **lista1, struct Node **lista2){
    struct Node *ptr, *ptr1;
    ptr = *lista1;
    ptr1 = *lista2;

    while(ptr->next != NULL){
        push_li(lista2,ptr->data);
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        push_li(lista2,ptr->data);
    }
}

int main(){
    struct Node* lista1 = NULL;
    struct Node* lista2 = NULL;
    // Punem elemente in lista
    push_li(&lista1, 10);
    push_li(&lista1, 120);
    push_li(&lista1, 40);

    printf("\nLista este: ");
    afiseaza_li(lista1);
    inversare_lista(&lista1,&lista2);
    printf("\nLista inversata este: ");
    afiseaza_li(lista2);  // Apelam functia de afisare
    printf("\n");
}