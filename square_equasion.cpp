
#include <txlib.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>

namespace QuadraticEquasion
{
    double compute_diskr(double data_arr[]);

    void print_answer(double diskr, double ans_array[]);

    int amount_of_answers(double diskr);

    double calculate_answer(double ans_array[], double data_arr[], double diskr);

    bool handle_exception(double data_arr[]);
}

bool get_data(double data_arr[], int option);

bool is_zero(double number);

void fill_array_with_NAN(double arr[], int length);

bool check_scanf_amount(int amount);

bool is_NAN(double number);

void clear_buffer();

bool check_on_exit();

//Constants
const int Debug = true;

const double Accuracy = 0.000001;

const int Solve_sqr_opt = 1;

const int amount_of_tries = 10;
//---------



bool get_data(double data_arr[], int option)
{
    if (option == Solve_sqr_opt)
    {
        bool data_is_ok = false;
        int not_exit = 1;

        while (not_exit)
        {
            printf("Введите коэфиценты уравнения вида ax^2 + bx + c = 0\n");

            int scanf_amount = scanf("%lg %lg %lg", data_arr, data_arr+1, data_arr+2);

            if (Debug){ $sy; printf("line %d: %lg %lg %lg - Коэфиценты\n",
                                    __LINE__, data_arr[0], data_arr[1], data_arr[2]); }

            data_is_ok = check_scanf_amount(scanf_amount);

            if (Debug){ $sy; printf("line %d: %d - Значение scanf\n", __LINE__, scanf_amount);}

            if (Debug){ $sy; printf("line %d: %d - data_is_ok\n", __LINE__, data_is_ok);}

            not_exit = check_on_exit();

            if (!data_is_ok)
            {
                if(!not_exit){
                    printf("Введенные данные некоректны \n");
                    clear_buffer();
                    continue;
                }
            }
        }

        if (data_is_ok)
        {
            data_is_ok = QuadraticEquasion::handle_exception(data_arr);
            if(data_is_ok)
            {
                printf("Спасибо за ввод значений %lg %lg %lg \n",
                        data_arr[0], data_arr[1], data_arr[2]);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
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
    if (getchar() == 'q')
    {
        return false;
    }
    return true;
}

double QuadraticEquasion::compute_diskr(double data_arr[])
{
    double diskr_pow_2 = (data_arr[1] * data_arr[1]) - (4 * data_arr[0] * data_arr[2]);

    if (diskr_pow_2 < 0)
    {
        return -1;
    }

    double diskr = sqrt(diskr_pow_2);

    if (Debug) { $sy; printf("line %d: %lg - Дикриминант\n", __LINE__, diskr); }

    return diskr;
}


double QuadraticEquasion::calculate_answer(double ans_array[], double data_arr[], double diskr)
{

    ans_array[0] = (-data_arr[1] + diskr) / (2*data_arr[0]);

    ans_array[1] = (-data_arr[1] - diskr) / (2*data_arr[0]);

    if (Debug) { $sy; printf("line %d: %lg - Первый ответ\n", __LINE__, ans_array[0]); }
    if (Debug) { $sy; printf("line %d: %lg - Второй ответ\n", __LINE__, ans_array[1]); }

    return 0;
}


int QuadraticEquasion::amount_of_answers(double diskr)
{
    if (Debug) { $sy;printf("line %d: %lg \n", __LINE__, diskr); }

    if (diskr < 0)
    {
        return 0;
    }
    if (is_zero(diskr))
    {
        return 1;
    }
    else
    {
        return 2;
    }

}


void QuadraticEquasion::print_answer(double diskr, double ans_array[])
{
    int answers_amount = QuadraticEquasion::amount_of_answers(diskr);

    printf("Уравнение имеет кол-во решений равное: %d \n", answers_amount);

    if (answers_amount == 0)
    {
        printf("%s", "Решений нет.\n");
    }

    else if (answers_amount == 1)
    {
        printf("Кратный корень %lg \n", ans_array[0]);
    }

    else
    {
        printf("Корень %lg, Корень %lg \n", ans_array[0], ans_array[1]);
    }
}


bool QuadraticEquasion::handle_exception(double data_arr[])
{
    if (is_zero(data_arr[0]) && is_zero(data_arr[0]) && is_zero(data_arr[0]))
    {
        printf("Бесконечное количество решений");
        return false;
    }
    return true;
}


bool is_zero(double number)
{
    if (abs(number) < Accuracy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_NAN(double number)
{
    if (number != number)
    {
        return true;
    }
    return false;
}


void fill_array_with_NAN(double arr[], int length)
{
    for (int i = 0; i< length; i++)
    {
        arr[i] = NAN;
    }
}


bool check_scanf_amount(int amount)
{
    if (amount == 3)
    {
        return true;
    }
    return false;
}


int main()
{
    double diskr = 0;    //diskrimiNANt
    double ans_array[2] = {}; //answers
    double data_array[100] = {};

    fill_array_with_NAN(data_array, 100);

    bool data_is_correct = get_data(data_array, Solve_sqr_opt);

    if (data_is_correct)
    {
        diskr = QuadraticEquasion::compute_diskr(data_array);

        QuadraticEquasion::calculate_answer(ans_array, data_array, diskr);

        QuadraticEquasion::print_answer(diskr, ans_array);
    }
}
