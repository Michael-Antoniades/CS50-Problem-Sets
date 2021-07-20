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
int i;
int m;

string plainprompt;
string cipher;

int main( int args, string plain[])
{

    if (args == 1)
    {
        printf("Usage: ./substitution KEY\n");
    }
    else if (args == 2)
    {
        for (plainlength = 0, n = strlen(plain[1]); plainlength < n; plainlength++ )
        {
            //section for checking only alphabetic characters
            if (isalpha(plain[1][plainlength]) == false)
            {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
            }

        for (i =0; i < plainlength+1; i++) //this section to make sure no repeats present
        {
            if (isupper(plain[1][i]))
            {
                plain[1][i] = tolower(plain[1][i]);
            }
            for(m = 0; m < plainlength+1; m++)
            {

                if (plain[1][i] == plain[1][m])
                {
                    j++;
                }
            }
        }

        if (j >= 352 && plainlength == 25) //strange value for J tested with the below prints to see what different cases look like
        {
            printf("%i\n",j);
            printf("%i\n",i);
            printf("%i\n",m);
            printf("Repeated value, check the key %s\n", plain[1]);
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


    plainprompt = get_string("Plaintext: ");

    for (int q = 0; q < plainlength; q++)
    {
        if ((plain[1][q] <= 65 || plain[1][q] >= 97) == false)
        {
            //plain[1][n] ==
            cipher[q] = plain[1][n];

        }
    }
    printf("ciphertext: %s", cipher);



}



//incomplete still need to add algorithm but basic functionality is working as described so far
