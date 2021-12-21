#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long ccn;
long numdigits;
int numsumtot;


int main(void)
{


    ccn = get_long("Number: ");
    numdigits = log10(ccn) + 1;

    if(numdigits > 16 || numdigits < 13 || numdigits == 14)
    {
        printf("INVALID Length Error\n");
    }

    else
    {
        long ccnholder = ccn; //will hold ccn's value
        int sum = 0;
        for (int i = 0; ccn != 0; i++, ccn /= 10)
        {
            if( i % 2 == 0 )
            {
                sum += ccn % 10;
            }
            else
            {
                int seperator = 2 * (ccn % 10);
                sum += seperator / 10 + seperator % 10;
            }
        }


        if(sum % 10 == 0)
        {
            if( ((ccnholder >= 34e13) && (ccnholder < 35e13)) || ((ccnholder >= 37e13) && (ccnholder < 38e13)) )
            {
            printf("AMEX\n");
            }
            else if( ((ccnholder >= 4e12) && (ccnholder < 5e12)) || ( (ccnholder >= 4e15) && (ccnholder < 5e15)) )
            {
            printf("VISA\n");
            }
            else if((ccnholder >= 5.1e15) && (ccnholder < 5.6e15))
            {
            printf("MASTERCARD\n");
            }
            else
            {
            printf("INVALID Error 2\n");
            //printf("%li\n", ccnholder); //test line
            }
        }
        else
        {
            printf("INVALID Error 1\n");
            //printf("%i\n", sum); //test line
        }
    }
}
// Tested and functions exactly as required!
