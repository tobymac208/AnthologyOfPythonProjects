#include "stdio.h"
#include "string.h"
#include <stdio.h>

#define TRUE 1

void writeRecord(const char[], const char[], long);
void searchRecord(const char[]); // Search the phonebook's records.
void viewPhonebook(const char[]); // Take a filename and grab all non-NULL records then read them.

int printMenuAndGetInput();
void decideWhatToDo(const char[], int); // passes a menu option to decide what to do.

int main(void) {
    int userChoice;
    const char FILENAME[] = "phonebook.data";

    while(TRUE) { // print the menu
        userChoice = printMenuAndGetInput();
        decideWhatToDo(FILENAME, userChoice);
    }
}

void writeRecord(const char filename[], const char name[], long number) {
    FILE * filePointer = fopen(filename, "a");

    fprintf(filePointer, "%s %li\n", name, number);
    
    fclose(filePointer);
}

void viewPhonebook(const char filename[]) {
    FILE *filePointer = fopen(filename, "r");

    // Read 255 characters until the buffer hits a newline character or EOF.
    char buffer[255];

    // Read until return of fgets is NULL
    while(fgets(buffer, 255, (FILE *)filePointer)) {
        // it grabbed one line!
        printf("Name and number: %s", buffer);
    }

    fclose(filePointer);
}

// This function's job is to decide what the user would like to do.
int printMenuAndGetInput() {
    int usersChoice;

    printf("1) View phonebook. \n");
    printf("2) Add phonebook record. \n");
    printf("3) Edit record.\n");
    printf("4) Delete record.\n");

    scanf("%i", &usersChoice);

    return usersChoice;
}

void decideWhatToDo(const char FILENAME[], int choice) {
    switch (choice) {
        case 1:
            viewPhonebook(FILENAME);
            break;
        case 2:
            writeRecord(FILENAME, "Billy", 6513360790);
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("Well, that's not a valid option. You'll have to try again. \n");
            break;
    }
}
