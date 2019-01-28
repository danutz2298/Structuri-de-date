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

// Functie ce sorteaza crescator lista simpla prin copiere
 void sort_asc_li(struct Node** head){
     struct Node *ptr1, *ptr2;
     int temp;
     ptr1 = *head;

     while(ptr1->next != NULL){
         ptr2=ptr1->next;
         while(ptr2 != NULL){
             if(ptr1->data > ptr2->data){
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
             }
             ptr2 = ptr2->next;
         }
         ptr1 = ptr1->next;
     }
 }

int main(){
    struct Node* head = NULL;
    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);
    
    // Apelam functia pentru sortarea listei
    sort_asc_li(&head);

    afiseaza_li(head);  // Apelam functia de afisare
    printf("\n");
}