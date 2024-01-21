/******************************************
*Student name: Yedidya Peles
*Student ID:322638354
*Exercise name: ex_6
******************************************/

#include "BinTree.h"

void generic_function(BinTree *root, void(*task)(void *)) {
    task(root);
}

int generic_int_function(BinTree *root, int(*task)(void *)) {
    return task(root);
}


/************************************************************************
* function name: createChild
* The Input: BinTree *root (the new child)
* The output: BinTree *root (the new child with values)
* The Function operation: get values and enter to the new child
*************************************************************************/
BinTree *createChild(BinTree *root) {
    int id;
    char name[NAME_MAX];
    char gender;
    //get the input
    printf("please enter child id:\n");
    scanf("%d", &id);
    printf("please insert child name:\n");
    scanf(" %s", name);
    printf("please insert child gender:\n");
    scanf(" %c", &gender);

    //create allocation for root
    root = (BinTree *) malloc(sizeof(BinTree));
    //check allocation
    if (root == NULL) {
        return NULL;
    }
    //create allocation for name
    root->name = (char *) malloc((NAME_MAX) * sizeof(char));
    //check allocation
    if (root->name == NULL) {
        //free the allocation that done before
        free(root);
        return NULL;
    }

    //enter values
    root->id = id;
    strcpy(root->name, name);
    root->gender = gender;
    //initialize age (-age) raise and after the raise it became 0
    root->age = (-AGE_RAISE);
    root->left = NULL;
    root->right = NULL;
    root->father = NULL;
    root->action = root->name;
    //if he is moshe - specific task
    if (strcmp(MOSHE, root->name) == 0 && root->gender == MALE)
        root->task = moshe_task;
    else
        root->task = child_task;

    return root;
    //end of createChild
}

/************************************************************************
* function name: addToTree
* The Input: BinTree *root, BinTree *newChild
* The output: void
* The Function operation: add the new child to the existing tree
*************************************************************************/
void addToTree(BinTree *root, BinTree *newChild) {
    if (root->id > newChild->id) {
        if (root->left != NULL) {
            return addToTree(root->left, newChild);
        }
        root->left = newChild;
        newChild->father = root;
        //the add done to some left
        return;
    }
    //check right
    if (root->id < newChild->id) {
        if (root->right != NULL) {
            return addToTree(root->right, newChild);
        }
        root->right = newChild;
        newChild->father = root;
        if (root->right == NULL) {
            //the add done to some right
            return;
        }
    }
    //end of addToTree
}

/************************************************************************
* function name: raiseAge
* The Input: BinTree *root
* The output: void
* The Function operation: raise the age of everyone in 20 years
*************************************************************************/
void raiseAge(BinTree *root) {
    if (root == NULL) {
        return;
    }
    root->age += AGE_RAISE;
    raiseAge(root->left);
    raiseAge(root->right);
}

/************************************************************************
* function name: check_death
* The Input: BinTree *root
* The output: int - if the tophead died 0, else other number
* The Function operation: check if someone died in this iteration
*************************************************************************/
int checkDeath(BinTree *root) {
    if (root == NULL) {
        return TOP_FULL;
    }
    //if the root died
    if (root->age == DEATH) {
        return killOne(root);
    }
    checkDeath(root->left);
    checkDeath(root->right);
    //if no one died
    return TOP_FULL;
    //end of check death
}

/************************************************************************
* function name: killOne
* The Input: BinTree *root
* The output: int - if the tophead died 0, else other number
* The Function operation: remove and free root the died
*************************************************************************/
int killOne(BinTree *root) {
    //if he has no childes
    if (root->left == NULL && root->right == NULL) {
        //if he does not have a father - in the top
        if (root->father == NULL) {
            //there is no father to change
            //he is the only one in the all tree
            free(root->name);
            free(root);
            return TOP_EMPTY;
        }
            //change father ptr to root to null
        else {
            //if he is the left child
            if (root->father->left == root)
                root->father->left = NULL;
            else
                //he is the right child
                root->father->right = NULL;
        }
        //free the allocations
        free(root->name);
        free(root);
        return TOP_FULL;
        //end of he does not have childes
    }

    //if he has only left child
    if (root->left != NULL && root->right == NULL) {
        //save the dead
        BinTree *temp = root->left;
        //if he does not have a father - in the top
        if (root->father == NULL) {
            //copy root.left to root, and delete the root.left
            root->id = root->left->id;
            //free the name
            free(root->name);
            //copy the name
            root->name = root->left->name;
            root->gender = root->left->gender;
            root->age = root->left->age;
            root->action = root->left->action;
            root->task = root->left->task;
            if (root->left->left != NULL)
                root->left->left->father = root;
            if (root->left->right != NULL)
                root->left->right->father = root;
            root->right = root->left->right;
            root->left = root->left->left;
            //the copy end, free the root.left that copied
            free(temp);
            return TOP_FULL;
            //end of he does not have a father
        }

        //he has a father
        //connect the left child to grandpa
        root->left->father = root->father;
        //connect grandpa to grandchild
        if (root->father->left==root)
            //he is the left son
            root->father->left = root->left;
        else
            //he is the right son
            root->father->right = root->left;
        //free the allocations
        free(root->name);
        free(root);
        return TOP_FULL;
        //end of he has a father

        //end of only left
    }

    //if he has only right child
    if (root->left == NULL && root->right != NULL) {
        //save the dead
        BinTree *temp = root->right;
        //if he does not have a father - in the top
        if (root->father == NULL) {
            //copy root.right to root, and delete the root.right
            root->id = root->right->id;
            //free the name
            free(root->name);
            //copy the name
            root->name = root->right->name;
            root->gender = root->right->gender;
            root->age = root->right->age;
            root->action = root->right->action;
            root->task = root->right->task;
            if (root->right->left != NULL)
                root->right->left->father = root;
            if (root->right->right != NULL)
                root->right->right->father = root;
            root->left = root->right->left;
            root->right = root->right->right;
            //the copy end, free the root.right that copied
            free(temp);
            return TOP_FULL;
            //end of he does not have a father
        }

        //he has a father
        //connect the right child to grandpa
        root->right->father = root->father;
        //connect grandpa to grandchild
        if (root->father->left==root)
            //he is the left son
            root->father->left = root->right;
        else
            //he is the right son
            root->father->right = root->right;
        //free the allocations
        free(root->name);
        free(root);
        return TOP_FULL;
    //end of only right child
    }

    //so he has both sides childes
    //find the smallest right scion
    BinTree *scion = root->right;
    while (scion->left != NULL) {
        scion = scion->left;
    }
    //copy the values of the smallest scion to root
    root->id = scion->id;
    //free the name
    free(root->name);
    //copy the name
    root->name = scion->name;
    root->gender = scion->gender;
    root->age = scion->age;
    root->action = scion->action;
    root->task = scion->task;
    //connect father to grandchild (empty or null)
    //if he is the left child
    if (scion->father->left == scion) {
        scion->father->left = scion->right;
    } else {
        //he is the right child
        scion->father->right = scion->right;
    }
    //if the scion had right child - connect to grandpa
    if (scion->right != NULL) {
        scion->right->father = scion->father;
    }
    //free the copied scion
    free(scion);
    return TOP_FULL;
    //end of, so he had to childes
    //end of the kill one
}

/************************************************************************
* function name: mosheReady
* The Input: BinTree *root
* The output: int - 80 if moshe is 80 and ready, else 0
* The Function operation: check if moshe is 80and ready to free israel
*************************************************************************/
int mosheReady(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    //if he is moshe and male and 80
    if (strcmp(root->name, MOSHE) == 0 && root->gender == MALE && root->age
                                                                  == READY) {
        return READY + mosheReady(root->left) +
               mosheReady(root->right);
    }
    //else
    return 0 + mosheReady(root->left) +
           mosheReady(root->right);
}

/************************************************************************
* function name: searchMales
* The Input: BinTree *root
* The output: int - if the tophead died 0, else other number
* The Function operation: search all the male and kill them ,except moshe
*************************************************************************/
int searchMales(BinTree *root) {
    if (root == NULL) {
        return TOP_FULL;
    }
    searchMales(root->right);
    searchMales(root->left);
    //if not moshe and not male
    if (strcmp(root->name, MOSHE) != 0 && root->gender == MALE) {
        int empty = killOne(root);
        //check if the top empty
        if (empty==TOP_EMPTY)
            return TOP_EMPTY;
    }
    return TOP_FULL;
}

/************************************************************************
* function name: child_task
* The Input: BinTree *root
* The output: void
* The Function operation: print normal child task - cry waaaa
*************************************************************************/
void child_task(void *val) {
    printf("%s cry waaaa\n", (char *) val);
}

/************************************************************************
* function name: moshe_task
* The Input: BinTree *root
* The output: void
* The Function operation: print moshe task - quiet
*************************************************************************/
void moshe_task(void *val) {
    printf("%s quiet\n", (char *) val);
}

/************************************************************************
* function name: findMoshe
* The Input: BinTree *root
* The output: int, 1 if found , else 0
* The Function operation: ask another function if moshe is in the tree and
* print the task of all the childes in the tree, in 3 option of order
*************************************************************************/
int findMoshe(BinTree *root) {
    int order;
    //check if moshe exist
    int found = mosheExist(root);
    printf("please choose order:\n"
           "(1) preorder\n"
           "(2) inorder\n"
           "(3) postorder\n");
    scanf("%d", &order);
    //check input
    if (order > MAX_ORDER || order < MIN_ORDER) {
        printf("wrong order!\n");
        return 0;
    }
    // find in the order that the user asked
    switch (order) {
        case OPTION_ONE: {
            findPreOrder(root);
            break;
        }
        case OPTION_TOW: {
            findInOrder(root);
            break;
        }
            //case 3
        default: {
            findPostOrder(root);
            break;
        }
            //end of switch
    }
    //if moshe found - return that found
    if (found == FOUND) {
        return found;
    } else {
        //moshe not fond - print it and return 0
        printf("Moshe Not Found!\n");
        return 0;
    }
//end of find moshe
}

/************************************************************************
* function name: mosheExist
* The Input: BinTree *root
* The output: int, 1 if found , else 0
* The Function operation: check if moshe male is in the tree
*************************************************************************/
int mosheExist(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    //if it is moshe male - return that found
    if (strcmp(root->name, MOSHE) == 0 && root->gender == MALE) {
        return FOUND;
    }
    return mosheExist(root->left) || mosheExist(root->right);
}

/************************************************************************
* function name: findPreOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print task of all childes in the tree - preorder
*************************************************************************/
void findPreOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    root->task(root->action);
    findPreOrder(root->left);
    findPreOrder(root->right);
}

/************************************************************************
* function name: findInOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print task of all childes in the tree - inorder
*************************************************************************/
void findInOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    findInOrder(root->left);
    root->task(root->action);
    findInOrder(root->right);
}

/************************************************************************
* function name: findPostOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print task of all childes in the tree - postorder
*************************************************************************/
void findPostOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    findPostOrder(root->left);
    findPostOrder(root->right);
    root->task(root->action);
}

/************************************************************************
* function name: printAll
* The Input: BinTree *root
* The output: void
* The Function operation: print all childes in the tree, in 3 order option
*************************************************************************/
void printAll(BinTree *root) {
    int order = 0;
    printf("please choose order:\n"
           "(1) preorder\n"
           "(2) inorder\n"
           "(3) postorder\n");
    scanf("%d", &order);
    // print in the order that the user asked
    switch (order) {
        case OPTION_ONE: {
            printPreOrder(root);
            break;
        }
        case OPTION_TOW: {
            printInOrder(root);
            break;
        }
        case OPTION_THREE: {
            printPostOrder(root);
            break;
        }
            //wrong input
        default: {
            printf("wrong order!\n");
        }
            //end of switch
    }
    //end of print all
}

/************************************************************************
* function name: printPreOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print all childes in the tree, in preorder
*************************************************************************/
void printPreOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    printf("id: %d, name: %s, gender: %c, age: %d\n", root->id,
           root->name, root->gender, root->age);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/************************************************************************
* function name: printInOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print all childes in the tree, in inorder
*************************************************************************/
void printInOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("id: %d, name: %s, gender: %c, age: %d\n", root->id,
           root->name, root->gender, root->age);
    printInOrder(root->right);
}

/************************************************************************
* function name: printPostOrder
* The Input: BinTree *root
* The output: void
* The Function operation: print all childes in the tree, in postorder
*************************************************************************/
void printPostOrder(BinTree *root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("id: %d, name: %s, gender: %c, age: %d\n", root->id,
           root->name, root->gender, root->age);
}

/************************************************************************
* function name: sizeOfJews
* The Input: BinTree *root
* The output: void
* The Function operation: print the size of jews in 3 order option
*************************************************************************/
void sizeOfJews(BinTree *root) {
    int calcWho;
    printf("please choose what you want to calculate:\n"
           "(1) All jews\n"
           "(2) Male\n"
           "(3) Female\n");
    scanf("%d", &calcWho);
    // calc the option that the user asked
    switch (calcWho) {
        case OPTION_ONE: {
            int allJews = calcAllJews(root);
            printf("size of all jews is: %d\n", allJews);
            break;
        }
        case OPTION_TOW: {
            int allMale = calcMale(root);
            printf("size of all male jews is: %d\n", allMale);
            break;
        }
        case OPTION_THREE: {
            int allFemale = calcFemale(root);
            printf("size of all female jews is: %d\n", allFemale);
            break;
        }
            //wrong input
        default: {
            printf("wrong order!\n");
        }
            //end of switch
    }
    //end of print all
}

/************************************************************************
* function name: calcAllJews
* The Input: BinTree *root
* The output: int - the size of all the jews
* The Function operation: calc all the jews
*************************************************************************/
int calcAllJews(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + calcAllJews(root->left)
           + calcAllJews(root->right);
}

/************************************************************************
* function name: calcMale
* The Input: BinTree *root
* The output: int - the size of all the male jews
* The Function operation: calc all the male jews
*************************************************************************/
int calcMale(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    //if male
    if (root->gender == MALE)
        return 1 + calcMale(root->left)
               + calcMale(root->right);
    else {
        //else female
        return 0 + calcMale(root->left)
               + calcMale(root->right);
    }
    //end of calc male
}

/************************************************************************
* function name: calcFemale
* The Input: BinTree *root
* The output: int - the size of all the female jews
* The Function operation: calc all the female jews
*************************************************************************/
int calcFemale(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    //if female
    if (root->gender == FEMALE)
        return 1 + calcFemale(root->left)
               + calcFemale(root->right);
    else {
        //else male
        return 0 + calcFemale(root->left)
               + calcFemale(root->right);
    }
    //end of calc female
}

/************************************************************************
* function name: freeIsrael
* The Input: BinTree *root
* The output: void
* The Function operation: free all the tree of israel
*************************************************************************/
void freeIsrael(BinTree *root) {
    if (root == NULL) {
        return;
    }
    freeIsrael(root->left);
    freeIsrael(root->right);
    //free tha allocations
    free(root->name);
    free(root);
}
