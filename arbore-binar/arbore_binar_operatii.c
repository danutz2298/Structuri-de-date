// Program ce creeaza un arbore binar
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;

    // Initializarea fiilor cu NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int height(struct node* node){
    if(node == NULL){
        return 0;
    }else{
        // calculeaza lungimea fiecarui sub-arbore
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* cea mai mare dintr-e lheight si rheight */
        if(lheight > rheight){
            return (lheight+1);
        }else{
            return (rheight+1);
        }
    }
}

void printGivenLevel(struct node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d", root->data);
    else if(level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node* root){
    int h = height(root);
    int i;
    for(i=1; i<=h; i++){
        printGivenLevel(root,i);
    }
}



int main(){
    struct node *root = newNode(1);
     /* arborele dupa creeare
  
        1 
      /   \ 
     NULL  NULL   
  */
    root->left = newNode(2);
    root->right = newNode(3);
 /* 2 si 3 devin fii lui 1
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
    root->left->left  = newNode(4); 
     /* 4 devine fiul stang al lui 2, lungimea este 3
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
printf("Level Order traversal of binary tree is \n"); 
    printLevelOrder(root);
}