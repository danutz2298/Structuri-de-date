#include <stdio.h>
#include <stdlib.h>
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

struct QNode* inceputCoada(struct Queue* queue){
    // Verifica daca coada este goala
    if(queue->front == NULL){
        printf("Coada este goala!\n");
        return NULL;
    }
    struct QNode *temp = queue->front;
    return temp;
}

struct QNode* sfarsitCoada(struct Queue* queue){
    // Verifica daca coada este goala
    if(queue->front == NULL){
        printf("Coada este goala!\n");
        return NULL;
    }
    struct QNode *temp = queue->rear;
    return temp;
}

int main(){
    // Creeaza o coada noua
    struct Queue *q = creeazaCoada();

    // Adaugam elemente in coada
    adaugaInCoada(q, 10);
    adaugaInCoada(q, 30);
    adaugaInCoada(q, 12);

    struct QNode *inceput = inceputCoada(q);
    if(inceput != NULL){
        printf("Inceputul cozii este %d\n", inceput->key);
    }

    struct QNode *sfarsit = sfarsitCoada(q);
    if(sfarsit != NULL){
        printf("Sfarsitul cozii este %d\n", sfarsit->key);
    }
}