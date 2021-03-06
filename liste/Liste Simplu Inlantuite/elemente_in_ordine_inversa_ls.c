// Afisare elemente in ordinca inversa dintr-o lista simplu inlantuita
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

void inverseazaLs(struct Node** head){
   struct Node* result = NULL;
   struct Node* current = *head;

    // parcurgem lista
   while(current != NULL){
       // creeam un nou pointer next
       struct Node* next = current->next;
       current->next = result;
       result = current;
       current = next;
   }
   *head = result;
}

int main(){
    struct Node* head = NULL;
    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);

    printf("Lista in ordine inversa este:");
    inverseazaLs(&head);
    afiseaza_li(head);  // Apelam functia de afisare
    printf("\n");
}