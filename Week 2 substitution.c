//C program for CS50 week 2 arrays
//That takes 26 alphabetic characters as a key and then ciphers a plaintext based on them

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int j = 0; //pesky three variables had to declare outside of function for universal usage
int plainlength = 0;
int n = 0;


int main( int args, string plain[])
{

    if (args == 1)
    {
        printf("Usage: ./substitution KEY\n");
    }
    else if (args == 2)
    {
        for (plainlength = 0, n=strlen(plain[1]); plainlength < n; plainlength++ )
        {
            //section for checking that we only use alphabetic characters
            if (isalpha(plain[1][plainlength]) == false)
            {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
            }

        for (int i =0; i < plainlength; i++) //this section to make sure no repeats present
        {
            for(int m = 0; m < plainlength; m++)
            {
                if (plain[1][i] == plain[1][m])
                {
                    j++;
                }
            }
        }

        if (j >= 1 && plainlength ==25)
        {
            printf("Repeated value, check the key\n");
            return 1;
        }                                   //end section

            if (plainlength == 25 && j == 0 )
            {
                printf("wedid itt we did itt joeeeee\n");
                return 0;
            }
            else if (plainlength == strlen(plain[1])-1 && plainlength != 25)
            {
                printf("Key must contain 26 characters\n");
                return 1;
            }
        }
    }
    else
    {
         printf("Usage: ./substitution KEY\n");
         return 1;
    }
}

//incomplete still need to add algorithm but basic functionality is working as described so far
