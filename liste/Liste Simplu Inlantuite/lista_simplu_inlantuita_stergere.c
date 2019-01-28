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

// Functie ce sterge un nod cu o valoarea data din lista
void sterge_nod_li(struct Node** head, int value){
    struct Node *current_node, *prev_node,*ptr;

    current_node = *head;

    if (current_node != NULL && current_node->data == value) 
    { 
        *head = current_node->next;
        free(current_node);               
        return; 
    } 

    while(current_node->data != value && current_node->next != NULL){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->data == value){
        prev_node->next = current_node->next;
        free(current_node);
        return;
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
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

int main(){
    struct Node* head = NULL;
    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);

    // Stergem nodul 10
    sterge_nod_li(&head,10);

    afiseaza_li(head);  // Apelam functia de afisare
    printf("\n");
}