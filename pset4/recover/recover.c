#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h> 
 
 
int main(int argc, char *argv[])
{
 if (argc == 1) {
     //main code
     typedef uint8_t BYTE; 
     
     
     FILE *file = fopen(argv[1], "r");
     
     fread(char *buffer[], BYTE ,512, file* )
     
     
 }
 
 else if (argc != 1) {
     return 1;
     fprintf("Only one argument at a time can be passed\n");
 }
}
