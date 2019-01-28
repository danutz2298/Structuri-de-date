// Program ce sterge elemente din coada
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

void afiseazaCoada(struct Queue *q)
{ 
    struct QNode *p;
    p=q->front;
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

int stergeDinCoada(struct Queue *q){
    // Daca coada este goala, returneaza NULL
    if(q->front == NULL)
        return 0;

    if(q->front == q->rear){
        printf("Bla");
        return 0;
    }

    struct QNode *temp = q->front;
    q->front = q->front->next;
    return temp->key;
}


int main(){
    // Creeaza o coada noua
    struct Queue *q = creeazaCoada();

    // Adaugam elemente in coada
    adaugaInCoada(q, 10);
    adaugaInCoada(q, 30);
    adaugaInCoada(q, 12);
    adaugaInCoada(q, 22);

    stergeDinCoada(q); // Sterge capul cozii
    stergeDinCoada(q);  // Sterge capul cozii

    // Afisam elementele din coada
    printf("Elementele dupa stergere sunt:");
    afiseazaCoada(q);
    printf("\n");
}
