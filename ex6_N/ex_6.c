/******************************************
*Student name: Yedidya Peles
*Student ID:322638354
*Exercise name: ex_6
******************************************/

#include "BinTree.h"


int main() {
    int option = 0;
    BinTree *topHead = NULL;
    while (option != END) {
        printf("please choose action:\n"
               "(1) A child was born\n"
               "(2) Throw into the Nile\n"
               "(3) Find Moshe\n"
               "(4) Print All\n"
               "(5) Size of jews\n"
               "(6) Exit\n");
        scanf(" %d", &option);
        switch (option) {
            //(1) a child was born
            case OPTION_ONE: {
                //check if the tree is empty
                if (topHead == NULL) {
                    //create new child, and insert to tophead
                    topHead = createChild(topHead);
                    //if the allocation failed
                    if (topHead == NULL) {
                        //the allocation failed - exit 1
                        exit(1);
                    }
                }
                    //the tree is not empty
                else {
                    //create new child()
                    BinTree *newChild = NULL;
                    newChild = createChild(newChild);
                    //if the allocation failed
                    if (newChild == NULL) {
                        //the allocation failed - free all and exit 1
                        generic_function(topHead,
                                         (void *) freeIsrael);
                        exit(1);
                    }
                    //add to tophead ()
                    addToTree(topHead, newChild);
                }
                break;
            }
                //(2) throw into the Nile
            case OPTION_TOW: {
                int empty = generic_int_function(topHead,
                                                 (void *) searchMales);
                //check if top ok
                if (empty == TOP_EMPTY)
                    topHead = NULL;
                break;
            }
                //(3) find Moshe
            case OPTION_THREE: {
                int found = generic_int_function(topHead,
                                                 (void *) findMoshe);
                //if moshe found - kill the males
                if (found == FOUND) {
                    int empty = generic_int_function
                            (topHead, (void *) searchMales);
                    //check if top ok
                    if (empty == TOP_EMPTY)
                        topHead = NULL;
                    break;
                }
                break;
            }
                //(4) print All
            case OPTION_FOUR: {
                generic_function(topHead, (void *) printAll);
                break;
            }
                //(5) size of jews
            case OPTION_FIVE: {
                generic_function(topHead, (void *) sizeOfJews);
                break;
            }
                //(6) exit
            case OPTION_SIX: {
                generic_function(topHead, (void *) freeIsrael);
                break;
            }
                //default - wrong option
            default: {
                printf("wrong choose please choose again\n");
                break;
            }
                //end of switch
        }
        //if we back to menu
        if (option != END) {
            //raise age
            generic_function(topHead, (void *) raiseAge);
            //check death
            int empty = generic_int_function(topHead,
                                             (void *) checkDeath);
            if (empty == TOP_EMPTY)
                topHead = NULL;
            //check moshe 80
            int ready = generic_int_function(topHead,
                                             (void *) mosheReady);
            if (ready == READY) {
                printf("Moshe say: let my people go!\n");
                generic_function(topHead, (void *) freeIsrael);
                exit(0);
            }
            printf("\n");
            //end of back to menu
        }
        //end of while loop
    }
    return 0;
}

