// Program ce elimina dintr-o lista inlantuita simpla cheile pozitive,negative sau nule
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definirea structurii lista circulara
struct node{
    int data;
    struct node *next;
};

// Adauga nod nou la inceputul listei
void push(struct node **head, int data){
    struct node *new_node, *ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    ptr = *head;

    if(*head == NULL){
        new_node->next = new_node;
        *head = new_node;
    }else{
        new_node->next = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        
        ptr->next = new_node;
        *head = new_node;
    }
}

// Functie ce sterge un nod din lista
void rmv_node(struct node **head, int value){
    struct node *ptr,*prev;
    ptr = *head;

    while(ptr->data != value && ptr->next != *head){
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr->data == value){
        prev = ptr->next;
        if(ptr == *head){
            prev = ptr->next;
            while(ptr->next != *head){
                ptr = ptr->next;
            }
            
            if(ptr->next == *head){
                ptr->next = prev;
                free(*head);
                *head = prev;
            }
        }else{
            prev->next = ptr->next;
            free(ptr);
        }   
    }
}

// Functie ce afiseaza elementele listei
void display_list(struct node *head){
    struct node *ptr;
    ptr = head;
    if (head == NULL){
        printf("list este goala");
    }
    ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){
    struct node* head = NULL;
    // Adauga elemente in lista
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    
    display_list(head);
}