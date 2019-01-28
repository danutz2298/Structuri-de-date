// Program ce creeaza o lista dublu inlantuita circulara pe un sens si sterge elementele neutre
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

// Functie ce sterge primul nod din lista din lista
void remove_front_ldCus(struct node **head){
    struct node *first,*ptr,*ptr2;
    ptr = *head;
    first = *head;
    ptr2 = ptr->next;

    // Daca lista este goala
    if(ptr->prev == NULL && ptr->next == NULL){
            *head = NULL;
            return;
    }

    if(first->prev == NULL){
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = first->next;
        ptr2->prev = NULL;
        *head = first->next;
        free(first);
    }
}

// Functie ce sterge un nod din lista
void sterge_nod_ldcus(struct node **head, int value){
    struct node *ptr,*ptr2,*ptr3;
    ptr = *head;
    ptr2 = ptr;
    ptr3 = ptr2;

    if(ptr->data == value){
        if(ptr->prev == NULL && ptr->next == ptr){
            free(ptr);
            *head = NULL;
            return;
        }
    }

    while(ptr->data != value && ptr->next != *head){
            ptr2 = ptr;
            ptr = ptr->next;
            ptr3 = ptr->next;;
    }

    if(ptr->data == value){
        if(ptr->prev == NULL){
            remove_front_ldCus(head);
        }else if(ptr->next == ptr){

        }else{
            ptr2->next = ptr3;
            ptr3->prev = ptr2;
            free(ptr);
        }
    }
}

void sterge_nule(struct node** head){
    struct node *current_node;
    current_node = *head;

    while(current_node->next != *head){
        if(current_node->data == 0){
            sterge_nod_ldcus(head, current_node->data);
        }
        current_node = current_node->next;
    }

    if(current_node->next == *head){
        if(current_node->data == 0){
            sterge_nod_ldcus(head, current_node->data);
        }
    }
}

int main(){
    struct node *head = NULL; // pointer catre primul nod din lista

    // Adaugam elemente in lista
    push_ldcus(&head,3);
    push_ldcus(&head,4);
    push_ldcus(&head,45);
    push_ldcus(&head,-45);
    push_ldcus(&head,-15);
    push_ldcus(&head,0);

    printf("elementele listei dupa stergere celor nule sunt:");
    sterge_nule(&head);
    afiseaza_ldcus(head);
    printf("\n");
}