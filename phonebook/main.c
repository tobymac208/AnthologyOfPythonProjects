#include "stdio.h"
#include "string.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void writeRecord(const char[], const char[], long);
void searchRecord(const char[]); // Search the phonebook's records.
void viewPhonebook(const char[]); // Take a filename and grab all non-NULL records then read them.

int printMenuAndGetInput();
int decideWhatToDo(const char[], int); // passes a menu option to decide what to do.

int main(void) {
    int userChoice;
    const char FILENAME[] = "phonebook.data";

    // running flag
    int running = TRUE;

    // Authenticate the user.
    char username[26];
    char password[26];

    char correctUsername[26] = "nikf";
    char correctPassword[26] = "notaneasypassword";

    printf("Username: ");
    scanf("%25s", username);

    if( strcmp(username, correctUsername) == FALSE ) {
        printf("Password: ");
        scanf("%25s", password);

        if ( strcmp(password, correctPassword) == FALSE ) {
            printf("Login successful. Welcome back, %s.\n", username);
        } else {
            // password failed
            printf("The password failed. Try running again.\n");
            running = FALSE;
        }
    } else {
        // username failed
        printf("The username failed. Try running again.\n");
        running = FALSE;
    }

    while(running) { // print the menu
        userChoice = printMenuAndGetInput();
        int keepRunning = decideWhatToDo(FILENAME, userChoice);

        // A simpler way to handle whether to stop the loop or not.
        running = keepRunning;
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
    printf("0) Exit.\n");

    scanf("%i", &usersChoice);

    return usersChoice;
}

int decideWhatToDo(const char FILENAME[], int choice) {
    switch (choice) {
        case 1:
            viewPhonebook(FILENAME);
            return 1;
        case 2:
            writeRecord(FILENAME, "Billy", 6513360790);
            return 1;
        case 3:

            return 1;
        case 4:

            return 1;
        case 0:
            // Tell the program to stop.
            int running = FALSE;
            return running;
        default:
            printf("Well, that's not a valid option. You'll have to try again. \n");
            return 1;
    }
}
