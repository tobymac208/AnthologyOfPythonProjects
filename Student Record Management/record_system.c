#include "stdio.h"
#include <stdlib.h>

void writeRecords(char*);

int main(void)
{
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

    return 0;
}

// Write records to a designated filename
void writeRecords(char* filename)
{
    FILE *filePointer = fopen(filename, "w");

    fprintf(filePointer, "%s %0.2f", "We are mighty!", 2.0);

    // fclose calls the free() function and closes the file
    fclose(filePointer);
}
