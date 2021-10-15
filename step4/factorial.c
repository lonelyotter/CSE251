#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    int f;       /* Number we compute the factorial of */
    int fac = 1; /* Initial value of factorial */
    int f0;

    while (1)
    {
        printf("Number to compute the factorial of: ");
        scanf("%d", &f);
        if (f < 0)
        {
            break;
        }

        f0 = f;
        if (f == 0)
        {
            fac = 1;
        }
        while (f > 0)
        {
            fac = fac * f;
            f--;
        }

        printf("%d! = %d\n", f0, fac);
    }
}
