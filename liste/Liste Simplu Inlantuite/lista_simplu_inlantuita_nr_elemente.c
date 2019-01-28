// Program ce afiseaza numarul de noduri din lista
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
 void numar_noduri(struct Node* n){
     int noduri = 0;
    if(n == NULL){
        printf("Lista este goala!\n");
        return;
    }
    while(n){
        noduri++;
        
        n=n->next;
    }
    printf("Numarul elementelor in lista: %d\n", noduri);
}

int main(){
    struct Node* head = NULL;

    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);

    numar_noduri(head);
}