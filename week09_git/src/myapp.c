#include <stdio.h>

double calculate(double a, char* op, double b)
{
    printf("Calculating.....\n");
}

int main()
{
    double a, b;
    char op[3];

    printf("~~~ Welcome to my calculator ~~~\n");
    printf("Enter expression (e.g. 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result = %.2f\n", calculate(a, op, b));

    return 0;
}