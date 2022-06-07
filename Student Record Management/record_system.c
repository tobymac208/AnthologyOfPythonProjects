#include "stdio.h"
#include <stdlib.h>

void writeRecords(char*, char[], int, char[]);

int main(void)
{
    // Defines how many records the loop should ask for.
    const int REQUEST_RECORDS = 2;

    // Create 5 student records
    for(int i = 0; i < REQUEST_RECORDS; i++)
    {
        printf("Enter information for record #%i \n", i+1);

        char name[15];
        int rollNumber;
        char subject[25];

        printf("Please enter your name: ");
        scanf("%s", name);

        printf("Roll number: ");
        scanf("%i", &rollNumber);

        printf("Subject: ");
        scanf("%s", subject);

        printf("Okay. So, your name is %s, you roll number is %i, and your subject is %s.\n", name, rollNumber, subject);

        writeRecords("student_record.txt", name, rollNumber, subject);   
    }

    return 0;
}

// Write records to a designated filename
void writeRecords(char* filename, char name[15], int age, char subject[])
{
    // Opens the desired file on "append" mode.
    FILE *filePointer = fopen(filename, "a");

    fprintf(filePointer, "%s %i %s\n", name, age, subject);

    // fclose calls the free() function and closes the file
    fclose(filePointer);
}
