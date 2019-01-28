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

void sterge_nod_ldcas(struct node **head, int value){
   if(*head == NULL)
        return;

    struct node *curr = *head, *prev_1 = NULL;
    while(curr->data != value){
        if(curr->next == *head){
            printf("elementul %d nu se afla in lisa",value);
            return;
        }
        prev_1 = curr;
        curr = curr->next;
    }
    // Verifica daca exista doar un singur nod in lista
    if(curr->next == *head && prev_1 == NULL){
        (*head) = NULL;
        free(curr);
        return;
    }

    // Daca lista are mai mult de un nod
    // Verifica daca este primul nod
    if(curr == *head){
        prev_1 = (*head)->prev;
        *head = (*head)->next;

        prev_1->next=*head;
        (*head)->prev = prev_1;
        free(curr);
    }else if(curr->next == *head){ // daca este ultimul nod din lista
        prev_1->next = *head;
        (*head)->prev = prev_1;
        free(curr);
    }else{
        struct node *temp = curr->next;
        prev_1->next=temp;
        temp->prev=prev_1;
        free(curr);
    }
}

void sterge_pozitive(struct node** head){
    struct node *current_node;
    current_node = *head;

    while(current_node->next != *head){
        if(current_node->data > 0){
            sterge_nod_ldcas(head, current_node->data);
        }
        current_node = current_node->next;
    }

    if(current_node->next == *head){
        if(current_node->data > 0){
            sterge_nod_ldcas(head, current_node->data);
        }
    }
}

int main(){
    struct node *head = NULL;

    // Adauga elemente in lista
    push_ldcas(&head,35);
    push_ldcas(&head,45);
    push_ldcas(&head,42);
    push_ldcas(&head,-42);
    push_ldcas(&head,-2);
    push_ldcas(&head,0);

    printf("Elementele listei dupa stergerea celor pozitive:");
    sterge_pozitive(&head);
    afiseaza_ldcas(head);
    printf("\n");
}