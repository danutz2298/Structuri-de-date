// Program ce concateneaza 2 prin copiere.
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

// Functie ce concateneaza 2 cozi prin copiere. Functia copiaza elementele cozii 2 in coada 1.
void concatenareCoada_copiere(struct Queue **coada1,struct Queue **coada2){
    struct QNode *ptrc1,*ptrc2;
    ptrc1 = (*coada1)->front;
    ptrc2 = (*coada2)->front;

    while(ptrc2->next != NULL){
        adaugaInCoada(*coada1,ptrc2->key);
        ptrc2 = ptrc2->next;
    }
    if(ptrc2->next == NULL){
        adaugaInCoada(*coada1,ptrc2->key);
    }
}

int main(){
    // Creeaza o coada noua
    struct Queue *coada1 = creeazaCoada();
    struct Queue *coada2 = creeazaCoada();

    // Adaugam elemente in coada
    adaugaInCoada(coada1, 10);
    adaugaInCoada(coada1, 30);
    adaugaInCoada(coada1, 12);

    adaugaInCoada(coada2, 3);
    adaugaInCoada(coada2, 12);
    adaugaInCoada(coada2, 22);
    concatenareCoada_copiere(&coada1, &coada2);
    // Afisam elementele din coada
    printf("Elementele concatenate sunt:");
    afiseazaCoada(coada1);
    printf("\n");
}
