# Quick-cReverse

This project is an introductory exercise in generating and deleting dynamic variables in C. It is also an exercise in the methods of reading and writing with files. The code was written with a heavy eye to [GVSU's Style-Guide](http://www.cis.gvsu.edu/java-coding-style-guide/).

## Description

The program reads a text file and then outputs another text file with all of the characters in reverse order.

Command Execution:
```
./cReverse inputFile.txt outputFile.txt
```

Note. Running this command `export PATH=.:$PATH` allows us to execute the program as:
```
cReverse inputFile.txt outputFile.txt
```

## Compiling the Program

The following is a command to compile the C program on GVSU's CentOS machines. The "-std=c99" flag allows for intialization of ints within for() loops. The "-Wall" flag makes sure to show warnings on compiling.

```
gcc -Wall -o cReverse reverse.c fileUtils.c -std=c99
```

## Further Testing of Program

With the '-g' flag, you tell the compiler to include information for further debugging.
```
gcc -g -Wall -o cReverse reverse.c fileUtils.c -std=c99
```

Then we can run the following two commands to step through the program and log the output.

```
export MALLOC_TRACE=pick-a-name-of-your-choice-here.log
```
```
mtrace a.out name-you-chose-above.log
```
