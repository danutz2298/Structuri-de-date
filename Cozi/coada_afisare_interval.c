// Program ce afiseaza elementele ce apartin unui interval [a,b]

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

// Functie ce citeste valorile din coada aflate intr-un interval dat
// Funcia citeste valorile aflate in coada, apoi le adaug intr-o alta coada
void valori_interval(struct Queue *n,struct Queue *newQueue, int a, int b){
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

void afisare_coada(struct Queue *head){
    struct QNode *temp;
    temp=head->front;

    while(temp->next != NULL){
        printf("%d ", temp->key);
        temp = temp->next;
    }

    // Afiseaza ultimul element din coada
    if(temp->next == NULL){
        printf("%d ", temp->key);
    }
}

int main(){
    struct Queue *coada1 = creeazaCoada();
    struct Queue *coada_interval = creeazaCoada();

    // Adaugam elemente in coada
    adaugaInCoada(coada1, 10);
    adaugaInCoada(coada1, 222);
    adaugaInCoada(coada1, 30);
    adaugaInCoada(coada1, 12);
    adaugaInCoada(coada1, 332);

    // Apelam functia pentru intervalul [10,30]
    valori_interval(coada1,coada_interval,10,30);
    printf("Valorile aflate in intervalul dat sunt:");
    afisare_coada(coada_interval);
    printf("\n");
}