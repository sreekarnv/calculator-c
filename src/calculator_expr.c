#include "calculator_expr.h"

bool parse_term(const char **current, double *result)
{
    char *end;

    double value = strtod(*current, &end);
    *current = end;

    while (
        **current == '*' ||
        **current == '/' ||
        **current == '%')
    {
        char operator = **current;

        (*current)++;

        double number = strtod(*current, &end);
        *current = end;

        if (operator == '*')
        {
            value *= number;
        }
        else if (operator == '/')
        {
            value /= number;
        }
        else if (operator == '%')
        {
            value = (int)value % (int)number;
        }
    }

    *result = value;

    return true;
}

bool parse_expression(const char **current, double *result)
{
    double value;

    parse_term(current, &value);

    while (
        **current == '+' ||
        **current == '-')
    {
        char operator = **current;

        (*current)++;

        double next_term;

        // parse the ENTIRE next term, not merely one number.
        parse_term(current, &next_term);

        if (operator == '+')
        {
            value += next_term;
        }
        else if (operator == '-')
        {
            value -= next_term;
        }
    }

    *result = value;

    return true;
}

bool evaluate_expression(const char *expr, double *result)
{
    if (expr == NULL || result == NULL)
        return false;

    const char *current = expr;

    return parse_expression(&current, result);
}
