
#include <txlib.h>
#include <stdio.h>
#include <math.h>


enum NUM_OF_ROOTS
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

namespace QuadraticEquasion
{
    double compute_diskr(double data_arr[]);

    void print_answer(int roots_amount, double roots_array[]);

    int calculate_roots_return_amount(double roots_array[], double data_arr[]);

    void solve_quadratic_equasion(double data_arr[]);
}


void UnitTestQuadraticEquasion(double test_data[], double answers[]);
void UnitTest();

void UnitTestQuadraticEquasion(double test_data[], int num_of_test);

bool is_equal(double num_1, double num_2);

bool get_input(double data_arr[], int option);

bool is_zero(double number);

void fill_array_with_NAN(double arr[], int length);

bool check_scanf_amount(int amount);

void clear_buffer();

bool check_on_exit();


//Constants
const int Debug = true;

const double Accuracy = 0.000001;

const int SolveSqrOpt = 1;

const double reserved_num = 12345.6;

const int MAX_DATA_SIZE = 100;

const int INF = 100000000;
//---------


bool get_input(double data_arr[], int option)
{
    if (option == SolveSqrOpt)
    {
        bool is_input_correct = false;
        bool not_exit         = true;

        printf("Введите q для выхода\n");

        while (not_exit)
        {
            printf("Введите коэфиценты уравнения вида ax^2 + bx + c = 0\n");

            int scanf_amount = scanf("%lg %lg %lg", data_arr, data_arr+1, data_arr+2);

            is_input_correct = check_scanf_amount(scanf_amount);

            // One if

            if (Debug)
            {
                $sy; printf("line %d: %lg %lg %lg - Коэфиценты\n",
                                    __LINE__, data_arr[0], data_arr[1], data_arr[2]);

                printf("line %d: %d - Значение scanf\n",
                                    __LINE__, scanf_amount);

                printf("line %d: %d - is_input_correct\n",
                                    __LINE__, is_input_correct);
            }

            not_exit = check_on_exit();

            if (!is_input_correct && not_exit)
            {
                printf("Введенные данные некоректны \n");

                clear_buffer();

                continue;
            }

            break;
        }

    }

    else
    {
        printf("Пока что программа не поддерживает другие операции :( ");
    }

    return false;
}


void clear_buffer()
{
    while(getchar() != '\n') ;
}


bool check_on_exit()
{
    return (getchar() == 'q') ? false : true;
}


bool is_zero(double number)
{
    return (fabs(number) < Accuracy) ? true : false;
}


void fill_array_with_NAN(double arr[], int length)
{
    for (int i = 0; i< length; i++)
    {
        arr[i] = NAN;
    }
}


bool check_scanf_amount(int num_of_args)
{
    return (num_of_args == 3) ? true : false;
}


bool is_equal(double num_1, double num_2)
{
    return ( fabs(num_1 - num_2) < Accuracy ) ? true : false;
}


int QuadraticEquasion::calculate_roots_return_amount(double roots_array[], double data_arr[])
{
    int koef_a = data_arr[0];
    int koef_b = data_arr[1];
    int koef_c = data_arr[2];

    int x1_indx = 0;
    int x2_indx = 1;

    //Special cases

    if (is_zero(koef_a) && !is_zero(koef_b) && !is_zero(koef_c))
    {
        roots_array[x1_indx] = -koef_c / koef_b;
        return 1;
    }

    if (is_zero(koef_a) && is_zero(koef_b) && is_zero(koef_c))
    {
        return INF;
    }

    //Special cases

    double diskr = (koef_b * koef_b) - (4 * koef_a * koef_c);

    if (diskr > 0)
    {
        roots_array[x1_indx] = ( -koef_b + sqrt(diskr)) / (2 * koef_a);

        roots_array[x2_indx] = ( -koef_b - sqrt(diskr)) / (2 * koef_a);

        return 2;
    }

    if (is_zero(diskr))
    {
        roots_array[x1_indx] = (-koef_b) / (2 * koef_a);

        roots_array[x2_indx] = (-koef_b) / (2 * koef_a);

        return 1;
    }

    return 0;

}


void QuadraticEquasion::print_answer(int roots_amount, double roots_array[])
{
    printf("Уравнение имеет кол-во решений равное: %d \n", roots_amount);

    if (roots_amount == 0)
    {
        printf("%s", "Решений нет.\n");
    }

    else if (roots_amount == 1)
    {
        printf("Кратный корень %lg \n", roots_array[0]);
    }

    else if (roots_amount == INF)
    {
        printf("Бесконечное количество решений");
    }

    else
    {
        printf("Корень %lg, Корень %lg \n", roots_array[0], roots_array[1]);
    }
}


void QuadraticEquasion::solve_quadratic_equasion(double data_array[])
{
    double roots_array[2] = {0, 0};

    int roots_count = QuadraticEquasion::calculate_roots_return_amount(roots_array, data_array);

    QuadraticEquasion::print_answer(roots_count, roots_array);
}


// One style

// 5 1 -> 1 5

// test_answers
// square_eq_coff test_data[], square_eq_root answers[], int num_of_test


void UnitTestQuadraticEquasion(double test_data[],
                               int    num_of_test)
{
    int a_indx  = 0;
    int b_indx  = 1;
    int c_indx  = 2;

    int x1_indx = 3;
    int x2_indx = 4;

    double diskr          = 0;
    double roots_array[2] = { reserved_num, reserved_num };

    QuadraticEquasion::calculate_roots_return_amount(roots_array, test_data);

    if (   is_equal(test_data[x1_indx], roots_array[0])
        && is_equal(test_data[x2_indx], roots_array[1]))
    {
        $sg; printf("Unit test %d passed\n", num_of_test + 1);
    }
    else
    {
        $sr; printf("Unit test %d not passed, with data %lg %lg %lg,"
                    "excepted %lg %lg, received %lg %lg\n",
                    num_of_test + 1,
                    test_data[a_indx ], test_data[b_indx ], test_data[c_indx],
                    test_data[x1_indx], test_data[x2_indx],
                    roots_array[a_indx ], roots_array[c_indx ]);
    }

}


void UnitTest()
{
    //                         a  b  c  x1   x2
    double test_data[][5] = { {1, 2, 1, -1,  -1 },
                              {2, 5, 1, -12, -15}
                              };


    int tests_amount = sizeof(test_data) / sizeof(test_data[0]);

    for(int i = 0; i < tests_amount; i++)
    {
        UnitTestQuadraticEquasion(test_data[i], i);
    }

}


int main()
{
    if (Debug)
    {
        UnitTest();
    }

    double data_array[MAX_DATA_SIZE] = {};

    fill_array_with_NAN(data_array, MAX_DATA_SIZE);

    bool data_is_correct = get_input(data_array, SolveSqrOpt);

    if (data_is_correct)
    {
        QuadraticEquasion::solve_quadratic_equasion(data_array);
    }
}
