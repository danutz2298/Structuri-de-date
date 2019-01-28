// Program ce concateneaza 2 liste dublu inlantuite
#include <stdio.h>
#include <stdlib.h>

struct lista{
    int data;
    struct lista *prev, *next;
};

void initializareLista(struct lista *list){
    list->prev = NULL;
    list->next = NULL;
}

void push(struct lista **head,int data){
    struct lista *new_node, *ptr;
    
    if(*head == NULL){
        new_node = (struct lista*)malloc(sizeof(struct lista));
        new_node->prev = NULL;
        new_node ->data = data;
        new_node->next = NULL;
        *head = new_node;
    }else{
        ptr = *head;
        new_node = (struct lista*)malloc(sizeof(struct lista));
        new_node->data = data;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
    }
}

void afiseazaLista(struct lista *head){
    if(head == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }

    struct lista *ptr;
    ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
}

void concatenare(struct lista **header_1, struct lista **header_2){
    // Verifica daca listele sunt goale
    if(header_1 == NULL || header_2 == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }
    struct lista *ptr = *header_1;
    struct lista *ptr1 = *header_2;

    while(ptr->next != NULL){
        ptr= ptr->next;
    }
    
    if(ptr->next == NULL){
        ptr->next = ptr1;
        ptr1->prev = ptr;
    }
    *header_2 = NULL;
}

void inverseaza_ldi(struct lista** head){
   struct lista* temp = NULL;
   struct lista* current = *head;

    // parcurgem lista
   while(current != NULL){
       // creeam un nou pointer next
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
   }
   if(temp != NULL)
        *head = temp->prev;
}

int main(){
    struct lista *header1 = NULL; // prima lista
    struct lista *header2 = NULL; // a 2 a lista

    // Initializam prima lista, inseram date in ea
    push(&header1, 5);
    push(&header1, 15);
    push(&header1, 25);
    inverseaza_ldi(&header1);
    afiseazaLista(header1);
    printf("\n");
}