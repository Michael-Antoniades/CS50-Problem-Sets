#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

int main(int argc, char *argv[])

{
     //argc has 2 calls, one by default and one to the program itself
     //main code

     if (argc != 2) {
     printf("Usage: ./recover card.raw");
     return 1;
     }



     FILE *file = fopen(argv[1], "r");


     if (file == NULL)
     {
     printf("Error: cannot open file\n");
     return 2;
     }

     unsigned char buffer[512];


     //will count how many images
     int count = 0;

     FILE *jpeg = NULL; //file we will be writing to

     char *filename = malloc(8 * sizeof(char));
     //char filename[8];

     while (fread(buffer, sizeof(char) ,512, file))
     {

      if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

       sprintf(filename, "%03i.jpg", count);

       jpeg = fopen(filename,"w");

       count++;
      }

      if (jpeg != NULL) {
      fwrite(&buffer, sizeof(char), 512, jpeg);
      }

      }


 free(filename);
 fclose(file);
 fclose(jpeg);

 return 0;

}
