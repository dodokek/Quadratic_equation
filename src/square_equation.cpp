//{----------------------------------------------------------------------------
//! @file
//! The main file for solving equation
//{----------------------------------------------------------------------------

// “Œ Õ≈ ﬁ«¿≈“ ¿——≈–“, “Œ“ ≈—“‹ ¡¿√» Õ¿ ƒ≈—≈–“

//-----------------------------------------------------------------------------

const bool Debug = true;

//-----------------------------------------------------------------------------

#include "../square_equation.h"
#include "../argument_proccessing.h"
#include "../unit_test.h"
#include "../input.h"

#define _$ $c;printf("[Line %d]\n", __LINE__); $y;

//Constants

const double Accuracy = 0.000001;

const int SolveSqrOpt = 1;

const double POISON_NUM = 12345.6;

const int MAX_DATA_SIZE = 100;

const double INF = 1000000000;

//---------

// Comand line arguments

const OptionDef Options[] =
{
    {"--test", start_unit_test},
    {"-t",     start_unit_test},
    {"/t",     start_unit_test},

    {"--help", print_help},
    {"-h",     print_help},
    {"/h",     print_help}
};

// Command line arguments

int main (int argc, const char* argv[])
{
    assert (argc != 0 && argv != NULL);

    process_arguments (argc, argv, Options, sizeof(Options) / sizeof(Options[0]));

    //__TRACK__

    if (Debug)
    {
        double data_array[MAX_DATA_SIZE] = {};

        fill_array (data_array, MAX_DATA_SIZE, NAN);

        bool data_is_correct = get_input (data_array, SolveSqrOpt);

        if (data_is_correct)
        {
            quadratic_equation::solve_quadratic_equation (data_array);
        }
    }


}


bool get_input (double data_arr[], int option)
{
    //__TRACK__
    assert (option == 1 && data_arr != NULL);

    if (option == SolveSqrOpt)
    {
        bool is_input_correct = false;

        printf ("Enter q to exit\n");

        while (!is_input_correct)
        {
            printf ("Enter coefficents for equation similar to ax^2 + bx + c = 0\n");

            int scanf_amount = scanf("%lg %lg %lg", data_arr, data_arr+1, data_arr+2);

            is_input_correct = (scanf_amount == 3);

            if (Debug)
            {
                $y;
                _$ printf ("%lg %lg %lg - coefficient\n",
                                     data_arr[0], data_arr[1], data_arr[2]);

                _$ printf ("%d - Value of scanf\n",
                                     scanf_amount);

                _$ printf ("%d - is_input_correct\n",
                                     is_input_correct);
            }

            if (check_on_exit('q'))
            {
                return 0;
            }

            if (!is_input_correct)
            {
                printf ("Incorrect data \n");

                clear_buffer('\n');
            }
        }

        if (Debug) printf ("Line - %d, data_arr0 = %lg, INF = %lg\n", __LINE__, data_arr[0], INF);

        return true;
    }

    else
    {
        printf ("So far program does not support any other operations :( ");
        return false;
    }
}


int solve_linear_equation (double roots_array[], double koef_a, double koef_b, double koef_c)
{
    //__TRACK__
    assert (roots_array != NULL && koef_a < INF && koef_b < INF);

    //ax + b = 0
    int x1_indx = 0;
    int x2_indx = 1;

    if (is_zero (koef_a))
    {
        if (is_zero (koef_b) && !is_zero (koef_c))
        {
            return NO_ROOTS;
        }

        else if (is_zero (koef_b) && is_zero (koef_c))
        {
            return INFINITE_ROOTS;
        }

        else if (!is_zero (koef_b) && is_zero (koef_c))
        {
            return INFINITE_ROOTS;
        }

        else
        {
            roots_array[x1_indx] = -koef_c / koef_b;
            return ONE_ROOT;
        }
    }

    else
    {
        if (is_zero(koef_a))
        {
            return INFINITE_ROOTS;
        }
        else{
            roots_array[x1_indx] = 0;
            roots_array[x2_indx] = -koef_b/koef_a;

            return TWO_ROOTS;
        }
    }

}


bool is_zero (double number)
{
    assert (number < INF);

    return (fabs(number) < Accuracy) ? true : false;
}


void fill_array (double arr[], int length, double filler)
{
    //__TRACK__
    assert (length <= MAX_DATA_SIZE && arr != NULL);

    for (int i = 0; i< length; i++)
    {
        arr[i] = filler;
    }
}


bool is_equal (double num_1, double num_2)
{
    assert (num_1 < INF && num_2 < INF);

    return ( fabs(num_1 - num_2) < Accuracy ) ? true : false;
}


int quadratic_equation::calculate_roots (double roots_array[], double data_arr[])
{
    //__TRACK__
    assert (roots_array != NULL && data_arr != NULL);

    double koef_a = data_arr[0];
    double koef_b = data_arr[1];
    double koef_c = data_arr[2];

    int x1_indx = 0;
    int x2_indx = 1;

    //LOG_ARGV("x1: %d, x2: %d", x1_indx, x2_indx);

    if (is_zero (koef_a) || is_zero(koef_c))
    {
        return solve_linear_equation (roots_array, koef_a, koef_b, koef_c);
    }

    double diskr = (koef_b * koef_b) - (4 * koef_a * koef_c);

    if (diskr > 0)
    {
        double diskr_sqrt = sqrt (diskr);

        roots_array[x1_indx] = ( -koef_b + diskr_sqrt ) / (2 * koef_a);

        roots_array[x2_indx] = ( -koef_b - diskr_sqrt ) / (2 * koef_a);

        return TWO_ROOTS;
    }

    if (is_zero(diskr))
    {
        roots_array[x1_indx] =
        roots_array[x2_indx] = (-koef_b) / (2 * koef_a);

        return ONE_ROOT;
    }

    return NO_ROOTS;
}


void quadratic_equation::print_answer (int roots_amount, double roots_array[])
{
    //__TRACK__
    printf ("Equation has solutions in quantity: %d \n", roots_amount);

    assert (roots_amount >= 0 && roots_amount <= 2 && roots_array != NULL);

    switch (roots_amount)
    {
        case NO_ROOTS:
            printf ("No solutions.\n");
            break;

        case ONE_ROOT:
            printf ("One root %lg \n", roots_array[0]);
            break;

        case INFINITE_ROOTS:
            printf ("Infinite amount of solutions");
            break;

        default:
            printf ("Root %lg, Root %lg \n", roots_array[0], roots_array[1]);
    }

}


void quadratic_equation::solve_quadratic_equation (double data_array[])
{
    //__TRACK__
    assert (data_array != NULL);

    double roots_array[2] = {POISON_NUM, POISON_NUM};

    int roots_count = quadratic_equation::calculate_roots (roots_array, data_array);

    quadratic_equation::print_answer (roots_count, roots_array);
}
