#ifndef _FILE_UTILITY_
#define _FILE_UTILITY_


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
int read_file( char* filename, char **buffer );


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
int write_file( char* filename, char *buffer, int size);


#endif
