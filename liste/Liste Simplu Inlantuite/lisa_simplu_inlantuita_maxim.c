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

void maxim_lista(struct Node* head){
    int maxim;
    struct Node *ptr;

    ptr = head;

    maxim = ptr->data;
    while(ptr->next != NULL){
        if(ptr->data > maxim){
            maxim = ptr->data;
        }  
        ptr = ptr->next;
    }

    if(ptr->next == NULL){
        if(ptr->data > maxim){
            maxim = ptr->data;
        }  
        printf("Maximul listei este %d\n",maxim);
    }
}

int main(){
    struct Node* head = NULL;

    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);

    maxim_lista(head);
}