/******************************************
*Student name: Yedidya Peles
*Student ID:322638354
*Exercise name: ex_5
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
#define HIGHEST_OPTION 7
#define LOWEST_OPTION 1
#define DETAILS_LENGTH 11
#define FIRST_LETTER 'A'

//declaration on struct contact
typedef struct Contact {
    char *firstName;
    char *lastName;
    char *phoneNum;
    struct Contact *next;
} Contact;

/************************************************************************
* function name: printMenu
* The Input: void
* The output: void
* The Function operation: print the menu
*************************************************************************/
void printMenu() {
    printf("Welcome to the phone book manager!\n"
           "Choose an option:\n"
           "1. Add a new contact to the phone book.\n"
           "2. Delete a contact from the phone book.\n"
           "3. Find a contact in the phone book by phone number.\n"
           "4. Find a contact in the phone book by name.\n"
           "5. Update phone number for a contact.\n"
           "6. Print phone book.\n"
           "7. Exit.\n");
}


/************************************************************************
* function name: checkAllocation
* The Input: void *check (the new allocation)
* The output: 0==failed, 1==succeed
* The Function operation: check if the new allocation succeed
*************************************************************************/
int checkAllocation(void *check) {
    //if the allocation failed - print message and return 0
    if (check == NULL) {
        printf("The addition of the contact has failed!\n");
        return 0;
    }
    //the allocation succeed - return 1
    return 1;
}

/************************************************************************
* function name: addNewContact
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: add a new contact to the phone book.
*************************************************************************/
void addNewContact(Contact *phoneBook[SIZE]) {
    //local data before check and add
    char firstName[DETAILS_LENGTH];
    char lastName[DETAILS_LENGTH];
    char number[DETAILS_LENGTH];
    int locationLetter;
    printf("Enter a contact details "
           "(<first name> <last name> <phone number>): ");
    scanf("%s %s %s", firstName, lastName, number);
    locationLetter = ((int) lastName[0] - (int) FIRST_LETTER);
    Contact *checkContact = NULL;

    //check double name
    //check lastname letter
    checkContact = phoneBook[locationLetter];
    //check list in this letter
    while (checkContact != NULL) {
        if (strcmp(checkContact->firstName, firstName) == 0 &&
            strcmp(checkContact->lastName, lastName) == 0) {
            printf("The addition of the contact has failed,"
                   " since the contact %s %s already exists!\n", firstName,
                   lastName);
            return;
        }
        checkContact = checkContact->next;
    }

    //check double number
    for (int i = 0; i < SIZE; ++i) {
        //check each letter
        checkContact = phoneBook[i];
        //check list in this letter
        while (checkContact != NULL) {
            if (strcmp(checkContact->phoneNum, number) == 0) {
                printf("The addition of the contact has failed,"
                       " since the phone number %s already exists!\n", number);
                return;
            }
            checkContact = checkContact->next;
            //end of while loop
        }
    }

    //so the input is ok - now fill it

    //check if it is the first in the letter
    if (phoneBook[locationLetter] == NULL) {
        //create memory
        phoneBook[locationLetter] = (Contact *) malloc(sizeof(Contact));
        if (checkAllocation(phoneBook[locationLetter]) == 0) {
            // the allocation failed
            return;
        }
        phoneBook[locationLetter]->firstName =
                (char *) malloc(sizeof(char) * DETAILS_LENGTH);
        if (checkAllocation(phoneBook[locationLetter]->firstName) == 0) {
            // the allocation failed - free the new allocations
            free(phoneBook[locationLetter]);
            return;
        }
        phoneBook[locationLetter]->lastName =
                (char *) malloc(sizeof(char) * DETAILS_LENGTH);
        if (checkAllocation(phoneBook[locationLetter]->lastName) == 0) {
            // the allocation failed - free the new allocations
            free(phoneBook[locationLetter]->firstName);
            free(phoneBook[locationLetter]);
            return;
        }
        phoneBook[locationLetter]->phoneNum =
                (char *) malloc(sizeof(char) * DETAILS_LENGTH);
        if (checkAllocation(phoneBook[locationLetter]->phoneNum) == 0) {
            // the allocation failed - free the new allocations
            free(phoneBook[locationLetter]->lastName);
            free(phoneBook[locationLetter]->firstName);
            free(phoneBook[locationLetter]);
            return;
        }
        //enter the values
        strcpy(phoneBook[locationLetter]->firstName, firstName);
        strcpy(phoneBook[locationLetter]->lastName, lastName);
        strcpy(phoneBook[locationLetter]->phoneNum, number);
        phoneBook[locationLetter]->next = NULL;
        printf("The contact has been added successfully!\n");
        //end of first in the letter
    } else {
        //create memory
        Contact *newContact;
        newContact = (Contact *) malloc(sizeof(Contact));
        if (checkAllocation(newContact) == 0) {
            // the allocation failed
            return;
        }
        newContact->firstName = (char *) malloc(sizeof(char)
                                                * DETAILS_LENGTH);
        if (checkAllocation(newContact->firstName) == 0) {
            // the allocation failed - free the new allocations
            free(newContact);
            return;
        }
        newContact->lastName = (char *) malloc(sizeof(char)
                                               * DETAILS_LENGTH);
        if (checkAllocation(newContact->lastName) == 0) {
            // the allocation failed - free the new allocations
            free(newContact->firstName);
            free(newContact);
            return;
        }
        newContact->phoneNum = (char *) malloc(sizeof(char)
                                               * DETAILS_LENGTH);
        if (checkAllocation(newContact->phoneNum) == 0) {
            // the allocation failed - free the new allocations
            free(newContact->lastName);
            free(newContact->firstName);
            free(newContact);
            return;
        }
        //enter the values
        strcpy(newContact->firstName, firstName);
        strcpy(newContact->lastName, lastName);
        strcpy(newContact->phoneNum, number);
        newContact->next = phoneBook[locationLetter];
        phoneBook[locationLetter] = newContact;
        printf("The contact has been added successfully!\n");
    }
    //end of add new contact
}

/************************************************************************
* function name: deleteContact
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: delete a contact from the phone book.
*************************************************************************/
void deleteContact(Contact *phoneBook[SIZE]) {
    char firstName[DETAILS_LENGTH];
    char lastName[DETAILS_LENGTH];
    int locationLetter;
    char sure;
    Contact *checkContact = NULL;
    Contact *previewsContact = NULL;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s %s", firstName, lastName);
    locationLetter = ((int) lastName[0] - (int) FIRST_LETTER);
    //if the list is empty
    if (phoneBook[locationLetter] == NULL) {
        printf("The deletion of the contact has failed!\n");
        return;
    }

    //check lastname letter list
    previewsContact = phoneBook[locationLetter];
    checkContact = phoneBook[locationLetter];
    //check if he is the first
    if (strcmp(previewsContact->firstName, firstName) == 0 &&
        strcmp(previewsContact->lastName, lastName) == 0) {
        //the contact exist in the start of the list
        //check if he sure
        printf("Are you sure? (y/n) ");
        scanf(" %c", &sure);
        if (sure != 'y' && sure != 'Y') {
            printf("The deletion of the contact has been canceled.\n");
            return;
        }
        //connect previews and next
        phoneBook[locationLetter] = phoneBook[locationLetter]->next;
        //need to free previews
        free(previewsContact->firstName);
        free(previewsContact->lastName);
        free(previewsContact->phoneNum);
        free(previewsContact);
        printf("The contact has been deleted successfully!\n");
        return;
    }
    //check the rest of the list in this letter
    while (checkContact->next != NULL) {
        checkContact = checkContact->next;
        if (strcmp(checkContact->firstName, firstName) == 0 &&
            strcmp(checkContact->lastName, lastName) == 0) {
            //the contact found
            //check if he sure
            printf("Are you sure? (y/n) ");
            scanf(" %c", &sure);
            if (sure != 'y' && sure != 'Y') {
                printf("The deletion of the contact has been "
                       "canceled.\n");
                return;
            }
            //connect previews and next
            previewsContact->next = checkContact->next;
            //free checkContact
            free(checkContact->firstName);
            free(checkContact->lastName);
            free(checkContact->phoneNum);
            free(checkContact);
            printf("The contact has been deleted successfully!\n");
            return;
            //end of contact found
        }
        //checkContact = checkContact->next;
        previewsContact = previewsContact->next;
        //end of while loop
    }
    //the contact not exist
    printf("The deletion of the contact has failed!\n");
    //end of delete contact
}

/************************************************************************
* function name: searchNum
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: find a contact in the phone book by phone number.
*************************************************************************/
void searchNum(Contact *phoneBook[SIZE]) {
    char number[DETAILS_LENGTH];
    Contact *checkContact = NULL;
    printf("Enter a phone number: ");
    scanf("%s", number);
    for (int i = 0; i < SIZE; ++i) {
        //check each letter
        checkContact = phoneBook[i];
        //check list in this letter
        while (checkContact != NULL) {
            if (strcmp(checkContact->phoneNum, number) == 0) {
                printf("The following contact was found:"
                       " %s %s %s\n",
                       checkContact->firstName,
                       checkContact->lastName,
                       checkContact->phoneNum);
                return;
            }
            checkContact = checkContact->next;
            //end of while loop
        }
    }
    //the number not found
    printf("No contact with a phone number %s was found"
           " in the phone book\n", number);

    //end of search number
}

/************************************************************************
* function name: searchName
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: find a contact in the phone book by name.
*************************************************************************/
void searchName(Contact *phoneBook[SIZE]) {
    char firstName[DETAILS_LENGTH];
    char lastName[DETAILS_LENGTH];
    int locationLetter;
    Contact *checkContact = NULL;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s %s", firstName, lastName);
    locationLetter = ((int) lastName[0] - (int) FIRST_LETTER);
    //check lastname letter
    checkContact = phoneBook[locationLetter];
    //check list in this letter
    while (checkContact != NULL) {
        if (strcmp(checkContact->firstName, firstName) == 0 &&
            strcmp(checkContact->lastName, lastName) == 0) {
            //the contact exist
            printf("The following contact was found: %s %s %s\n",
                   firstName, lastName, checkContact->phoneNum);
            return;
        }
        checkContact = checkContact->next;
    }

    //the contact not exist
    printf("No contact with a name %s %s was found in the phone book\n",
           firstName, lastName);

    //end of search name
}

/************************************************************************
* function name: updateNumber
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: update phone number for a contact.
*************************************************************************/
void updateNumber(Contact *phoneBook[SIZE]) {
    int nameExist = 0;
    char firstName[DETAILS_LENGTH];
    char lastName[DETAILS_LENGTH];
    char number[DETAILS_LENGTH];
    int locationLetter;
    Contact *checkContact = NULL;
    Contact *updateNumber = NULL;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf("%s %s", firstName, lastName);
    locationLetter = ((int) lastName[0] - (int) FIRST_LETTER);

    //check if the contact exist
    //check lastname letter
    checkContact = phoneBook[locationLetter];
    //check list in this letter
    while (checkContact != NULL) {
        if (strcmp(checkContact->firstName, firstName) == 0 &&
            strcmp(checkContact->lastName, lastName) == 0) {
            //the contact exist
            printf("The following contact was found: %s %s %s\n",
                   firstName, lastName, checkContact->phoneNum);
            nameExist = 1;
            updateNumber = checkContact;
        }
        checkContact = checkContact->next;
    }
    //check if the contact not exist
    if (nameExist == 0) {
        printf("No contact with a name %s %s was found in the phone "
               "book\n", firstName, lastName);
        return;
    }
    //the name exist - enter the number
    printf("Enter the new phone number: ");
    scanf("%s", number);
    //check if the number exist
    for (int i = 0; i < SIZE; ++i) {
        //check each letter
        checkContact = phoneBook[i];
        //check list in this letter
        while (checkContact != NULL) {
            if (strcmp(checkContact->phoneNum, number) == 0) {
                printf("The update of the contact has failed, "
                       "since the phone number %s already exists!\n",
                       checkContact->phoneNum);
                return;
            }
            checkContact = checkContact->next;
            //end of while loop
        }
    }
    //the input is ok - update the number
    strcpy(updateNumber->phoneNum, number);
    printf("The contact has been updated successfully!\n");
    //end of update number
}

/************************************************************************
* function name: printPhoneBook
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: print phone book.
*************************************************************************/
void printPhoneBook(Contact *phoneBook[SIZE]) {
    Contact *checkContact = NULL;
    for (int i = 0; i < SIZE; ++i) {
        //check each letter
        checkContact = phoneBook[i];
        //check list in this letter
        while (checkContact != NULL) {
            printf("%-10s %-10s %s\n", checkContact->firstName,
                   checkContact->lastName, checkContact->phoneNum);
            checkContact = checkContact->next;
            //end of while loop
        }
    }
}

/************************************************************************
* function name: freeAll
* The Input: Contact *phoneBook[SIZE] (the phoneBook)
* The output: void
* The Function operation: free all the heap
*************************************************************************/
void freeAll(Contact *phoneBook[SIZE]) {
    Contact *checkContact = NULL;
    Contact *previewsContact = NULL;
    for (int i = 0; i < SIZE; ++i) {
        //check each letter
        checkContact = phoneBook[i];
        //check list in this letter
        while (checkContact != NULL) {
            previewsContact = checkContact;
            //save the next for now
            checkContact = checkContact->next;
            //free the previews
            free(previewsContact->firstName);
            free(previewsContact->lastName);
            free(previewsContact->phoneNum);
            free(previewsContact);
            //end of while loop
        }
        //end of for loop
    }
    //end of free all
}

int main() {
    //declaration and initialization of struct phoneBook
    Contact *phoneBook[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        phoneBook[i] = NULL;
    }
    int option = 0;
    while (option != 7) {
        printMenu();
        scanf("%d", &option);
        //check of wrong input
        while (option > HIGHEST_OPTION || option < LOWEST_OPTION) {
            printf("Wrong option, try again:\n");
            scanf("%d", &option);
        }
        switch (option) {
            //add a new contact to the phone book.
            case 1: {
                addNewContact(phoneBook);
                break;
            }
                //delete a contact from the phone book.
            case 2: {
                deleteContact(phoneBook);
                break;
            }
                //find a contact in the phone book by phone number.
            case 3: {
                searchNum(phoneBook);
                break;
            }
                //find a contact in the phone book by name.
            case 4: {
                searchName(phoneBook);
                break;
            }
                //update phone number for a contact.
            case 5: {
                updateNumber(phoneBook);
                break;
            }
                //print phone book.
            case 6: {
                printPhoneBook(phoneBook);
                break;
            }
                //7 - exit.
            default: {
                freeAll(phoneBook);
                printf("Bye!");
                break;
            }
                //end of switch
        }
        //end of while loop
    }
    //end of main
    return 0;
}