#include "calculator_expr.h"

bool evaluate_expression(char *expr, double *result)
{
    if (expr == NULL)
        return false;

    char *current = expr;
    double result_ = strtod(expr, &current);

    while (*current != '\0')
    {
        char operator = *current;
        current++;

        double number = strtod(current, &current);

        if (operator == '+')
        {
            result_ += number;
        }
        else if (operator == '-')
        {
            result_ -= number;
        }
        else if (operator == '*')
        {
            result_ *= number;
        }
        else if (operator == '/')
        {
            result_ /= number;
        }
        else if (operator == '%')
        {
            int left = (int)result_;
            int right = (int)number;

            result_ = left % right;
        }
    }

    *result = result_;

    return true;
}