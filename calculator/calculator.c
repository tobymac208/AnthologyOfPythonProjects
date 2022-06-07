#include "stdio.h"

int main(void)
{
    float firstOperand = 0, secondOperand = 0;
    char arithmeticOperator;
    char clearStream;

    // Take input for the numbers.
    printf("Give me the first number: ");
    scanf("%f", &firstOperand);

    printf("Give me the second number: ");
    scanf("%f", &secondOperand);

    // Take the operator
    printf("Give me the operator! ");
    // Clear the stream
    scanf("%c", &clearStream);
    scanf("%c", &arithmeticOperator);

    switch(arithmeticOperator)
    {
        case '+':
            printf("%.02f\n", firstOperand + secondOperand);
            break;
        case '-':
            printf("%.02f\n", firstOperand - secondOperand );
            break;
        case '*':
            printf("%.02f\n", firstOperand * secondOperand );
            break;
        case '/':
            printf("%.02f\n", firstOperand / secondOperand );
            break;
        default:
            printf("Invalid input. You'll have to try again! \n");
            break;
    }

    return 0;
}
