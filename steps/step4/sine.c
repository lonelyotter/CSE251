#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    double angle;
    int numSteps;
    double maxAngle = M_PI * 2;
    int i;
    double sinVal = -1;
    int numSpaces;
    double derivative;

    do
    {
        printf("Input the number of steps: ");
        scanf("%d", &numSteps);
    } while (numSteps < 2);

    for (i = 0; i <= numSteps; i++)
    {

        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
        numSpaces = 30 + sinVal * 30;
        derivative = cos(angle);

        printf("%3d: %5.2f ", i, angle);
        for (int j = 0; j < numSpaces; j++)
        {
            printf(" ");
        }

        if (fabs(derivative) < 0.1)
        {
            printf("*\n");
        }
        else if (derivative > 0)
        {
            printf("\\\n");
        }
        else
        {
            printf("/\n");
        }
    }
}
