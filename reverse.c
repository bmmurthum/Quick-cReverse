#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "fileUtils.h"  // for my written functions

/***********************************************************************

@author Brendon Murthum
@version Fall 2017

This program reads a text file and then outputs
anouther text file with all of the text reversed.

Assignment
 https://github.com/irawoodring/343/blob/master/assignments
 /reverse-file-in-c.md
References
  Tutorialspoint.com
    https://www.tutorialspoint.com/c_standard_library
    /c_function_fopen.htm
    - This is a simple small loop on reading char by char from file

***********************************************************************/

// Use this to output error messages!
// fprintf( stderr, "ERROR MESSAGE" );


int main(int argc, char** argv) {

    /* For handling the allocated memory */
    char* buffer;
    /* Size of input file - This will aid in allocating memory*/
    int sizeOfFile;
    /* Number of characters successfully written to file from memory */
    int numberWritten;
    /* Name of the input file  to read from */
    char* inputFileString;
    /* Name of the output file to write to */
    char* outputFileString;
    /* The number of characters read into our dynamic char array */
    int numberRead;
    /* To keep track of if buffer has allocated memory */
    int bufferHasMemory = 0;


    /*******************************************************************
    This checks to see that the correct number of arguments were passed.
    On success, it also sets the names of the input and output files.
    *******************************************************************/
    if ( argc == 3 ) {
	    inputFileString = argv[1];
	    outputFileString = argv[2];
    }
    else {
	    /* ERROR - Wrong number of arguments */
        errno = EINVAL;
        fprintf( stderr, "ERROR: wrong number of arguments!\n" ); 
        return(-1);    
    }

    /* Read input file into memory */
    sizeOfFile = read_file(inputFileString, &buffer);
    if (sizeOfFile == -2) {
        /* ERROR - Input file never read to memory */
        printf("\nQuitting program due to error!\n");
        exit(0);   
    }
    else if (sizeOfFile == -1) {
        /* ERROR - Memory was allocated, but inputfile did not close */
        printf("\nQuitting program due to error!\n");
        free(buffer);
        exit(0);  
    }
    else {
        bufferHasMemory = 1;
    }

    /* Write from memory to the file, backwards */
    numberWritten = write_file(outputFileString, buffer, sizeOfFile);

    /* ERROR - Not all characters written to file */
    if (numberWritten < sizeOfFile) {
        fprintf( stderr, "ERROR: not all chars written to file!\n" );
        printf("Bytes written backwards to file: %i / %i \n", 
            numberWritten, sizeOfFile);
    }

    /* Return memory */
    if (bufferHasMemory == 1) {
        free(buffer);
    }

}
