/******************************************
* Student name: Yedidya Peles
* Student: 322638354
* Exercise name: Exercise 3
******************************************/
#include <stdio.h>
#include  <math.h>

int main() {


    int input1;
    do {
        printf("Choose an option:\n"
               "\t1: Logical Statement Calculator\n"
               "\t2: Count digit in a number\n"
               "\t3: GCD Calculator\n"
               "\t4: Exit\n");
        scanf("%d", &input1);
        int checkInput1;
        for (int i = 0; i <= 4; ++i) {
            if (input1 == i)
                break;
            checkInput1 = 0;
        }
        if (checkInput1 == 0) {
            printf("Fool of a Took!\n"
                   "This is a serious journey, not a hobbit walking-party.\n"
                   "Throw yourself in next time, and then you will be no "
                   "further nuisance.\n") ;
            continue;
        }

        if (input1 == 4) {
            printf("So Long, and Thanks for All the Fish!");
            break;
        }


    } while (input1 != 4);

}



