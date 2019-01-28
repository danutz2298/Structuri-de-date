// Program ce afiseaza o lista simplu inlantuita circulara
#include <stdio.h>
#include <stdlib.h>

// Definirea structurii lista circulara
struct node{
    int data;
    struct node *next;
};

// Adauga nod nou la inceputul listei
void push_lic(struct node **head, int data){
    struct node *new_node, *ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    ptr = *head;

    if(*head == NULL){
        new_node->next = new_node;
        *head = new_node;
        return;
    }else{
        new_node->next = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        *head = new_node;
    }
}

// Functie ce afiseaza elementele listei
void afiseaza_lic(struct node *head){
   struct node *ptr;
    ptr = head;
    if (head == NULL){
        printf("list este goala");
    }
    ptr = head;

    while(ptr->next != head){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    if(ptr->next == head){
        printf("%d ",ptr->data);
    }
}

int main(){
    struct node *head = NULL;
    push_lic(&head,43);
    push_lic(&head,33);

    afiseaza_lic(head);
}