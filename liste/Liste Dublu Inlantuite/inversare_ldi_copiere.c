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
    new_node = (struct lista*)malloc(sizeof(struct lista));
    new_node ->data = data;
    if(*head == NULL){
        new_node->prev = NULL;
        new_node->next = NULL;
        *head = new_node;
    }else{
        ptr = *head;
        new_node->prev = NULL;
        new_node->next = ptr;
        *head = new_node;
    }
}

void afiseazaLista(struct lista *head){
    if(head == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }

    struct lista *ptr;
    ptr = head;

   do{
        printf("%d ", ptr->data);
        ptr= ptr->next;
    } while(ptr->next != NULL);

    if(ptr->next == NULL){
        printf("%d ", ptr->data);
    }
}

void inversare_ldi_copiere(struct lista **lista1, struct lista **lista2){
    struct lista *ptr, *ptr1;
    ptr = *lista1;
    ptr1 = *lista2;

    while(ptr->next != NULL){
        push(lista2,ptr->data);
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        push(lista2,ptr->data);
    }
}


int main(){
    struct lista *header1 = NULL; // prima lista
    struct lista *header2 = NULL; // a 2 a lista

    // Initializam prima lista, inseram date in ea
    
    push(&header1, 5);
    push(&header1, 15);
    push(&header1,53);

    printf("\nLista este: ");
    afiseazaLista(header1);

    printf("\nLista inversata este: ");
    inversare_ldi_copiere(&header1,&header2);
    afiseazaLista(header2);
    printf("\n");
}