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

int main(){
    struct node *head = NULL;
    push_ldcas(&head,3);
    push_ldcas(&head,4);
    push_ldcas(&head,45);

    printf("Elementele liste sunt:");
    afiseaza_ldcas(head);
    printf("\n");
}