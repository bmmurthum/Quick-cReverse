#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>   // for checking a filesize

#include "fileUtils.h"


/***********************************************************************

int read_file() 

    This takes in a "string" of a file name and a pointer to a space to
    store the read characters from the file.

    Within this method, the file-pointer is estabished to allow for 
    reading to memory. The memory-pointer to the space in the heap is
    also allocated a certain space of memory within this method.

    - Returns -1 on ERROR
    - Returns INT of characters in file if successful

***********************************************************************/
int read_file( char* filename, char** buffer ) {

    /* Input file pointer */
    FILE* inputFile;
    /* Number of character in the input file */
    int sizeOfFile;
    /* To area to store characters read from file */
    char* characterArray;
    /* Numer of characters currently read from the file to memory */
    int numberRead;
    /* A help variable in reading from file to memory */
    char c;

    /* Open the input file */
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        // ERROR - No file named as inputFileString - Did NOT open
        fprintf( stderr, "ERROR: could not read input file!\n" );        
        return(-2);    
    }

    /* Read the size of the input file */
    struct stat st;
    stat(filename, &st);
    sizeOfFile = st.st_size;

    /* Read each character to a dynamic array (size = filesize) */
    characterArray = (char*)malloc(sizeOfFile * sizeof(char));    
    *buffer = characterArray;

    /* The following while() with help from TUTORIALSPOINT.COM */
    numberRead = 0;   
    while(1) {
        c = fgetc(inputFile);
        if(feof(inputFile)) { 
            break;
        }
        characterArray[numberRead] = c;
        numberRead++;
    }

    /* Close the inputfile */
    if (fclose(inputFile) != 0)
    {
	    // ERROR - Did NOT close inputFile successfully
        fprintf( stderr, "ERROR: trouble in closing inputFile!\n" );        
        return(-1);
    }

    return sizeOfFile;

}


/***********************************************************************

int write_file() 

    This takes in a "string" of a file name, a pointer to the space
    that is storing the read-in characters, and the size of the 
    initial file (and our number of characters in memory)

    Within this method, the file-pointer is estabished to allow for 
    reading to memory. The memory-pointer to the space in the heap is
    also allocated a certain space of memory within this method.

    This method writes the characters stored in memory, that "buffer"
    points to, into a file in backwards order of how they are stored
    in memory.

    - Returns -1 on ERROR
    - Returns INT of characters written to file, if no other errors

***********************************************************************/
int write_file( char* filename, char *buffer, int size) {

    /* Output file pointer */
    FILE* outputFile;
    /* Number of characters written from memory to file */
    int numberWritten = 0;

    /* Open the output file for editting */
    outputFile = fopen(filename, "w");

    /* Write the characters to output file */
    for(int i = size-1; i >= 0; i--) {
        fputc(buffer[i], outputFile);
        numberWritten++;
    }

    /* Close the inputfile */
    if (fclose(outputFile) != 0)
    {
	    // ERROR - Did NOT close inputFile successfully
        fprintf( stderr, "ERROR: trouble in closing outputFile!\n" );        
        return(-1);
    }

    return numberWritten;

}
