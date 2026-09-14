#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool evaluate_expression(const char *expr, double *result);

bool parse_expression(const char **expr, double *result);

bool parse_term(const char **expr, double *result);