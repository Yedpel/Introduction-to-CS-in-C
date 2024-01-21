/******************************************
*Student name: Yedidya Peles
*Student ID:322638354
*Exercise name: ex_6
******************************************/

#ifndef UNTITLED6_BINTREE_H
#define UNTITLED6_BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP_EMPTY 0
#define TOP_FULL 1
#define MAX_ORDER 3
#define MIN_ORDER 1
#define FOUND 1
#define READY 80
#define END 6
#define NAME_MAX 11
#define AGE_RAISE 20
#define DEATH 120
#define MALE 'M'
#define FEMALE 'F'
#define MOSHE "Moshe"
#define OPTION_ONE 1
#define OPTION_TOW 2
#define OPTION_THREE 3
#define OPTION_FOUR 4
#define OPTION_FIVE 5
#define OPTION_SIX 6

//declare on struct bin tree
typedef struct BinTree {
    int id;
    char *name;
    int age;
    char gender;
    void (*task)(void *val);
    void *action;
    struct BinTree *left;
    struct BinTree *right;
    struct BinTree *father;
} BinTree;

//declare on generic functions
void generic_function(BinTree *root, void(*task)(void *));
int generic_int_function(BinTree *root, int(*task)(void *));

BinTree *createChild(BinTree *root);
void addToTree(BinTree *root, BinTree *newChild);

void raiseAge(BinTree *root);
int checkDeath(BinTree *root);

int killOne(BinTree *root);

int mosheReady(BinTree *root);

int searchMales(BinTree *root);

void child_task (void *val);
void moshe_task (void *val);

int findMoshe (BinTree *root);
int mosheExist (BinTree *root);
void findPreOrder(BinTree* root);
void findInOrder(BinTree* root);
void findPostOrder(BinTree* root);

void printAll (BinTree *root);
void printPreOrder(BinTree *root);
void printInOrder(BinTree *root);
void printPostOrder(BinTree *root);

void sizeOfJews (BinTree *root);
int calcAllJews (BinTree *root);
int calcMale (BinTree *root);
int calcFemale (BinTree *root);

void freeIsrael(BinTree* root);


#endif //UNTITLED6_BINTREE_H