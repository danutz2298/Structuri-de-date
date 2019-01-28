// Program ce creeaza 2 liste duble circulara pe ambele sensuri si le concateneaza pe loc
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

void remove_node_ldcas(struct node **head, int value){
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

void concatenare_ldcas(struct node **header_1, struct node **header_2){
 // Verifica daca listele sunt goale
    if(header_1 == NULL || header_2 == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }
   struct node *first_l1,*first_l2,*last_l1,*last_l2;

   first_l1 = *header_1; 
   first_l2 = *header_2;
   last_l1 = first_l1;
   last_l2 = first_l2;

   // Parcurgere lista 1
   while(last_l1->next != first_l1){
       last_l1 = last_l1->next;
   }

   // parcurgere lista 2
   while(last_l2->next != first_l2){
       last_l2 = last_l2->next;
   }
  
    // Schimbam adresele nodurilor
    first_l1->prev = last_l2;
    first_l2->prev = last_l1;
    last_l1->next = first_l2;
    last_l2->next = first_l1;
}

int main(){
    struct node *lista1 = NULL; // creeeaza lista 1
    struct node *lista2 = NULL;

    // Adauga elemente in lista 1
    push_ldcas(&lista1,35);
    push_ldcas(&lista1,45);
    push_ldcas(&lista1,42);


    // Adauga elemente in lsita 2
    push_ldcas(&lista2, 31);
    push_ldcas(&lista2,13);
    push_ldcas(&lista2,3);

    concatenare_ldcas(&lista1,&lista2);
    printf("Elementele liste dupa concatenare sunt:");
    afiseaza_ldcas(lista1);
    printf("\n");
}