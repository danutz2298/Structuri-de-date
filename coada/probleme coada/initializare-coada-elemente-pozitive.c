// Program ce initializeaza o coada cu elemente pozitive
#include <stdio.h>
#include <stdlib.h>

struct Queue *creeazaCoada();
void adaugaInCoada(struct Queue *q,int k);
struct QNode *stergeDinCoada(struct Queue *q);
struct QNode* inceputCoada(struct Queue* queue);
struct QNode* sfarsitCoada(struct Queue* queue);
void initCoada(struct Queue *queue);
int cauta(struct Queue *node, int data);
void afiseaza(struct Queue *q);

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
    printf("Valoarea %d a fost adaugata in coada!\n",k);
}

struct QNode *stergeDinCoada(struct Queue *q){
    // Daca coada este goala, returneaza NULL
    if(q->front == NULL)
        return NULL;

    struct QNode *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    return temp;
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

void afiseaza(struct Queue *q)
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

// Functie ce cauta in stiva un element, returneaza 1 daca il gaseste si 0 altfe
int cauta(struct Queue  *head, int data){
    int found = 0;
    struct QNode *temp;
    temp=head->front;
    // Verifica daca coada este goala;
    if(head->front == NULL){
        printf("Coada este goala!\n");
        return 0;
    }
    
    while(temp->next != NULL){
        if(temp->key == data){
             found = 1;
             return found;
        }
        temp=temp->next;
    }

    if(temp->next == NULL){
        if(temp->key == data){
             found = 1;
             return found;
        }
    }
    return found;
}

void initCoada(struct Queue *queue){
    int value,data;
    
    do{
        printf("\n Introduceti o valoare pozitiva in stiva:(-1 pentru a iesi din program) ");
        scanf("%d", &value);
        if(value >=0){
            if(queue->front == NULL){
                adaugaInCoada(queue, value);
            }else if(cauta(queue,value) != 1){
                adaugaInCoada(queue, value);
            }
        }
        
    }while(value >= 0);
}

int main(){
    struct Queue *queue = creeazaCoada();
    initCoada(queue);

    afiseaza(queue);
}