// compilation command:
// gcc Lab4.c -lm
// -lm maybe required to link the math library

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// read and store input function. Parameters CAN be *n, *k, *someTables
//      look back at lab 3 for dynamic allocation of arrays
//      read the input and put the numbers into array
//      probably a void function

// isolate digit in a integer function. Parameters CAN be integer, somePosition
//      look at modulo and dividing for isolating the digit
//      also becareful of situations you may be dividing by 0
//      probably a int function

// modified counting sort or whatever sort function. Parameters CAN be *sometables, *somePosition, *slot, *n, *k, *output
//      follow phases in notes, and follow exactly what weems says in the lab video
//
//      a possibly useful code outline:
//      phase 1
//      phase 2
//      phase 3
//      PROCESSING of new n and k, and the choosen digit
//      phase 4
//      overwrite the input array
//
//      don't forget to increase the position for digits

// driving main function.
//      declare and initialize things here
//      call your read and store input function
//      do some conditional loop with your modified counting sort in it
//      do some print statements for some things
//      don't forget to free your memory
