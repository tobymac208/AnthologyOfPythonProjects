#include "stdio.h"
#include <stdlib.h>

void writeRecords(char*, char[], int, float);

int main(void)
{
    // Create 5 student records
    for(int i = 0; i < 5; i++)
    {
        printf("Enter information for record #%i \n", i+1);

        char name[15];
        int age;
        float gpa;

        printf("Please enter your name: ");
        scanf("%s", name);

        printf("How old are you? ");
        scanf("%i", &age);

        printf("Ok, finally %s, what's your current GPA? ", name);
        scanf("%f", &gpa);

        printf("Okay. So, your name is %s, you're %i, and your GPA is %0.1f.\n", name, age, gpa);

        writeRecords("student_record.txt", name, age, gpa);   
    }

    return 0;
}

// Write records to a designated filename
void writeRecords(char* filename, char name[15], int age, float gpa)
{
    // Opens the desired file on "append" mode.
    FILE *filePointer = fopen(filename, "a");

    fprintf(filePointer, "%s %i %0.2f\n", name, age, gpa);

    // fclose calls the free() function and closes the file
    fclose(filePointer);
}
