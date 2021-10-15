#include <stdio.h>

/* 
 * Name : <Insert name>
 * Program to experiment with hexadecimal
 * and pointers
 */

int main()
{
    int a = 0;
    int b = 5;
    int c = 0x2251;
    int *pA = &a;
    int *pB = &b;
    int *p;

    printf("%d: %x\n", a, a);
    printf("%d: %x\n", b, b);
    printf("%d: %x\n", c, c);
    printf("a=%d, pA=%lx, *pA=%d\n", a, (long)pA, *pA);
    a = 47;
    printf("a=%d, pA=%lx, *pA=%d\n", a, (long)pA, *pA);
    *pA = 99;
    printf("a=%d, pA=%lx, *pA=%d\n", a, (long)pA, *pA);
    printf("Next experiment:\n");
    p = pA;
    *p = 22;
    p = pB;
    *p = 18;
    p = &b;
    *p = 108;
    p = pA;
    *p = 2;
    printf("a=%d, pA=%lx, *pA=%d\n", a, (long)pA, *pA);
    printf("b=%d, pB=%lx, *pB=%d\n", b, (long)pB, *pB);
    printf("p=%lx, *p=%d\n", (long)p, *p);
}
