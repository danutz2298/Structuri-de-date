// Program ce creeaza o lista dublu inlantuita circulara pe un sens si o afiseaza
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

void concatenare_ldcus(struct node **header_1, struct node **header_2){
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

   last_l1->next = first_l2;
   first_l2->prev = last_l1;
   last_l2->next = first_l1;
}

int main(){
    struct node *lista_1 = NULL; // pointer catre primul nod din lista 1
    struct node *lista_2 = NULL; // pointer catre primul nod din lista 2

    // Adaugam elemente in lista 1
    push_ldcus(&lista_1,3);
    push_ldcus(&lista_1,4);
    push_ldcus(&lista_1,45);
    
    // Adaugam elemente in lista 2
    push_ldcus(&lista_2,13);
    push_ldcus(&lista_2,43);
    push_ldcus(&lista_2,4);

    concatenare_ldcus(&lista_1,&lista_2);
    printf("elementele listei sunt:");
    afiseaza_ldcus(lista_1); // lista_1 contine si elementele din lista_2
    printf("\n");
}