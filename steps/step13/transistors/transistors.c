#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
*/

int main()
{

    int i;
    Tran *trans;
    int numTrans = 0;
    bool flag = true;
    char buffer[100];

    printf("transistors!\n");

    /* Allocate space for one transistor */
    trans = malloc(sizeof(Tran));

    while (1)
    {
        trans[numTrans] = InputTransistor();
        numTrans++;

        printf("Would you like to enter another transistor (Y/N)?");
        do
        {
            /* Get a line of up to 100 characters */
            fgets(buffer, sizeof(buffer), stdin);

            /* Remove any stray newlines from the buffer */
            while (buffer[0] == '\n')
                fgets(buffer, sizeof(buffer), stdin);

            /* Remove any \n we may have input */
            if (strlen(buffer) > 0)
                buffer[strlen(buffer) - 1] = '\0';
            if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0)
            {
                trans = realloc(trans, sizeof(Tran) * (numTrans + 1));
            }
            else if (strcmp(buffer, "N") == 0 || strcmp(buffer, "n") == 0)
            {
                flag = false;
                break;
            }
        } while (strcmp(buffer, "Y") != 0 && strcmp(buffer, "N") != 0 && strcmp(buffer, "y") != 0 && strcmp(buffer, "n") != 0);

        if (flag == false)
        {
            break;
        }
    }

    /* Output the transistors */
    printf("\nThe transistors:\n");
    for (i = 0; i < numTrans; i++)
    {
        DisplayTransistor(trans[i]);
    }

    /* Free the memory */
    free(trans);
}
