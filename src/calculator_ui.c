#include "calculator_ui.h"
#include "calculator_expr.h"

void on_number_clicked(GtkButton *button, gpointer user_data)
{
    GtkEditable *display = GTK_EDITABLE(user_data);

    const char *text = gtk_button_get_label(button);
    int position = gtk_editable_get_position(display);

    gtk_editable_insert_text(
        display,
        text,
        -1,
        &position);

    gtk_editable_set_position(display, position);
}

void calculator_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 380, 650);

    GtkWidget *grid = gtk_grid_new();

    GtkWidget *button_1 = gtk_button_new_with_label("1");
    GtkWidget *button_2 = gtk_button_new_with_label("2");
    GtkWidget *button_3 = gtk_button_new_with_label("3");
    GtkWidget *button_4 = gtk_button_new_with_label("4");
    GtkWidget *button_5 = gtk_button_new_with_label("5");
    GtkWidget *button_6 = gtk_button_new_with_label("6");
    GtkWidget *button_7 = gtk_button_new_with_label("7");
    GtkWidget *button_8 = gtk_button_new_with_label("8");
    GtkWidget *button_9 = gtk_button_new_with_label("9");
    GtkWidget *button_0 = gtk_button_new_with_label("0");

    GtkWidget *button_clear = gtk_button_new_with_label("C");
    GtkWidget *button_plus = gtk_button_new_with_label("+");
    GtkWidget *button_minus = gtk_button_new_with_label("-");

    GtkWidget *button_multiply = gtk_button_new_with_label("*");
    GtkWidget *button_divide = gtk_button_new_with_label("/");
    GtkWidget *button_dot = gtk_button_new_with_label(".");
    GtkWidget *button_equals = gtk_button_new_with_label("=");
    GtkWidget *widgets[] = {
        button_0,
        button_1,
        button_2,
        button_3,
        button_4,
        button_5,
        button_6,
        button_7,
        button_8,
        button_9,
        button_clear,
        button_plus,
        button_minus,
        button_multiply,
        button_divide,
        button_dot,
        button_equals};
    GtkWidget *buttons[] = {
        button_0,
        button_1,
        button_2,
        button_3,
        button_4,
        button_5,
        button_6,
        button_7,
        button_8,
        button_9,
        button_plus,
        button_minus,
        button_multiply,
        button_divide,
        button_dot,
    };
    size_t number_button_count =
        sizeof(buttons) / sizeof(buttons[0]);

    size_t widgets_count = sizeof(widgets) / sizeof(widgets[0]);

    gtk_grid_attach(GTK_GRID(grid), button_clear, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_divide, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_multiply, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_minus, 3, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), button_7, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_8, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_9, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_plus, 3, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), button_4, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_5, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_6, 2, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), button_1, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_2, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_3, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_equals, 3, 2, 1, 3);

    gtk_grid_attach(GTK_GRID(grid), button_0, 0, 4, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button_dot, 2, 4, 1, 1);

    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

    for (size_t i = 0; i < widgets_count; i++)
    {
        gtk_widget_set_hexpand(widgets[i], TRUE);
        gtk_widget_set_vexpand(widgets[i], TRUE);
    }

    GtkWidget *display = gtk_entry_new();

    for (size_t i = 0; i < number_button_count; i++)
    {
        g_signal_connect(
            buttons[i],
            "clicked",
            G_CALLBACK(on_number_clicked),
            display);
    }

    g_signal_connect(
        button_equals,
        "clicked",
        G_CALLBACK(on_equals_clicked),
        display);

    g_signal_connect(
        button_clear,
        "clicked",
        G_CALLBACK(on_clear_clicked),
        display);

    GtkWidget *layout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    gtk_widget_set_vexpand(display, TRUE);
    gtk_widget_set_hexpand(display, TRUE);

    gtk_widget_set_vexpand(grid, TRUE);
    gtk_widget_set_hexpand(grid, TRUE);

    gtk_box_append(GTK_BOX(layout), display);
    gtk_box_append(GTK_BOX(layout), grid);

    gtk_editable_set_editable(GTK_EDITABLE(display), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(display), 1.0);

    gtk_window_set_child(GTK_WINDOW(window), layout);

    gtk_window_present(GTK_WINDOW(window));
}

bool evaluate_expression(char *expr, double *result)
{
    if (expr == NULL)
        return false;

    char *first = malloc(6);
    char *end = malloc(6);
    char operator;

    size_t i = 0;
    while (true)
    {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%' || expr[i] == '\0')
        {
            operator = expr[i];
            break;
        }

        first[i] = expr[i];
        i++;
    }
    first[i] = '\0';

    i += 1;
    int j = 0;
    while (expr[i] != '\0')
    {
        end[j] = expr[i];
        i++;
        j++;
    }
    end[j] = '\0';

    char *endf;
    char *ende;

    int numbers[] = {strtod(first, &endf), strtod(end, &ende)};

    if (operator == '+')
    {
        int int_result;
        add(numbers, 2, &int_result);
        *result = int_result;

        printf("Addition = %d\n", int_result);
    }
    else if (operator == '-')
    {
        int int_result;
        subtract(numbers, 2, &int_result);
        *result = int_result;

        printf("Subtraction = %d\n", int_result);
    }
    else if (operator == '*')
    {
        int int_result;
        multiply(numbers, 2, &int_result);
        *result = int_result;

        printf("Multiply = %d\n", int_result);
    }
    else if (operator == '/')
    {
        divide(numbers, 2, result);

        printf("Division = %.2lf\n", *result);
    }
    else if (operator == '%')
    {
        int int_result;
        modulus(numbers, 2, &int_result);
        *result = int_result;

        printf("Modulus = %d\n", int_result);
    }

    free(first);
    free(end);

    return true;
}

void on_equals_clicked(GtkButton *button, gpointer user_data)
{
    (void)button;

    GtkEditable *display = GTK_EDITABLE(user_data);

    const char *expression =
        gtk_editable_get_text(display);

    double result;

    evaluate_expression(
        (char *)expression,
        &result);

    char buffer[64];

    snprintf(
        buffer,
        sizeof(buffer),
        "%g",
        result);

    gtk_editable_set_text(
        display,
        buffer);
}

void on_clear_clicked(GtkButton *button, gpointer user_data)
{
    (void)button;

    GtkEditable *display = GTK_EDITABLE(user_data);

    gtk_editable_set_text(display, "");
}