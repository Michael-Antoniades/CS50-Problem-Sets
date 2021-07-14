#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long ccn;
long numdigits;
int numsumtot;
int sum = 0;


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
        long ccnmath = ccn; //not necessary but ccn math will be variable changing instead of ccn

        for (int i = 0; ccnmath != 0; i++, ccnmath /= 10)
        {

            if( i % 2 == 0 )
            {
                sum += ccnmath % 10;
            }

            else
            {
                int seperator = 2 * (ccn % 10);
                sum += seperator / 10 + seperator % 10;
            }

        }


        if(sum % 10 == 0)
        {
            if( (ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13) )
            {
            printf("AMEX\n");
            }
            else if( (ccn >= 4e12 && ccn < 5e12) || ( ccn>= 4e15 && ccn < 5e15) )
            {
            printf("VISA\n");
            }
            else if(ccn >= 51e14 && ccn < 56e14)
            {
            printf("MASTERCARD\n");
            }
            else
            {
            printf("INVALID front 2 numbers");
            printf("%li\n", ccn);
            }
        }
        else
        {
            printf("INVALID from Alrogrithm\n");
        }
    }
}
//close to being done but no cigar yet algorithm section off
