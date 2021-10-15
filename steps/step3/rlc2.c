#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool valid = true;
    double l, c, omega, f;

    printf("Input Inductance (millihenrys): ");
    scanf("%lf", &l);
    if (l < 0)
    {
        printf("You moron, you entered a negative inductance!\n");
        valid = false;
    }
    else if (l == 0)
    {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }
    else
    {
        printf("Okay, I guess that's reasonable\n");
    }

    printf("Input Capacitance (microfarads): ");
    scanf("%lf", &c);
    if (c < 0)
    {
        printf("You moron, you entered a negative capacitance!\n");
        valid = false;
    }
    else if (c == 0)
    {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }
    else
    {
        printf("Okay, I guess that's reasonable\n");
    }

    if (valid)
    {
        omega = 1.0 / sqrt((l / 1000) * (c / 1000000));
        f = omega / (2 * M_PI);
        printf("Resonant frequency: %.2f\n", f);
        if (f >= 20 && f <= 20000)
        {
            printf("This frequency is one I can hear!\n");
        }
    }
}
