// Program ce initializeaza o stiva cu elemente negative, elementele in stiva nu se vor repeta
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

void push(struct Stack** root, int data){
    struct Stack* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d a fost adaugat in stiva\n", data);
}

int isEmpty(struct Stack* root){
    return !root;
}

// Functie ce sterge un element din stiva
int pop(struct Stack** root){
    if(isEmpty(*root)){
        return 0;
    }

    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Functie ce returneaza capul stivei
int peek(struct Stack* root){
    if(isEmpty(root)){
        return 0;
    }
    return root->data;
}

void initStiva(struct Stack** root){
    int value,data;

    do{
        printf("\n Introduceti o valoare negativa in stiva: ");
        scanf("%d", &value);
        if(value < 0){
            if(isEmpty(*root) == 1){
                push(root,value);
            }else if((data = peek(*root)) != value){
                push(root,value);
            }
        }
    }while(value < 0);
}

void afisare(struct Stack *vf)
{
    struct Stack *p;

    for(p=vf;p;p=p->next)
        printf("%i->",p->data);
    printf("NULL");
}

int main(){
    struct Stack* root = NULL;
    initStiva(&root);
    afisare(root);
}