/*
NOTES FROM 11/9/2022

Functions parameters default values with prototypes.
- The default value should be in the prototype
  and not in the function definition.
Multi-dimensional array parameters
- Always pass-by-reference (do not include &)
- All dimensions except the leftmost one must be defined.

Example:
int getAverage(double values[][100][256], int arraySize)
- May be a good idea to use vectors instead.
- Dynamic arrays coming in CS202

Command Line Arguments

- Command line arguments are collect by the system whenever
  a program is run and passed to the program.
- Command line arguments are whitespace delimited.

The program receives:
- The number of arguments (argc)
- The arguments in a c-style atring array (argv)

Change main:
int main(int argc, char* argv[])
// Array of c-style strings^^^ (argv[])

Converting strings to Numbers
- <cstdlib>
- int atoi(char[])
- double atof(char[])

Importing functions from another file
- g++ can compile multiple source code files
  simultaneously (or in parts)
- To use a function from another file, a function
  prototype must be used.

Example:
> g++ main.cpp functions.cpp -Wall -pedantic -o program.exe
(-o program.exe will create executable instead of a.out)

Header file
- Includes function prototypes, constants (later class\struct declarations)
- .h is file extension
- Added to programs via #include
- <> are used to look in library directory
- "" are used to look in current directory

Example in main.cpp:
#include "functions.h"

SEE PICTURES FOR MULTIPLE DEFINITIONS PROBLEM.

Preprocessor Directive
#ifndef identifier
   ^ #endif
If not defined:
#define identifier

Header Guard:
#ifndef h_functions
     #define h_functions
#endif
This ensure that the contents of a header file
only get copited by #include once.

*/