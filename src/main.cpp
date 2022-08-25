
#include "include/main.h"

int main (int argc, const char* argv[])
{
    printf ("#Quadratic equation by DodoKek\n");
    printf ("#Why don't you just solve it yourself?\n");

    assert (argc != 0 && argv != NULL);

    process_arguments (argc, argv, Options, sizeof(Options) / sizeof(Options[0]));

    __TRACKBEGIN__

    if (!Debug)
    {
        double data_array[MAX_DATA_SIZE] = {};

        fill_array (data_array, MAX_DATA_SIZE, NAN);

        bool data_is_correct = get_input (data_array, SolveSqrOpt);

        if (data_is_correct)
        {
            quadratic_equation::solve_quadratic_equation (data_array);
        }
    }

    __TRACKEND__
}
