#include <stdio.h>
#include <cs50.h> // only include on ide.cs50.io text editor/terminal


int main(void) {

int p;

    do {

        p = get_int("Please input height of Mario's Pyramid (must be 1-8): ");

    }
    while (p < 1 || p >8 );


    for (int i = 0; i < p; i++){

        for (int j = p-1; j > i; j-- )
        {
            printf(" " );
        }

        for (int j = 0; j <= i; j++){
            printf("#");
        }

   printf("  ");
    for(int q = 0; q <= i; q++)
    {
        printf("#");
    }
    printf("\n");

}
}
