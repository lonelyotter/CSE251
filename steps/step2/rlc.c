#include <stdio.h>
#include <math.h>

int main()
{
    double L, C, omega_c, f;
    printf("Input Capacitance (microfarads): ");
    scanf("%lf", &C);
    printf("Input Inductance (millihenrys): ");
    scanf("%lf", &L);
    omega_c = 1 / sqrt(L * C / 1e9);
    f = omega_c / (2 * M_PI);
    printf("Resonant Frequency is %.3f\n", f);
}
