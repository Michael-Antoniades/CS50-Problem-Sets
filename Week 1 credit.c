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
        printf("INVALID\n");
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
            if( (ccnholder >= 34e15 && ccnholder < 35e13) || (ccnholder >= 37e15 && ccnholder < 38e15) )
            {
            printf("AMEX\n");
            }
            else if( (ccnholder >= 4e13 && ccn < 5e13) || ( ccnholder >= 4e16 && ccn < 5e16) )
            {
            printf("VISA\n");
            }
            else if(ccn >= 51e16 && ccn < 56e16)
            {
            printf("MASTERCARD\n");
            }
            else
            {
            printf("INVALID front 2 numbers");
            printf("%li\n", ccnholder);
            }
        }
        else
        {
            printf("INVALID from Alrogrithm\n");
            printf("%i\n", sum);

        }
    }
}
//correct needs testing
