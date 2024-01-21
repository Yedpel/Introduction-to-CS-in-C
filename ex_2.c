/******************************************
* Student name: Yedidya Peles
* Student: 322638354
* Exercise name: ex_2
******************************************/



#include <stdio.h>
#include  <math.h>

#define OCT_REM 10
#define OCT_DEV 10
#define BINAR_THOUSAND 1000
#define BINAR_DEV 10
#define HEX_DEV4 4
#define HEX_REM4 4
#define BINAR_TEN_TOUSAND 10000
#define NUM1_REM_TEN 10
#define NUM1_DEV_TEN 10
#define NUM2_REM_TEN 10
#define NUM2_DEV_TEN 10
#define REM2_DEC_TO_BIN 2
#define DEV2_DEC_TO_BIN 2
#define MUL10_DEC_TO_BIN 10
#define BINARY_REM 10
#define BINARY_DEV 10
#define BIN6_DEV 10
#define BIN6_REM 10


int main() {
    int recived;
    int octalRec;
    int octalCheck;
    int octalLength;
    int binar;
    int octalNow;
    int octalDigit;
    int binarDigit;
    int power;
    int binarNow;
    char hexDigit;
    int hexLentgh;
    int binarLentgh;
    int num1Bad;
    int num2Bad;
    int num1Lentgh;
    int num2Lentgh;
    unsigned long long num1;
    unsigned long long num2;
    unsigned long long num1Check;
    unsigned long long num2Check;
    int ten1;
    int t;
    int rem1;
    unsigned long long num1convert;
    int ten2;
    int k;
    int rem2;
    unsigned long long num2convert;
    int sumTen;
    unsigned long long sumBin;
    int remSum;
    int m;
    int hef1;
    int hef2;
    unsigned long x;
    int binary;
    int binaryLength;
    int binaryCheck;
    int bit1;
    int invalidInput;
    int dec;
    int bin5;
    int decTrans;
    int remDec;
    int n;
    int dec6;
    int bin6;
    int bin6Check;
    int bool;
    int remDec6;
    int n6;

    //print menu
    do {
        printf("Choose an option:\n");
        printf("1. octal to hex\n");
        printf("2. binary addition\n");
        printf("3. print HI\n");
        printf("4. count bits\n");
        printf("5. decimal to binary\n");
        printf("6. Zig-Zag bits\n");
        printf("7. exit\n");
        scanf("%d", &recived);
        // end
        if (recived == 7)
        {
            printf("Bye!\n");
            break;
        }
        //invalid option
        if (recived < 1 || recived > 7)
        {
            printf("Invalid option!\n");
            continue;
        }
        // 1 - octal to hex
        if (recived == 1)
        {
            printf("Please enter number in octal base: ");
            scanf("%d", &octalRec);
            octalCheck = octalRec;
            octalLength = 0;
            //invalid input and octalLength
            do {
                if ((octalCheck % OCT_REM) > 7 ||
                    (octalCheck % OCT_REM) < 0) {
                    printf("Invalid input!\n");
                    break;
                } else (octalCheck /= OCT_DEV);
                octalLength++;
            } while (octalCheck > 0);
            //octal to binar
            if (octalCheck == 0) {
                octalNow = octalRec;
                binar = 0;
                for (int i = 1; i <= octalLength; i++) {
                    octalDigit = octalNow % OCT_REM;
                    octalNow /= OCT_DEV;
                    switch (octalDigit) {
                        case 0:
                            binarDigit = 000;
                            break;
                        case 1:
                            binarDigit = 001;
                            break;
                        case 2:
                            binarDigit = 10;
                            break;
                        case 3:
                            binarDigit = 11;
                            break;
                        case 4:
                            binarDigit = 100;
                            break;
                        case 5:
                            binarDigit = 101;
                            break;
                        case 6:
                            binarDigit = 110;
                            break;
                        case 7:
                            binarDigit = 111;
                            break;
                        default:
                            break ;
                    }
                    power = (int)pow(BINAR_THOUSAND, octalLength - i);
                    binar += (binarDigit * power);
                }
                binarNow = binar;
                binarLentgh = binar;
                hexLentgh = 0;
                //hexlength
                while (binarLentgh > 0) {
                    binarLentgh /= BINAR_DEV;
                    hexLentgh++;
                }
                //bytes of hex
                if (hexLentgh % HEX_REM4 == 0)
                    hexLentgh /= HEX_DEV4;
                else
                    hexLentgh = ((hexLentgh / HEX_DEV4) + 1);
                //binar to hex
                for (int i = 1; i <= hexLentgh; ++i) {
                    binarDigit = binarNow /
                            ((int)pow(BINAR_TEN_TOUSAND, hexLentgh - i));
                    binarNow = binarNow % (long)
                            (pow(BINAR_TEN_TOUSAND, hexLentgh - i));
                    switch (binarDigit) {
                        case 0:
                            hexDigit = '0';
                            printf("%c", hexDigit);
                            break;
                        case 1:
                            hexDigit = '1';
                            printf("%c", hexDigit);
                            break;
                        case 10:
                            hexDigit = '2';
                            printf("%c", hexDigit);
                            break;
                        case 11:
                            hexDigit = '3';
                            printf("%c", hexDigit);
                            break;
                        case 100:
                            hexDigit = '4';
                            printf("%c", hexDigit);
                            break;
                        case 101:
                            hexDigit = '5';
                            printf("%c", hexDigit);
                            break;
                        case 110:
                            hexDigit = '6';
                            printf("%c", hexDigit);
                            break;
                        case 111:
                            hexDigit = '7';
                            printf("%c", hexDigit);
                            break;
                        case 1000:
                            hexDigit = '8';
                            printf("%c", hexDigit);
                            break;
                        case 1001:
                            hexDigit = '9';
                            printf("%c", hexDigit);
                            break;
                        case 1010:
                            hexDigit = 'A';
                            printf("%c", hexDigit);
                            break;
                        case 1011:
                            hexDigit = 'B';
                            printf("%c", hexDigit);
                            break;
                        case 1100:
                            hexDigit = 'C';
                            printf("%c", hexDigit);
                            break;
                        case 1101:
                            hexDigit = 'D';
                            printf("%c", hexDigit);
                            break;
                        case 1110:
                            hexDigit = 'E';
                            printf("%c", hexDigit);
                            break;
                        case 1111:
                            hexDigit = 'F';
                            printf("%c", hexDigit);
                            break;
                        default:
                            break;
                    }
                }
                printf("\n");
            }
        }
        //2 - binary addition
        if (recived == 2) {
            printf("Please enter two binary numbers: ");
            scanf("%llu", &num1);
            scanf("%llu", &num2);
            if (num1 == 0 && num2 == 0) {
                printf("0 + 0 = 0\n");
                continue;
            }
            num1Check = num1;
            num1Lentgh = 0;
            num1Bad = 0;
            //num1 check and length
            while (num1Check > 0)
            {
                if (num1Check % NUM1_REM_TEN != 0 &&
                    num1Check % NUM1_REM_TEN != 1) {
                    printf("Invalid input!\n");
                    num1Bad = 1;
                    break;
                }
                num1Lentgh++;
                num1Check /= NUM1_DEV_TEN;
            }
            //invalid input-back to menu
            if (num1Bad == 1)
                continue;
            num2Check = num2;
            num2Lentgh = 0;
            num2Bad = 0;
            //num2 check and length
            while (num2Check > 0)
            {
                if (num2Check % NUM2_REM_TEN != 0 &&
                    num2Check % NUM2_REM_TEN != 1) {
                    printf("Invalid input!\n");
                    num2Bad = 1;
                    break;
                }
                num2Check /= NUM1_DEV_TEN;
                num2Lentgh++;
            }
            //invalid input-back to menu
            if (num2Bad == 1)
                continue;
            num1convert = num1;
            ten1 = 0;
            t = 0;
            //num1 to dec
            while (num1convert != 0) {
                rem1 = (int)num1convert % NUM1_REM_TEN;
                num1convert /= NUM1_DEV_TEN;
                ten1 += rem1 * (int)pow(2, t);
                t++;
            }
            num2convert = num2;
            ten2 = 0;
            k = 0;
            //num2 to dec
            while (num2convert != 0) {
                rem2 = (int)num2convert % NUM2_REM_TEN;
                num2convert /= NUM2_DEV_TEN;
                ten2 += rem2 * (int)pow(2, k);
                k++;
            }
            sumTen = ten1 + ten2;
            sumBin = 0;
            m = 1;
            //sumten to binar
            while (sumTen != 0) {
                remSum = sumTen % REM2_DEC_TO_BIN;
                sumTen /= DEV2_DEC_TO_BIN;
                sumBin += remSum * m;
                m *= MUL10_DEC_TO_BIN;
            }
            //print with padding 0
            if (num1Lentgh > num2Lentgh) {
                hef1 = num1Lentgh - num2Lentgh;
                printf("%llu\t +", num1);
                for (int i = 0; i < hef1; ++i) {
                    printf("0");
                }
                printf("%llu\t = %llu\n", num2, sumBin);
            } else if (num2Lentgh > num1Lentgh) {
                hef2 = num2Lentgh - num1Lentgh;
                for (int i = 0; i < hef2; ++i) {
                    printf("0");
                }
                printf("%llu + %llu = %llu\n", num1, num2, sumBin);
            } else
                printf("%llu + %llu = %llu\n", num1, num2, sumBin);
        }
        //print HI
        if (recived == 3) {
            printf("Please enter size: ");
            scanf("%lu", &x);
            if ((0 > (int) x)) {
                printf("Invalid input!\n");
                continue;
            }
            printf("#");
            for (int j = 0; j < x; ++j) {
                printf("#");
            }
            printf("#");
            printf(" ");
            for (int i = 0; i < x; ++i) {
                printf(" ");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            printf("#");
            printf("  ");
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            //end row 1
            printf("#\n");
            for (int i = 0; i < x; ++i) {
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                printf("#");
                printf(" ");
                for (int j = 0; j < x; ++j) {
                    printf(" ");
                }
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                printf("#");
                printf("  ");
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                //end part 2
                printf("#\n");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            printf("##");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            printf("#  #");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            //end part 3
            printf("#\n");
            for (int i = 0; i < x; ++i) {
                printf("#");
                for (int j = 0; j < ((x * 3) + 3); ++j) {
                    printf("*");
                }
                printf("#  #");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                //end part 4
                printf("#\n");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            printf("##");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            printf("#  #");
            for (int i = 0; i < x; ++i) {
                printf("*");
            }
            //end part 5
            printf("#\n");
            for (int i = 0; i < x; ++i) {
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                printf("#");
                printf(" ");
                for (int j = 0; j < x; ++j) {
                    printf(" ");
                }
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                printf("#");
                printf("  ");
                printf("#");
                for (int j = 0; j < x; ++j) {
                    printf("*");
                }
                //end part 6
                printf("#\n");
            }
            printf("#");
            for (int j = 0; j < x; ++j) {
                printf("#");
            }
            printf("#");
            printf(" ");
            for (int i = 0; i < x; ++i) {
                printf(" ");
            }
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            printf("#");
            printf("  ");
            printf("#");
            for (int i = 0; i < x; ++i) {
                printf("#");
            }
            //end row 7
            printf("#\n");
        }
        //count bits
        if (recived == 4) {
            printf("Please enter a binary number: ");
            scanf("%d", &binary);
            binaryCheck = binary;
            binaryLength = 0;
            invalidInput = 0;
            //invaid input and binarylength
            while (binaryCheck > 0)
            {
                if (binaryCheck % BINARY_REM != 0
                    && binaryCheck % BINARY_REM != 1) {
                    printf("Invalid input!\n");
                    invalidInput = 1;
                    break;
                }
                binaryCheck /= BINARY_DEV;
                binaryLength++;
            }
            //invalid input-back to menu
            if (invalidInput == 1)
                continue;
            binaryCheck = binary;
            bit1 = 0;
            //count bits
            while (binaryCheck > 0) {
                if (binaryCheck % BINARY_REM == 1) { bit1++; }
                binaryCheck /= BINARY_DEV;
            }
            printf("%d\n", bit1);
        }
        // decimal to binary
        if (recived == 5) {
            printf("Enter a non negative decimal number: ");
            scanf("%d", &dec);
            //invalid input-back to menu
            if (dec < 0) {
                printf("Invalid input!\n");
                continue;
            }
            decTrans = dec;
            bin5 = 0;
            n = 1;
            // decimal to binary
            while (decTrans != 0) {
                remDec = decTrans % REM2_DEC_TO_BIN;
                decTrans /= DEV2_DEC_TO_BIN;
                bin5 += remDec * n;
                n *= MUL10_DEC_TO_BIN;
            }
            printf("%d => %d\n", dec, bin5);
        }
        //Zig-Zag bits
        if (recived == 6) {
            printf("Enter a non negative decimal number: ");
            scanf("%d", &dec6);
            //invalid input-back to menu
            if (dec6 < 0) {
                printf("Invalid input!\n");
                continue;
            }
            int decTrans6 = dec6;
            bin6 = 0;
            n6 = 1;
            bool = 1;
            // decimal to binary
            while (decTrans6 != 0) {
                remDec6 = decTrans6 % REM2_DEC_TO_BIN;
                decTrans6 /= DEV2_DEC_TO_BIN;
                bin6 += remDec6 * n6;
                n6 *= MUL10_DEC_TO_BIN;
            }
            //1bit = zigzag
            if (bin6 / BIN6_DEV == 0)
                printf("true\n");
            else {
                bin6Check = bin6;
                //check not zigzag
                while (bin6Check > 0) {
                    if (bin6Check % BIN6_REM ==
                        (bin6Check / BIN6_DEV) % BIN6_REM) {
                        printf("false\n");
                        bool = 0;
                        break;
                    } else {
                        bin6Check /= BIN6_DEV;
                    }
                }
                //if !(not zigzag) = zig zag
                if (bool == 1)
                    printf("true\n");
            }
        }
        //if 7 - end
    } while (recived != 7);
    return 0;
}