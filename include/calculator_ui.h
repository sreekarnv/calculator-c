#pragma once

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>

void on_number_clicked(GtkButton *button, gpointer user_data);

void calculator_activate(GtkApplication *app, gpointer user_data);

void on_equals_clicked(GtkButton *button, gpointer user_data);

void on_clear_clicked(GtkButton *button, gpointer user_data);

bool validate_expression(char *expr, double *result);
