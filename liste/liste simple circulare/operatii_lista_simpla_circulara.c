/* Program care creeaza o lista simplu inlantuita circulara */

#include <stdio.h>
#include <stdlib.h>

//definirea structurii lista circulara

struct node{
    int data;
    struct node *next;
};

// Adauga nod nou la inceputul listei
void push(struct node **head, int data){
    struct node *new_node, *ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    ptr = *head;

    if(*head == NULL){
        new_node->next = new_node;
        *head = new_node;
    }else{
        new_node->next = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        
        ptr->next = new_node;
        *head = new_node;
    }
}

// Adauga nod la sfarsitul listei
void insert_end(struct node **head, int data){
    struct node *new_node, *ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    ptr = *head;

    while(ptr->next != *head){
        ptr = ptr->next;
    }

    new_node->next = *head;
    ptr->next = new_node;
}

// Adauga un node dupa o valoare existenta in nod
void insert_node_after(struct node **head){
    struct node *new_node, *ptr, *prev;

    new_node = (struct node*)malloc(sizeof(struct node));
    

    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);
    new_node->data = value;

    printf("\n Introduceti valoarea nodului dupa care se doreste a fi inserat noul nod");
    scanf("%d", &node_value);
    ptr = *head;

    while(ptr->data != node_value && ptr->next != *head){
        ptr = ptr->next;
    }

    if(ptr->data == node_value){
        if(ptr->next == *head){
            ptr->next = new_node;
            new_node->next = *head;
        }else{
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
}

// Adauga un nod inaintea unei valori existente in nod
void insert_node_before(struct node **head){
    struct node *new_node, *ptr, *prev;

    new_node = (struct node*)malloc(sizeof(struct node));

    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);
    new_node->data = value;

    printf("\n Introduceti valoarea nodului inaintea caruia se doreste a fi inserat noul nod");
    scanf("%d", &node_value);
    ptr = *head;

    while(ptr->data != node_value && ptr->next != *head){
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr->data == node_value){
        if(ptr == *head){
            prev = ptr;
            while(ptr->next != *head){
                ptr = ptr->next;
            }
            new_node->next = prev;
            ptr->next = new_node;
            *head = new_node;
        }else{
            new_node->next = prev->next;
            prev->next = new_node;
        }
    }
}

// Sterge un nod de la inceputul listei
void rmv_front(struct node **head){
    struct node *ptr,*prev;
    ptr = *head;

    if(ptr == *head){
        prev = ptr->next;
        
        while(ptr->next != *head){
            ptr = ptr->next;
        }
            
        if(ptr->next == *head){
            ptr->next = prev;
            free(*head);
            *head = prev;
        }
    }
}

void rmv_end(struct node **head){
    struct node *ptr,*ptrn;
    ptr = *head;
    // Verifica daca lista are un singur nod
    if(ptr->next == ptr){
        *head = NULL;
        return;
    }

    while(ptr->next != *head){
        ptrn = ptr;
        ptr = ptr->next;
    }
    ptrn->next = ptr->next;
    free(ptr);
    
}

void rmv_node(struct node **head){
    struct node *ptr,*prev;
    ptr = *head;

    int value;

    printf("\n Introduceti valoarea nodului care va fi sters:");
    scanf("%d", &value);

    while(ptr->data != value && ptr->next != *head){
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr->data == value){
        prev = ptr->next;
        if(ptr == *head){
            prev = ptr->next;
            while(ptr->next != *head){
                ptr = ptr->next;
            }
            
            if(ptr->next == *head){
                ptr->next = prev;
                free(*head);
                *head = prev;
            }
        }else{
            prev->next = ptr->next;
            free(ptr);
        }   
    }

}

void delete_list(struct node** head){
    struct node *ptr,*ptrn;
    ptr = *head;

    while(ptr->next != *head){
        rmv_end(head);
    }
    rmv_end(head);
    return;
}

// Functie ce afiseaza elementele listei
void display_list(struct node *head){
    struct node *ptr;
    ptr = head;
    if (head == NULL){
        printf("list este goala");
    }
    ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){
    struct node *head = NULL;

    push(&head,3);
    push(&head,4);
   push(&head,4);
    //insert_end(&head, 6);
   // display_list(head);
    //insert_node_before(&head);
    //display_list(head);
    //insert_node_after(&head);
    //display_list(head);
    //rmv_front(&head);
    //display_list(head);
    //rmv_end(&head);
    //display_list(head);
    //rmv_node(&head);
    //display_list(head);
    //delete_list(&head);
    display_list(head);
}