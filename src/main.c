#include <stdio.h>
#include "calculator_expr.h"

int main(void)
{
    int a[] = {10, 20};
    int sum_;
    add(a, 2, &sum_);

    int diff_;
    subtract(a, 2, &diff_);

    int mul_;
    multiply(a, 2, &mul_);

    double div_;
    divide(a, 2, &div_);

    int mod_;
    modulus(a, 2, &mod_);

    if (sum_ && diff_ && mul_ && div_)
    {
        printf("Sum = %d\n", sum_);
        printf("Diff = %d\n", diff_);
        printf("Mul = %d\n", mul_);
        printf("Div = %.2lf\n", div_);
        printf("Mod = %d\n", mod_);
    }

    return 0;
}
