// Program ce afiseaza elementele dintr-o coada, care apartin unui interval dat
#include <stdio.h>
#include <stdlib.h>

// Definire functii
struct QNode* newNode(int k);
struct Queue *creeazaCoada();
void adaugaInCoada(struct Queue *q,int k);

// O lista inlantuita care stocheaza datele unui nod din coada
struct QNode{
    int key;
    struct QNode *next;
};

/* * Coada, front - contine adresa primul nod din lista inlantuita 
   *        rear - continer adresa ultimului nod din lista inlantuita
   */
struct Queue{
    struct QNode *front, *rear;
};

// Functie utila in crearea unui nou nod in lista inlantuita
struct QNode* newNode(int k){
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// Functie ce creeaza o coada goala
struct Queue *creeazaCoada(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Functie ce adauga o cheie k in coada
void adaugaInCoada(struct Queue *q,int k){
    // Creaza un nou nod in lista inlantuita
    struct QNode *temp = newNode(k);

    // Daca lista este goala, nodul va fi si inceputul si sfarsitul cozii
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }

    // Adauga un nod la sfarsitul cozii
    q->rear->next = temp;
    q->rear = temp;
}

// Functie ce afiseaza elementele unei cozi
void afiseaza(struct Queue *q)
{ 
    struct QNode *p;
    p= q->front;
    // Verifica daca coada este goala;
    if(q->front == NULL){
        printf("Coada este goala!\n");
        return;
    }

    while(p->next != NULL){
        printf("%d ",p->key);
        p=p->next;
    }
    printf("%d ",p->key);
}

void valori_Interval(struct Queue *n,struct Queue *newQueue, int a, int b){
    struct QNode *ptr;

    ptr = n->front;

    while(ptr->next != NULL){
        if(ptr->key >= a && ptr->key <= b){
            adaugaInCoada(newQueue,ptr->key);
        }
        ptr = ptr->next;
    }
    // Verifica ultimul element
    if(ptr->key >= a && ptr->key <= b){
            adaugaInCoada(newQueue,ptr->key);
    }
}

int main(){
    struct Queue *q = creeazaCoada(); // creeaza coada nou q
    struct Queue *j = creeazaCoada(); // creeaza coada nou j pentru a punele elementele aflate in interval

    adaugaInCoada(q, 10); // adauga element in coada
    adaugaInCoada(q, 30);
    adaugaInCoada(q, 5);
    adaugaInCoada(q, 32);
    adaugaInCoada(q, 2);
    adaugaInCoada(q, 12);

    printf("Valorile din intervalul dat sunt: ");
    valori_Interval(q,j,2,30);
    afiseaza(j); 
    printf("\n");
}