#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(struct node **head,int data){
    struct node *new_node, *ptr;
    
    if(*head == NULL){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node ->data = data;
        new_node->next = NULL;
        *head = new_node;
    }else{
        ptr = *head;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
    }
}
// Adauga un nod la inceputul liste duble
void add_front(struct node **head, int data){
    struct node *new_node, *ptr;

    ptr = *head;

    if(ptr->prev == NULL){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;

        new_node->next = ptr;
        ptr->prev = new_node;
        new_node->prev = NULL;
        *head = new_node;
    }
}

// Adauga un nod la sfarsitul listei duble
void add_end(struct node **head,int data){
    struct node *new_node, *ptr;

    ptr = *head;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->next = NULL;
}

void add_after(struct node **head){
    struct node *new_node, *current_node;

    current_node = *head;
    new_node =(struct node*)malloc(sizeof(struct node));

    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);
    new_node->data = value;

    printf("\n Introduceti valoarea nodului dupa care se doreste a fi inserat noul nod");
    scanf("%d", &node_value);

    while(current_node->data != node_value){
        current_node = current_node->next;
    }

    if(current_node->data == node_value){
        new_node->prev = current_node;
        new_node->next = current_node->next;
        current_node->next = new_node;
    }else{
        printf("\nValoarea nu exista in lista\n");
    }
}

void add_before(struct node**head){
    struct node *new_node, *current_node, *prev_node;

    current_node = *head;
    new_node =(struct node*)malloc(sizeof(struct node));

    int value,node_value;
    printf("\n Introdu valoarea: ");
    scanf("%d", &value);
    new_node->data = value;

    printf("\n Introduceti valoarea nodului inaintea caruia se doreste a fi inserat noul nod");
    scanf("%d", &node_value);

    while(current_node->data != node_value){
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node->data == node_value){
        if(current_node->prev == NULL){
            current_node->prev = new_node;
            new_node->next = current_node;
            new_node->prev = NULL;
            *head = new_node;
        }else{
            new_node->prev = prev_node;
            new_node->next = current_node;
            prev_node->next = new_node;
            current_node->prev = new_node;
        }
    }else{
        printf("\nValoarea nu exista in lista\n");
    }
}

void remove_front(struct node **head){
    struct node *ptr,*ptrn;
    ptr = *head;

    if(ptr->prev == NULL && ptr->next == NULL){
            *head = NULL;
            return;
    }

    if(ptr->prev == NULL){
        ptrn = ptr->next;
        ptrn->prev = NULL;
        *head = ptrn;
        free(ptr);
    }
}

void remove_end(struct node **head){
    struct node *ptr,*ptrn;
    ptr = *head;

    if(ptr->prev == NULL && ptr->next == NULL){
        *head = NULL;
        return;
    }

    while(ptr->next != NULL){
        ptrn= ptr;
        ptr = ptr->next;
    }

    if(ptr->next== NULL){
        ptrn->next = NULL;
        free(ptr);
    }else if(ptr->prev == NULL && ptr->next == NULL){

    }
}

void remove_node(struct node**head){
    struct node *ptr1,*ptr2,*ptr3;

    int value;
    printf("\n Introdu valoarea noudului care va fi stearsa: ");
    scanf("%d", &value);

    ptr1 = *head;
    ptr2 = ptr1;
    ptr3 = ptr2;

    while(ptr2->data != value && ptr3->next != NULL){
        ptr1 = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr2->next;;
    }

   if(ptr2->data == value){
       
       if(ptr2 == *head){
           ptr3 = ptr2->next;
           ptr3->prev = NULL;
           *head = ptr3;
           free(ptr2);
       }else if(ptr2->next == NULL){
           printf("%d", ptr2->data);
       }else{
            ptr1->next = ptr3;
            ptr3->prev = ptr1;
            free(ptr2);
       }
   }else if(ptr3->data == value){
       ptr2->next = NULL;
       free(ptr3);
   }
}

void delete_list(struct node **head){
    while(*head != NULL){
        remove_front(head);
    }
}

void show_list(struct node *head){
    if(head == NULL){
        printf("Lista este goala!\n");
        exit(0);
    }

    struct node *ptr;
    ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
}

int main(){
    push(&head,4);
    push(&head,14);
    add_front(&head, 24);
    add_end(&head,40);
    show_list(head);
    printf("\n");
    //add_after(&head);
    //show_list(head);
    printf("\n");
    add_before(&head);
    show_list(head);
    printf("\n");
    remove_front(&head);
    show_list(head);
    printf("\n");
    remove_end(&head);
    show_list(head);
    printf("\n");
    remove_node(&head);
    show_list(head);
    printf("\n");
    delete_list(&head);
    printf("\n");
    show_list(head);
}