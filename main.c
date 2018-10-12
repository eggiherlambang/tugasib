#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
#define LEFT "left"
#define RIGHT "right"
 
/*-------Pohon Biner*/
 
typedef struct smp *alamatsimpul;
typedef struct smp{
    char huruf;         //Elemen pohon
    alamatsimpul right;//Ranting kanan
    alamatsimpul left;//Ranting kiri
}simpul;
 
typedef struct{
    simpul* root;//Root = Akar pohon paling atas
}tree;
 
 
/*-------Queue*/
 
typedef struct elmQueue *alamatelmtQueue;
typedef struct elmQueue{
    simpul* elemen;//alamat simpul pohon
    alamatelmtQueue next;
}containerQueue;
 
typedef struct{
    containerQueue *first;//Pointer depan
    containerQueue *last;//Pointer belakang
}queue;
 

 
/*Mesin*/
 
/*-------Pohon Biner*/
 
//Buat pohon baru
void makeTree(char huruf, tree *T){
    simpul *node;//Pointer baru
    node = (simpul *) malloc (sizeof (simpul));
    node->huruf = huruf;
    node->right = NULL;
    node->left = NULL;
    (*T).root = node;//Pindah akar
}
 
//Tambah elemen di ranting kanan
void addTree(char tempat[], char huruf, simpul **root){
    /*Jika ranting kanan masih kosong*/
    if((*root)->right == NULL){
        simpul *node;//Pointer baru
        node = (simpul *) malloc (sizeof (simpul));
        node->huruf = huruf;
        node->right = NULL;
        node->left = NULL;
        if(strcmp(tempat, RIGHT) == 0) (*root)->right = node;//Pindah ranting kanan
        else if(strcmp(tempat, LEFT) == 0) (*root)->left = node;//Pindah ranting kiri
    }
}
 


/*-------Queue*/
 
//prosedur membuat queue kosong
void createEmptyQueue(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}
 
//prosedur memeriksa apakah queue kosong
int isQueueEmpty(queue Q){
    int hasil = 0;
    if(Q.first == NULL){
        hasil = 1;
    }
    return hasil;
}
 
//prosedur menambah elemen pada queue(addLast)
void addQueue(simpul *node, queue *Q ){
    containerQueue *tunjuk;
    tunjuk = (containerQueue *) malloc (sizeof (containerQueue));
    tunjuk->elemen = node;
    tunjuk->next = NULL;
 
    //jika queue masih kosong (addFirst)
    if((*Q).first == NULL) (*Q).first = tunjuk;
    else (*Q).last->next = tunjuk;
 
    (*Q).last = tunjuk;
    tunjuk = NULL;
}
 
//prosedur delete queue (delFirst);
void delQueue(queue *Q){
 
    //jika queue tidak kosong
    if((*Q).first != NULL){
        containerQueue *tunjuk = (*Q).first;
        (*Q).first = (*Q).first->next;
        tunjuk->next = NULL;
        free(tunjuk);
    }
}
 

 
//print pohon per level dengan algoritma BFS
void BFS_printLevelOrder(simpul *root){
    if(root!=NULL){
        queue Q;
        createEmptyQueue(&Q);
        addQueue(root, &Q);
 
        while(isQueueEmpty(Q) != 1){
            printf("%c ", Q.first->elemen->huruf);
 
            if(Q.first->elemen->left != NULL){
                addQueue(Q.first->elemen->left, &Q);
            }
            if(Q.first->elemen->right != NULL){
                addQueue(Q.first->elemen->right, &Q);
            }
            delQueue(&Q);
        }
        printf("\n");
    }
}
 

 
int main(){
 
    tree T;#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
#define LEFT "left"
#define RIGHT "right"
 
/*-------Pohon Biner*/
 
typedef struct smp *alamatsimpul;
typedef struct smp{
    char huruf;         //Elemen pohon
    alamatsimpul right;//Ranting kanan
    alamatsimpul left;//Ranting kiri
}simpul;
 
typedef struct{
    simpul* root;//Root = Akar pohon paling atas
}tree;
 
 
/*-------Queue*/
 
typedef struct elmQueue *alamatelmtQueue;
typedef struct elmQueue{
    simpul* elemen;//alamat simpul pohon
    alamatelmtQueue next;
}containerQueue;
 
typedef struct{
    containerQueue *first;//Pointer depan
    containerQueue *last;//Pointer belakang
}queue;
 

 
/*Mesin*/
 
/*-------Pohon Biner*/
 
//Buat pohon baru
void makeTree(char huruf, tree *T){
    simpul *node;//Pointer baru
    node = (simpul *) malloc (sizeof (simpul));
    node->huruf = huruf;
    node->right = NULL;
    node->left = NULL;
    (*T).root = node;//Pindah akar
}
 
//Tambah elemen di ranting kanan
void addTree(char tempat[], char huruf, simpul **root){
    /*Jika ranting kanan masih kosong*/
    if((*root)->right == NULL){
        simpul *node;//Pointer baru
        node = (simpul *) malloc (sizeof (simpul));
        node->huruf = huruf;
        node->right = NULL;
        node->left = NULL;
        if(strcmp(tempat, RIGHT) == 0) (*root)->right = node;//Pindah ranting kanan
        else if(strcmp(tempat, LEFT) == 0) (*root)->left = node;//Pindah ranting kiri
    }
}
 


/*-------Queue*/
 
//prosedur membuat queue kosong
void createEmptyQueue(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}
 
//prosedur memeriksa apakah queue kosong
int isQueueEmpty(queue Q){
    int hasil = 0;
    if(Q.first == NULL){
        hasil = 1;
    }
    return hasil;
}
 
//prosedur menambah elemen pada queue(addLast)
void addQueue(simpul *node, queue *Q ){
    containerQueue *tunjuk;
    tunjuk = (containerQueue *) malloc (sizeof (containerQueue));
    tunjuk->elemen = node;
    tunjuk->next = NULL;
 
    //jika queue masih kosong (addFirst)
    if((*Q).first == NULL) (*Q).first = tunjuk;
    else (*Q).last->next = tunjuk;
 
    (*Q).last = tunjuk;
    tunjuk = NULL;
}
 
//prosedur delete queue (delFirst);
void delQueue(queue *Q){
 
    //jika queue tidak kosong
    if((*Q).first != NULL){
        containerQueue *tunjuk = (*Q).first;
        (*Q).first = (*Q).first->next;
        tunjuk->next = NULL;
        free(tunjuk);
    }
}
 

 
//print pohon per level dengan algoritma BFS
void BFS_printLevelOrder(simpul *root){
    if(root!=NULL){
        queue Q;
        createEmptyQueue(&Q);
        addQueue(root, &Q);
 
        while(isQueueEmpty(Q) != 1){
            printf("%c ", Q.first->elemen->huruf);
 
            if(Q.first->elemen->left != NULL){
                addQueue(Q.first->elemen->left, &Q);
            }
            if(Q.first->elemen->right != NULL){
                addQueue(Q.first->elemen->right, &Q);
            }
            delQueue(&Q);
        }
        printf("\n");
    }
}
 

 
int main(){
 
    tree T;
 
    makeTree('A', &T);
    addTree(LEFT , 'B', &T.root);
    addTree(RIGHT, 'C', &T.root);
    addTree(LEFT , 'D', &T.root->left);
    addTree(RIGHT, 'E', &T.root->left);
    addTree(LEFT , 'F', &T.root->right);
    addTree(RIGHT, 'G', &T.root->right);
    addTree(LEFT , 'H', &T.root->left->left);
    addTree(RIGHT, 'I', &T.root->left->right);
    addTree(LEFT , 'J', &T.root->right->right);
    addTree(RIGHT, 'K', &T.root->right->right);
    addTree(RIGHT, 'L', &T.root->right->right->right);
 
    BFS_printLevelOrder(T.root);
 
    return 0;
}
//waktu yang dibutuhkan untuk mengcompile adalah =950ms
 
    makeTree('A', &T);
    addTree(LEFT , 'B', &T.root);
    addTree(RIGHT, 'C', &T.root);
    addTree(LEFT , 'D', &T.root->left);
    addTree(RIGHT, 'E', &T.root->left);
    addTree(LEFT , 'F', &T.root->right);
    addTree(RIGHT, 'G', &T.root->right);
    addTree(LEFT , 'H', &T.root->left->left);
    addTree(RIGHT, 'I', &T.root->left->right);
    addTree(LEFT , 'J', &T.root->right->right);
    addTree(RIGHT, 'K', &T.root->right->right);
    addTree(RIGHT, 'L', &T.root->right->right->right);
 
    BFS_printLevelOrder(T.root);
 
    return 0;
}