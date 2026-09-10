#include "calculator_expr.h"

bool add(int *numbers_ref, size_t numbers_size, int *result)
{
    if (numbers_ref == NULL || result == NULL || numbers_size < 1)
        return false;

    *result = 0;

    for (size_t i = 0; i < numbers_size; i++)
    {
        *result += numbers_ref[i];
    }

    return true;
}

bool subtract(int *numbers_ref, size_t numbers_size, int *result)
{
    if (numbers_ref == NULL || result == NULL || numbers_size < 1)
        return false;

    *result = numbers_ref[0];

    for (size_t i = 1; i < numbers_size; i++)
    {
        *result -= numbers_ref[i];
    }

    return true;
}

bool multiply(int *numbers_ref, size_t numbers_size, int *result)
{
    if (numbers_ref == NULL || result == NULL || numbers_size < 1)
        return false;

    *result = 1;

    for (size_t i = 0; i < numbers_size; i++)
    {
        *result *= numbers_ref[i];
    }

    return true;
}

bool modulus(int *numbers_ref, size_t numbers_size, int *result)
{
    if (numbers_ref == NULL || result == NULL || numbers_size < 1)
        return false;

    *result = numbers_ref[0];

    for (size_t i = 1; i < numbers_size; i++)
    {
        *result %= numbers_ref[i];
    }

    return true;
}

bool divide(int *numbers_ref, size_t numbers_size, double *result)
{
    if (numbers_ref == NULL || result == NULL || numbers_size < 1)
        return false;

    *result = (double)(numbers_ref[0]);

    for (size_t i = 1; i < numbers_size; i++)
    {
        *result /= numbers_ref[i];
    }

    return true;
}