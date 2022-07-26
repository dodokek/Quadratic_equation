//{---------------------------
//! @file square_equation.cpp
//{---------------------------


#include <txlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "square_equation.h"


bool get_input(double data_arr[], int option)
{
    assert(option == 1 && data_arr != NULL);

    if (option == SolveSqrOpt)
    {
        bool is_input_correct = false;
        bool not_exit         = true;

        printf("Enter q to exit\n");

        while (not_exit)
        {
            printf("Enter coefficients for equation similar to ax^2 + bx + c = 0\n");

            int scanf_amount = scanf("%lg %lg %lg", data_arr, data_arr+1, data_arr+2);

            is_input_correct = (scanf_amount == 3);

            if (Debug)
            {
                $sy;
                printf("line %d: %lg %lg %lg - coefficient\n",
                                    __LINE__, data_arr[0], data_arr[1], data_arr[2]);

                printf("line %d: %d - Value of scanf\n",
                                    __LINE__, scanf_amount);

                printf("line %d: %d - is_input_correct\n",
                                    __LINE__, is_input_correct);
            }

            not_exit = check_on_exit();

            if (!is_input_correct && not_exit)
            {
                printf("Incorrect data \n");

                clear_buffer();

                continue;
            }

            assert(scanf_amount == 3);

            break;
        }

        if (Debug) printf("Line - %d, data_arr0 = %lg, INF = %lg\n", __LINE__, data_arr[0], INF);

        return true;
    }

    else
    {
        printf("So far program does not support any other operations :( ");
        return false;
    }


}


int solve_linear_equation_return_amount(double roots_array[], double koef_a, double koef_b)
{
    assert(roots_array != NULL && koef_a < INF && koef_b < INF);

    //ax + b = 0
    int x1_indx = 0;

    if (is_zero(koef_a) && is_zero(koef_b))
    {
        return INF;
    }

    else if (!is_zero(koef_a) && is_zero(koef_b))
    {
        return INF;
    }

    else if (is_zero(koef_a) && !is_zero(koef_b))
    {
        return NO_ROOTS;
    }

    roots_array[x1_indx] = -koef_b / koef_a;

    return ONE_ROOT;
}

void clear_buffer()
{
    while (getchar() != '\n') ;
}


bool check_on_exit()
{
    return (getchar() == 'q') ? false : true;
}


bool is_zero(double number)
{
    assert(number < INF);

    return (fabs(number) < Accuracy) ? true : false;
}


void fill_array_with_NAN(double arr[], int length)
{
    assert(length <= MAX_DATA_SIZE && arr != NULL);

    for (int i = 0; i< length; i++)
    {
        arr[i] = NAN;
    }
}


bool is_equal(double num_1, double num_2)
{
    assert(num_1 < INF && num_2 < INF);
    return ( fabs(num_1 - num_2) < Accuracy ) ? true : false;
}


int quadratic_equation::calculate_roots_return_amount(double roots_array[], double data_arr[])
{
    assert(roots_array != NULL && data_arr != NULL);

    double koef_a = data_arr[0];
    double koef_b = data_arr[1];
    double koef_c = data_arr[2];

    int x1_indx = 0;
    int x2_indx = 1;

    if (is_zero(koef_a))
    {
        return solve_linear_equation_return_amount(roots_array, koef_b, koef_c);
    }

    double diskr = (koef_b * koef_b) - (4 * koef_a * koef_c);

    if (diskr > 0)
    {
        double diskr_sqrt = sqrt(diskr);

        roots_array[x1_indx] = ( -koef_b + diskr_sqrt) / (2 * koef_a);

        roots_array[x2_indx] = ( -koef_b - diskr_sqrt) / (2 * koef_a);

        return TWO_ROOTS;
    }

    if (is_zero(diskr))
    {
        roots_array[x1_indx] = (-koef_b) / (2 * koef_a);

        roots_array[x2_indx] = (-koef_b) / (2 * koef_a);

        return ONE_ROOT;
    }

    return NO_ROOTS;

}


void quadratic_equation::print_answer(int roots_amount, double roots_array[])
{
    printf("Equation has solutions in quantity: %d \n", roots_amount);

    assert(roots_amount >= 0 && roots_amount <= 2 && roots_array != NULL);

    if (roots_amount == NO_ROOTS)
    {
        printf("No solutions.\n");
    }

    else if (roots_amount == ONE_ROOT)
    {
        printf("One root %lg \n", roots_array[0]);
    }

    else if (roots_amount == INF)
    {
        printf("Infinite amount of solutions");
    }

    else
    {
        printf("Root %lg, Root %lg \n", roots_array[0], roots_array[1]);
    }
}


void quadratic_equation::solve_quadratic_equation(double data_array[])
{
    assert(data_array != NULL);

    double roots_array[2] = {POISON_NUM, POISON_NUM};

    int roots_count = quadratic_equation::calculate_roots_return_amount(roots_array, data_array);

    quadratic_equation::print_answer(roots_count, roots_array);
}


void unit_test_quadratic_equation(double test_data[], int    num_of_test)
{
    assert(test_data != NULL && num_of_test > 0);

    int a_indx = 0;
    int b_indx = 0;
    int c_indx = 0;

    int x1_indx = 3;
    int x2_indx = 4;

    double roots_array[2] = { POISON_NUM, POISON_NUM };

    quadratic_equation::calculate_roots_return_amount(roots_array, test_data);

    assert(roots_array[0] == roots_array[0] && roots_array[1] == roots_array[1]);

    if (roots_array[0] < roots_array[1])
    {
        std::swap(roots_array[0], roots_array[1]);
    }

    if (   is_equal(test_data[x1_indx], roots_array[0])
        && is_equal(test_data[x2_indx], roots_array[1]))
    {
        $sg; printf("Unit test %d passed\n", num_of_test);
    }
    else
    {
        $sr; printf("Unit test %d not passed, with data %lg %lg %lg,"
                    "excepted %lg %lg, received %lg %lg\n",
                    num_of_test,
                    test_data[a_indx],   test_data[b_indx ], test_data[c_indx],
                    test_data[x1_indx],  test_data[x2_indx],
                    roots_array[a_indx], roots_array[c_indx]);
    }
    txSleep(500);

}


FILE* get_tests_file()
{

    char file_name[] = {};

    char is_default[] = "def";

    printf("Enter file name. Enter def to keep tests.txt\n");

    scanf("%s", file_name);

    assert(file_name[0] != '\0');

    if (strcmp(file_name, is_default) == 0)
    {
        return fopen(default_file_name, "r");
    }
    else
    {
        return fopen(file_name, "r");
    }

    printf("File name %s\n", file_name);
}


void start_unit_test()
{
    FILE *tests_file = get_tests_file();

    if (tests_file == NULL)
    {
        printf("Failed to open the file \n");
        getchar();

        return;
    }

    int num_of_test = 1;

    while (true)
    {
        int check_EOF = 1;
        double test_data[5] = {};

        check_EOF = fscanf(tests_file, "%lg %lg %lg %lg %lg",
                           test_data,
                           test_data + 1,  test_data + 2,
                           test_data + 3,  test_data + 4);

        if (check_EOF == EOF) break;

        unit_test_quadratic_equation(test_data, num_of_test);

        assert(num_of_test > 0);

        num_of_test++;

    }

    fclose(tests_file);
}


void print_help()
{
    printf("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "chrome C:\\Users\\User\\Desktop\\Lessons\\Square_equasion\\html\\index.html";

    system(help_src);
}


void process_arguments(int                    argc,      const char* argv[],
                       const struct OptionDef Options[], int         options_range)
{
    assert(argc > 0 && argv != NULL && Options != NULL && options_range < INF);

    int count_processed_options = 0;

    for (int i = 0; i < argc; i++)
    {
        for(int j = 0; j < options_range; j++)
        {
            if (strcmp(argv[i], Options[j].option_name) == 0)
            {
                Options[j].func();
                count_processed_options++;
            }
        }
    }

    if (count_processed_options != argc - 1)
    {
        printf("Some arguments are incorrect.\n");
    }
}


int main (int argc, const char* argv[])
{
    assert(argc != 0 && argv != NULL);

    process_arguments(argc, argv, Options, sizeof(Options) / sizeof(Options[0]));

    double data_array[MAX_DATA_SIZE] = {};

    fill_array_with_NAN(data_array, MAX_DATA_SIZE);

    bool data_is_correct = get_input(data_array, SolveSqrOpt);

    if (data_is_correct)
    {
        quadratic_equation::solve_quadratic_equation(data_array);
    }
}
