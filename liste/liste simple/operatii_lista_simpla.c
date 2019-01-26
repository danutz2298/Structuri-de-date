#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};


/* Given a reference (pointer to pointer) to the head of a list
    and an int, inserts a new node of the front of the list. 
    C nu suporta transmiterea valorii prin referinta.
    */

void push(struct Node** head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if(!new_node){
        printf("Memory Error");
    }

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

void insert_front(struct Node** head){
    struct Node *new_node;
    int value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);

    // Aloca spatiu de memorie pentru noul nod
    new_node = (struct Node*) malloc(sizeof(struct Node));

    // Verifica daca s-a alocat spatiu de memorie pentru noul nod
    if(!new_node){
        printf("Memory Error");
    }

    new_node -> data = value;
    new_node -> next =*head;
    *head = new_node;
}

void insert_end(struct Node** head){
    struct Node *ptr, *new_node;
    int value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);

    // Aloca spatiu de memorie pentru noul nod
    new_node = (struct Node*) malloc(sizeof(struct Node));

    // Verifica daca s-a alocat spatiu de memorie pentru noul nod
    if(!new_node){
        printf("Memory Error");
    }
    new_node -> data = value;
    new_node -> next = NULL;

    ptr = *head;

    while(ptr-> next != NULL){
        ptr = ptr -> next;
    }
    ptr-> next = new_node;
}

void insert_before(struct Node** head){
    struct Node *current_node,*prev_node, *new_node;
    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);

    printf("\n Introduceti valoarea nodului inaintea caruia se doreste a fi inserat noul nod");
    scanf("%d", &node_value);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = value;
    
    current_node = *head;

    while(current_node -> data != node_value && current_node -> next != NULL)
    {
        prev_node = current_node;
        current_node = current_node -> next;
    }

    if(current_node -> data == node_value){
        prev_node -> next = new_node;
        new_node -> next = current_node;
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
}

void insert_after(struct Node** head){
    struct Node *prev_node, *current_node, *new_node;

    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);

    printf("\n Introduceti valoarea nodului dupa care se doreste a fi inserat noul nod");
    scanf("%d", &node_value);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = value;

    current_node = *head;
    prev_node = current_node;

    while(prev_node->data != node_value && prev_node -> next != NULL){
        prev_node = current_node;
        current_node = current_node -> next;
    }
    if(prev_node -> data == node_value){
        prev_node -> next = new_node;
        new_node -> next = current_node;
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
}

// Functie ce sterge un nod de la inceputul listei
void delete_begin(struct Node**head){
    struct Node *ptr;
    
    if(head != NULL){
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

// Functie ce sterge un nod de la sfarsitul listei
void delete_end(struct Node** head){
    struct Node *current_node,*prev_node;

    current_node = *head;

    while(current_node->next != NULL){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->next == NULL){
        prev_node->next = NULL;
        free(current_node);
    }
}

void delete_node(struct Node** head){
    struct Node *current_node, *prev_node;

    current_node = *head;

    int value,node_value;

    printf("\n Introdu valoarea nodului pentru stergere: ");
    scanf("%d", &value);

    while(current_node->data != value && current_node->next != NULL){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->data == value){
        prev_node->next = current_node->next;
        free(current_node);
    }else{
        printf("Valoarea nu a fost gasita!\n");
    }
}

// Sterge un nod inaintea altui nod
void delete_node_before(struct Node** head){
    struct Node *current_node, *prev_node, *prev_prev_node;
    int value;
    current_node = *head;
    prev_node = current_node;
    prev_prev_node = prev_node;

    printf("\n Introdu valoarea nodului inaintea caruie se va efectua stergerea: ");
    scanf("%d", &value);

    while(current_node->data != value && current_node->next != NULL){
        prev_prev_node = prev_node;
        prev_node = current_node;
        current_node = current_node->next; 
    }

   if(current_node->data == value){
       prev_prev_node->next = current_node;
       free(prev_node);
   }
}

// Sterge un node dupa un alt nod specificat
void delete_node_after(struct Node** head){
    struct Node *current_node, *prev_node, *prev_prev_node;
    int value;

    current_node = *head;
    prev_node = current_node;

    printf("\n Introdu valoarea nodului inaintea caruie se va efectua stergerea: ");
    scanf("%d", &value);

    while(prev_node->data != value && current_node->next != NULL){
        prev_node = current_node;
        current_node = current_node->next; 
    }

    if(prev_node->data == value){
        prev_node->next = current_node->next;
        free(current_node);
    }
}

// Sortare prin copiere
 void sort(struct Node** head){
     struct Node *ptr1, *ptr2;
     int temp;
     ptr1 = *head;

     while(ptr1->next != NULL){
         ptr2=ptr1->next;
         while(ptr2 != NULL){
             if(ptr1->data > ptr2->data){
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
             }
             ptr2 = ptr2->next;
         }
         ptr1 = ptr1->next;
     }
 }

void displayList(struct Node* n){
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

int main(){
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    printf("Valorile din lista: ");
    displayList(head);
    insert_front(&head);
    displayList(head);
    insert_end(&head);
    displayList(head);
    insert_before(&head);
    displayList(head);
    insert_after(&head);
    displayList(head);
    //printf("\nLista dupa stergerea primului nod:");
    //delete_begin(&head);
    //displayList(head);
    //printf("\nLista dupa stergerea ultimului nod:");
    //delete_end(&head);
    //displayList(head);
    //delete_node(&head);
    printf("\nLista dupa stergerea unui nod:");
    displayList(head);
    delete_node_before(&head);
    displayList(head);
    delete_node_after(&head);
    displayList(head);
    sort(&head);
    displayList(head);
    printf("\n");
}