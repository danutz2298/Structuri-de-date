#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structura de reprezentare a unei stive o lista inlantuita
struct Stack{
    int data;
    struct Stack *next;
};

// Functie ce creaza un nod nou in stiva
struct Stack* newNode(int data){
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
    node->data = data;
    node->next = NULL;

    return node;
}

// Verifica daca stiva este goala
int isEmpty(struct Stack* root){
    return !root;
}

void push(struct Stack** root, int data){
    struct Stack* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d a fost adaugat in stiva\n", data);
}

// Functie ce afiseaza elementele unei stive
void afisareStiva(struct Stack* n){
    if(n == NULL){
        printf("stiva goala");
        return;
    }
    while(n){
        printf("%d ", n->data);
        n=n->next;
    }
}

// Functie ce sterge un element din stiva
int pop(struct Stack** root){
    if(isEmpty(*root)){
        return INT_MIN;
    }

    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

void valori_Interval(struct Stack *n,struct Stack **newList, int a, int b){
    struct Stack *ptr;
    if(n == NULL){
        printf("stiva este goala!");
    }
    ptr = n;

    while(ptr->next != NULL){
        if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
        }
        ptr = ptr->next;
    }
    // Verifica ultimul element
    if(ptr->data >= a && ptr->data <= b){
            push(newList,ptr->data);
    }
}


int main(){
    struct Stack *root = NULL;
    struct Stack *newList = NULL;
    int interval_a;
    int interval_b;

    //Adaugam elemente in stiva
    push(&root, 10);
    push(&root, 24);
    push(&root, 2);
    push(&root, 80);
    
    printf("Introduceti un interval [a,b] pentru afisare elementelor:\m");
    printf("\nIntroduceti a:");
    scanf("%d",&interval_a);
    printf("\nIntroduceti b:");
    scanf("%d", &interval_b);
    valori_Interval(root,&newList,interval_a,interval_b); // intervalul [2,40]
    printf("Valorile din intervalul dat sunt:");
    afisareStiva(newList); 
    printf("\n");
}   