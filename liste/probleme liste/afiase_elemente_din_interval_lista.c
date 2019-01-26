// Program ce afiseaza elementele aflate in intervalul [a,b] dintr-o lista inlantuita
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};


void push(struct Node** head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if(!new_node){
        printf("Memory Error");
    }

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

void displayList(struct Node* n){
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

void valori_Interval(struct Node *n,struct Node **newList, int a, int b){
    struct Node *ptr,*ptr1,*ptr2;

    ptr = n;

    while(ptr->next != NULL){
        if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
        }
        ptr = ptr->next;
    }
    // Verifica ultimul element
    if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* newList = NULL;
    push(&head,2);
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head,3);

    //printf("Valorile din lista: ");
    //displayList(head);
    valori_Interval(head,&newList,2,40);
    displayList(newList);
}