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

// Functie ce afiseaza lista
 void afiseaza_li(struct Node* n){
    if(n == NULL){
        printf("Lista este goala!\n");
        return;
    }
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}
void valori_Interval(struct Node *n,struct Node **newList, int a, int b){
    struct Node *ptr;

    ptr = n;

    while(ptr->next != NULL){
        if(ptr->data >= a && ptr->data <= b){
            push_li(newList,ptr->data);
        }
        ptr = ptr->next;
    }
    // Verifica ultimul element
    if(ptr->data >= a && ptr->data <= b){
            push_li(newList,ptr->data);
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* newList = NULL;

    // Punem elemente in lista
    push_li(&head, 10);
    push_li(&head, 120);
    push_li(&head, 40);

    // Apelam functia pentru intervalul [2,40]
    valori_Interval(head,&newList,2,40);

    printf("Valorile aflate in intervalul dat sunt:");
    afiseaza_li(newList);  // Apelam functia de afisare
    printf("\n");
}