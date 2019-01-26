// Program ce elimina dintr-o lista inlantuita simpla cheile pozitive,negative sau nule
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structura lista
struct Node{
    int data;
    struct Node* next;
};

// Functie ce adauga un element in lista
void push(struct Node** head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if(!new_node){
        printf("Memory Error");
    }

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

// Functie ce sterge un nod din lista
void stergeNod(struct Node** head,int value){
    struct Node *current_node, *prev_node;
    current_node = *head;

    while(current_node->data != value && current_node->next != NULL){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->data == value){
        if(current_node == *head){
            *head = current_node->next;
            free(current_node);
        }else{
            prev_node->next = current_node->next;
            free(current_node);
        }
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
}

// Functie ce sterge elementele pozitive din lista
void stergeElementePozitive(struct Node **head){
    struct Node *current_node;
    current_node = *head;
    while(current_node->next != NULL){
        if(current_node->data > 0){
            stergeNod(head,current_node->data);
        }
        current_node = current_node->next;
    }
    if(current_node->data > 0){
            stergeNod(head,current_node->data);
    }
}

// Functie ce sterge elementele negative din lista 
void stergeElementeNegative(struct Node **head){
    struct Node *current_node;
    current_node = *head;
    while(current_node->next != NULL){
        if(current_node->data < 0){
            stergeNod(head,current_node->data);
        }
        current_node = current_node->next;
    }
    if(current_node->data < 0){
            stergeNod(head,current_node->data);
    }
}

// Functie ce sterge elementele nule din lista
void stergeElementeNule(struct Node **head){
    struct Node *current_node;
    current_node = *head;
    while(current_node->next != NULL){
        if(current_node->data == 0){
            stergeNod(head,current_node->data);
        }
        current_node = current_node->next;
    }
    if(current_node->data == 0){
            stergeNod(head,current_node->data);
    }
}
void displayList(struct Node* n){
    if(n == NULL){
        printf("Lista este goala!\n");
        return;
    }

    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

int main(){
    struct Node* head = NULL;
    // Adauga elemente in lista
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, -30);
    push(&head, 0);
    stergeElementePozitive(&head);
    stergeElementeNegative(&head);
    stergeElementeNule(&head);
    displayList(head);
}