// Program ce creeaza o lista dubla circulara pe ambele sensuri
#include <stdio.h>
#include <stdlib.h>

// Structura lista dublu inlantuita
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

// Functie ce adauga in lista un element nou
void push_ldcas(struct node **head,int data){
    struct node *new_node, *ptr,*frst;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(*head == NULL){
        new_node->prev = new_node;
        new_node->data = data;
        new_node->next = new_node;
        *head = new_node;
    }else{
        ptr = *head;
        frst = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        new_node->data = data;

        new_node->prev = ptr;
        new_node->next = frst;
        frst->prev = new_node;
        ptr->next = new_node;
        *head = new_node;
    }
}

void afiseaza_ldcas(struct node *head){
    if(head == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }

    struct node *ptr,*first,*last;
    ptr = head;
    first = head;
   
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr->next != head);
    // Afiseaza ultimul element din lista
    if(ptr->prev != ptr && ptr->next == head){
       printf("%d ", ptr->data);
    }
}

void inversare_ldcas_copiere(struct node **lista1, struct node **lista2){
    struct node *ptr, *ptr1;
    ptr = *lista1;
    ptr1 = *lista2;
    
    while(ptr->next != *lista1){
        push_ldcas(lista2,ptr->data);
        ptr = ptr->next;
    }
    if(ptr->next == *lista1){
        push_ldcas(lista2,ptr->data);
    }
}

int main(){
   struct node *lista1= NULL; // prima lista
    struct node *lista2 = NULL; // a 2 a lista
    push_ldcas(&lista1,3);
    push_ldcas(&lista1,4);
    push_ldcas(&lista1,45);
    
    printf("Elementele liste sunt:\n");
    afiseaza_ldcas(lista1);
    printf("\nElementele inversate ale liste sunt:\n");
    inversare_ldcas_copiere(&lista1,&lista2);
    afiseaza_ldcas(lista2);
    printf("\n");
}