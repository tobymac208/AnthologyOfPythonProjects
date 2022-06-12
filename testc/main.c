#include "stdio.h"

int main(void){
    char firstName[50];

    printf("Enter your name: ");
    fgets(firstName, 50, stdin);

    printf("Your name is %s", firstName);
    puts(firstName);
}
