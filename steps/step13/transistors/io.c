#include <stdio.h>
#include <string.h>
#include "transistors.h"

void DisplayTransistor(Tran tran)
{
    printf("Number: %s\n", tran.number);
    switch (tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;

    case PNP:
        printf("Type: PNP\n");
        break;
    }

    printf("Case style: ");
    switch (tran.caseStyle)
    {
    case TO18:
        printf("TO18\n");
        break;

    case TO92A:
        printf("TO92A\n");
        break;

    case TO92C:
        printf("TO92C\n");
        break;

    case TO220:
        printf("TO220\n");
        break;

    case TO39:
        printf("TO39\n");
        break;

    default:
        break;
    }

    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);
}

void InputString(char *str, int max)
{
    char buffer[100];

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max - 1] = '\0';
}

double InputPositiveValue(char *prompt)
{
    char buffer[100];
    double value = 0;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%lf", &value);
    } while (value <= 0);

    return value;
}

int InputTransistorType(char *prompt)
{
    char buffer[100];

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any stray newlines from the buffer */
        while (buffer[0] == '\n')
            fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
    } while (strcmp(buffer, "PNP") != 0 && strcmp(buffer, "NPN") != 0);

    if (strcmp(buffer, "PNP") == 0)
    {
        return PNP;
    }
    else
    {
        return NPN;
    }
}

int InputTransistorCaseStyle(char *prompt)
{
    char buffer[100];

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any stray newlines from the buffer */
        while (buffer[0] == '\n')
            fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
    } while (strcmp(buffer, "TO18") != 0 && strcmp(buffer, "TO92A") != 0 && strcmp(buffer, "TO92C") != 0 && strcmp(buffer, "TO220") != 0 && strcmp(buffer, "TO39") != 0);

    if (strcmp(buffer, "TO18") == 0)
    {
        return TO18;
    }
    else if (strcmp(buffer, "TO92A") == 0)
    {
        return TO92A;
    }
    else if (strcmp(buffer, "TO92C") == 0)
    {
        return TO92C;
    }
    else if (strcmp(buffer, "TO220") == 0)
    {
        return TO220;
    }
    else
    {
        return TO39;
    }
}

Tran InputTransistor()
{
    struct Transistor t1;
    printf("Input number: ");
    InputString(t1.number, sizeof(t1.number));
    t1.type = InputTransistorType("Input type: ");
    t1.caseStyle = InputTransistorCaseStyle("Input case style: ");
    t1.pmax = InputPositiveValue("Input pMax: ");
    t1.icmax = InputPositiveValue("Input icMax: ");
    return t1;
}
