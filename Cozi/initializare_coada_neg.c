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

// Functie ce cauta in stiva un element, returneaza 1 daca il gaseste si 0 altfe
int cautaInCoada(struct Queue  *head, int data){
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

// Functie ce initializeaza coada cu valori negative, elementele nu se vor repeta in coada
void initNegCoada(struct Queue *queue,int value){
        if(value < 0){
            if(queue->front == NULL){
                adaugaInCoada(queue, value);
            }else if(cautaInCoada(queue,value) != 1){  // verifica daca elementul se afla in coada
                adaugaInCoada(queue, value);
            }
        }
}

int main(){
    // Creeaza o coada noua
    struct Queue *q = creeazaCoada();

    int value;

    do{
        printf("Introduceti o valoare negativa in coada(0 pentr a iesii):");
        scanf("%d",&value);
        if(value < 0){
            initNegCoada(q,value);
        }
    }while(value < 0);

    // Afisam elementele din coada
    printf("Elementele din coada sunt:");
    afiseazaCoada(q);
    printf("\n");
}
