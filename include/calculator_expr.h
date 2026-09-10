#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool add(int *numbers_ref, size_t numbers_size, int *result);

bool subtract(int *numbers_ref, size_t numbers_size, int *result);

bool multiply(int *numbers_ref, size_t numbers_size, int *result);

bool modulus(int *numbers_ref, size_t numbers_size, int *result);

bool divide(int *numbers_ref, size_t numbers_size, double *result);
