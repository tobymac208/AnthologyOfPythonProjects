#include "stdio.h"
#include <stdlib.h>

void writeRecords(char*, char[], int, char[]);
void writeStudent(struct Students);
// Takes a string and calculates its length.
int calculateStringLength(char[]);

int main(void)
{
    // Define a student structure
    struct Students {
        int rollNumber;
        char name[20];
        char fieldOfStudy[30];
    };

    while(1)
    {
        char userChoice[20];

        printf("Welcome to the student records system! What would you like to do? \n");
        // TODO: add, search, change, and remove entries
        printf("Add, Search, Change, Remove, Exit. \n");

        // Avoid buffer overflow and overrun by limiting the input.
        scanf("%19s", userChoice);

        // Check user input
        if(userChoice == "Add")
        {
            printf("Add User \n");

            // Create a structure to better organze what our "student" will be.
            struct Students Student;

            printf("Student's roll number (ID): ");
            scanf("%i", Student.rollNumber);

            printf("Student's name: ");
            scanf("%19s", Student.name);

            printf("Student's field of study: ");
            scanf("%29s", Student.fieldOfStudy);

            // Peform input validation!
            if(rollNumber == NULL || calculateStringLength(Student.name) < 1 || calculateStringLength(Student.fieldOfStudy) < 1) {
                printf("\"%i, %s, %s\" something is invalid in your input. Can't accept it!", Student.rollNumber, Student.name, Student.fieldOfStudy);
            } else
                writeUser(Student); // Pass the whole student structure
        }
        else if(userChoice == "Search")
            // queryStudent(); // TODO: Declare queryStudent
        else if(userChoice == "Change")
            // modifyStudent(); // TODO: Declare modifyStudent
        else if(userChoice == "Remove")
            // removeStudent(); // TODO Declare modifyStudent
        else if(userChoice == "Exit")
        {
            printf("Goodbye. \n");
            break; // leave the loop
        }
    }

    // // Defines how many records the loop should ask for.
    // const int REQUEST_RECORDS = 2;

    // // Create 5 student records
    // for(int i = 0; i < REQUEST_RECORDS; i++)
    // {
    //     printf("Enter information for record #%i \n", i+1);

    //     char name[15];
    //     int rollNumber;
    //     char subject[25];

    //     printf("Please enter your name: ");
    //     scanf("%s", name);

    //     printf("Roll number: ");
    //     scanf("%i", &rollNumber);

    //     printf("Subject: ");
    //     scanf("%s", subject);

    //     printf("Okay. So, your name is %s, you roll number is %i, and your subject is %s.\n", name, rollNumber, subject);

    //     writeRecords("student_record.txt", name, rollNumber, subject);   
    // }

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

void writeStudent(struct Students student)
{
    FILE *filePointer = fopen("student_record.txt", "a");
    
    fprintf(filePointer, "%i,%s,%s", student.rollNumber, student.name, student.fieldOfStudy);

    fclose(filePointer);
}

int calculateStringLength(char value[])
{
    return sizeof(value)/sizeof(value[0]);
}