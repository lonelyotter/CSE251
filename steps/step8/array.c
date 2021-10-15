#include <stdio.h>
#include <stdbool.h>

/* 
 * Name : <Insert name>
 * Program to experiment with arrays
 */
#define NumMovies 10
#define MaxGrosses 5

int main()
{
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                              "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                              "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                              "True Grit"};
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    double sum;
    int highestGrossIndex = 0;
    double highestGross = 0;
    bool isExist = false;

    for (int i = 0; i < NumMovies; i++)
    {
        printf("Movie %2d %33s: %.0f\n", i + 1, names[i], gross[i]);
    }

    sum = 0; /* Initialize to zero */
    for (int i = 0; i < NumMovies; i++)
    {
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);

    highestGross = 0;
    for (int i = 0; i < NumMovies; i++)
    {
        if (gross[i] > highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

    for (int i = 0; i < MaxGrosses; i++)
    {
        isExist = false;
        highestGross = 0;
        highestGrossIndex = 0;

        for (int j = 0; j < NumMovies; j++)
        {
            if (gross[j] > highestGross && gross[j] < maxGross[i])
            {
                isExist = true;
                highestGrossIndex = j;
                highestGross = gross[j];
            }
        }

        if (!isExist)
        {
            printf("No film made less than %f\n", maxGross[i]);
        }
        else
        {
            printf("The highest gross less than %.0f is %s at %.0f\n", maxGross[i], names[highestGrossIndex], highestGross);
        }
    }
}
