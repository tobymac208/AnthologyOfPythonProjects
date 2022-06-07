#include "stdio.h"

void writeRecords(char*);

int main(void)
{
    writeRecords("record_system.txt");

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
