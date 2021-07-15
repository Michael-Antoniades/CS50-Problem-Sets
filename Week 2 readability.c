#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

string text; //user text input
int length; //length of # of characters in text
float L = 0; //number of letters, excluding spaces
float W = 1; //number of words start at 1, then count spaces for # of
           //words assuming we don't double space sentence ends and # of spaces is correct
float S = 0; //number of sentences similar performance to W, no punctuation we'll assume 1 sentence
float index = 0; //Equation for determining level
bool titlecheck = false; //trigger for subtraction of a sentence if a Mr. / Mrs. or Dr. title is input

int main(void)
{
    text = get_string("Text: ");
    length = strlen(text);

        for(int i = 0; i < length; i++)
        {
            if (text[i] != 32 && text[i] != 33 && text[i] !=46 && text[i] != 63 && text[i] != 39 && text[i]!= 44) //all things to not count
            {
                L += 1;
            }
            else if (text[i] == 32)
            {
                W += 1;
            }

            if (text[i] == 33 || text[i] == 46 || text[i] == 63 ) // 33 is ASCII !, 46 is ., and 63 is ?
            {
                S += 1;
                titlecheck = true;
            }
            else
            {
                titlecheck = false;
            }

            if ( titlecheck && ( ( (text[i-2] <= 90) && (text[i-2] >= 65) ) || ( (text[i-3] <= 90) && (text[i-3] >= 65) ) ) ) //to indicate a title by capital letter before a period
            {
                S -= 1;
            }
        }


    float AL = 100*L / W;
    float AS = 100*S/W;
    index = (0.0588 * AL) - (0.296 * AS) - 15.8;

    int grade = round(index);
    int ww = round(W);
    int ss = round(S);
    int ll = round(L);

if (grade <= 1 )
{
printf("You are grade 1 or stooopider.\n");
}
else if(grade >=2 && grade <= 16)
{
printf("Grade %i\n", grade);
}
else if(grade > 16){
printf("You Belong @ Harvard! Grade: 16+\n");
}

//printf("Length: %i\n", ll); //test for L properly working
//printf("Number of words: %i\n", ww); //test for W properly working
//printf("Number of sentences: %i\n", ss); //test for S properly working

}
