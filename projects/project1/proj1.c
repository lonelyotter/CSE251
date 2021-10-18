#include <stdio.h>
#include <math.h>

/*
* CSE 251 Project 1
* By: ¡your name here¿ 
*
* Complete the following table: 
*
* a      b      n          estimate
* −1     1      1883       1.178979838
* 0      10     2028       0.489888070
* −1000  1000   18861      0.999796418
* 10     15     1515       0.016860599
* 0.1    0.2    138        0.096211811
*/

double sinc(double x);

int main()
{
    double a, b;
    int n = 10;
    const double error = 1e-10;
    double preResult;
    double result;
    double delta;
    double decrease;

    printf("Enter a value for a: ");
    scanf("%lf\n", &a);
    printf("Enter a value for b: ");
    scanf("%lf\n", &b);

    printf("Integral evaluation\n");
    while (n <= 100000)
    {
        preResult = result;
        result = 0;

        delta = (b - a) / (double)n;
        for (int i = 1; i <= n; i++)
        {
            result += sinc(a + ((double)i - 0.5) * delta) * delta;
        }
        decrease = fabs(result - preResult);

        if (n == 10)
        {
            printf("%d: %.9lf\n", n, result);
        }
        else
        {
            printf("%d: %.9lf %.6e\n", n, result, decrease);
        }

        if (decrease < error)
        {
            break;
        }
        n++;
    }
    printf("The integral result is %.9lf\n", result);
}

double sinc(double x)
{
    if (x == 0)
    {
        return 1;
    }

    return (1e7 * sin(M_PI * x)) / (1e7 * M_PI * x);
}
