// Program ce afiseaza sterge un element dintr-o lista simplu inlantuita circulara
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

// Functie ce sterge un nod cu o valoarea data din lista
void sterge_nod_lic(struct node** head, int value){
    struct node *current_node, *prev_node,*ptr;

    current_node = *head;
    ptr = current_node;

    if(current_node->data == value && current_node == *head){
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        *head = current_node->next;
        ptr->next = *head;
        free(current_node);               
        return;
    }

    while(current_node->data != value && current_node->next != *head){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->data == value){
        if(current_node->next == *head){
            prev_node->next = current_node->next;
            free(current_node);
            return;
        }else{
            prev_node->next = current_node->next;
            free(current_node);
            return;
        }
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
}

int main(){
    struct node *head = NULL;

    // Adaugam elemente in lista
    push_lic(&head,43);
    push_lic(&head,33);
    push_lic(&head,23);

    // Stergem elemente din lista
    sterge_nod_lic(&head,43);
    sterge_nod_lic(&head,23);
    printf("lista dupa stergere:");
    afiseaza_lic(head);
    printf("\n");
}