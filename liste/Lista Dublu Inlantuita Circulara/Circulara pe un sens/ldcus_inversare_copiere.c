// Program ce creeaza o lista dublu inlantuita circulara pe un sens si sterge elemente din ea
#include <stdio.h>
#include <stdlib.h>

// Structura lista dublu inlantuita
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

// Functie ce adauga in lista un element nou
void push_ldcus(struct node **head,int data){
    struct node *new_node, *ptr,*frst;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(*head == NULL){
        new_node->prev = NULL;
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

        new_node->prev = NULL;
        new_node->next = frst;
        frst->prev = new_node;
        ptr->next = new_node;
        *head = new_node;
    }
}

void afiseaza_ldcus(struct node *head){
    if(head == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }

    struct node *ptr;
    ptr = head;

    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr->next != head);
    if(ptr->prev != NULL && ptr->next == head){
       printf("%d ", ptr->data);
    }
}

void inversare_ldcus_copiere(struct node **lista1, struct node **lista2){
    struct node *ptr, *ptr1;
    ptr = *lista1;
    ptr1 = *lista2;
    
    while(ptr->next != *lista1){
        push_ldcus(lista2,ptr->data);
        ptr = ptr->next;
    }
    if(ptr->next == *lista1){
        push_ldcus(lista2,ptr->data);
    }
}

int main(){
    struct node *lista1 = NULL; // pointer catre primul nod din lista
    struct node *lista2 = NULL; // pointer catre primul nod din lista
    // Adaugam elemente in lista
    push_ldcus(&lista1,3);
    push_ldcus(&lista1,4);
    push_ldcus(&lista1,45);

    printf("Lista neinversata este: ");
    afiseaza_ldcus(lista1);
    printf("\nLista inversata este: ");
    inversare_ldcus_copiere(&lista1,&lista2);
    afiseaza_ldcus(lista2);
    printf("\n");
}