#include <stdio.h>
#include <stdlib.h>

int main()
{
    // define variables
    double annualIncome;
    int filingStatus;
    int dependents;
    int standardDeduction;
    int children;
    int totalDeductions;
    double taxableIncome;
    double tax;

    // input annual income
    printf("Enter your annual income: ");
    scanf("%lf", &annualIncome);

    // cases when annual income < 9350
    if (annualIncome < 9350)
    {
        printf("0.00\n");
        exit(0);
    }

    // input filing status
    printf("What is your filing status?\n");
    printf("1) single\n");
    printf("2) married filing jointly\n");
    printf("3) married filing separately\n");
    printf("Please enter a number: ");
    scanf("%d", &filingStatus);

    // set the number of dependents and the standard deduction
    if (filingStatus == 1 && filingStatus == 3)
    {
        dependents = 1;
        standardDeduction = 5700;
    }
    else if (filingStatus == 2)
    {
        standardDeduction = 11400;

        printf("How many children do you have? ");
        scanf("%d", &children);

        dependents = 2 + children;
    }

    // compute total deductions and taxable income
    totalDeductions = dependents * 3650 + standardDeduction;
    taxableIncome = annualIncome - totalDeductions;

    // compute tax
    if (taxableIncome <= 16750)
    {
        tax = 0.1 * taxableIncome;
    }
    else if (taxableIncome <= 68000)
    {
        tax = 1675 + 0.15 * (taxableIncome - 16750);
    }
    else if (taxableIncome <= 137300)
    {
        tax = 9362.50 + 0.25 * (taxableIncome - 68000);
    }
    else
    {
        tax = 26687.50 + 0.28 * (taxableIncome - 137300);
    }

    // print tax
    printf("%.2f\n", tax);
}
