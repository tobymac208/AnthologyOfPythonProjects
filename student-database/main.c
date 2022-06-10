#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define TRUE 1

int main(void)
{
    while(TRUE)
    {
        int studentID;
        char studentName[20];
        char studentSubject[25];

        printf("What's your student's ID? ");
        scanf("%i", &studentID);

        printf("What's your student's name? ");
        scanf("%19s", studentName);

        printf("What's your student's subject? ");
        scanf("%24s", studentSubject);

        // authenticate
        char password[] = "abc123";
        char checkPassword[25];

        printf("Enter your password: ");
        scanf("%24s", checkPassword);

        // If the passwords are the same
        if(strcmp(password, checkPassword) == 0){
            // create the new record in the file
            const char FILENAME[35] = "student_records.txt";
            FILE *filePointer = fopen(FILENAME, "a");
            fprintf(filePointer, "%i,%s,%s\n", studentID, studentName, studentSubject);
            fclose(filePointer);

            // clear the terminal
            system("echo \"clearing screen\";sleep 1;clear");
        } else {
            printf("Invalid password. Record couldn't be added. \n");
        }
    }

    return 0;
}