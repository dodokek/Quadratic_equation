//{---------------------------
//! @file square_equation.h
//{---------------------------

#ifndef SQUARE_EQ_H
#define SQUARE_EQ_H

//-----------------------------------------------------------------------------
//! \mainpage Welcome to the documentation, what lead you here?
//! \section  Guess you were so interested in my project, that you wanted to read more about it! I am veeeeery happy...
//-----------------------------------------------------------------------------

#include <TXLib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "argument_proccessing.h"
#include "unit_test.h"
#include "input.h"
#include "log.h"
#include "graphics.h"

//-----------------------------------------------------------------------------

const double Accuracy = 0.000001;

const int SolveSqrOpt = 1;

const double POISON_NUM = 12345.6;

const int MAX_DATA_SIZE = 100;

const double INF = 1000000000;

extern bool Debug;

//-----------------------------------------------------------------------------

/// Нумерация количества корей уравнения.
enum NUM_OF_ROOTS
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
};

/// \brief Кластер функций для решений квадратного уравнения
namespace quadratic_equation
{
    /// \brief Функция отвечает за вывод ответа, количество корней
    /// \note  Рассмотрены случаи с бесконечным количеством ответов и пустым множеством ответов
    /// \param roots_amount Количество корней уравнения, приходящее из функции calculate_roots
    /// \param roots_array[] Массив корней уравнения

    void print_answer (int roots_amount, double roots_array[]);

    /// \brief  Функция подсчета количества корней и их значения
    /// \param  roots_array Массив заполняется заполняется значениями корней в ходе работы функции
    /// \param  data_arr Массив значений коэфицентов уравнения
    /// \note   Изначально массив корней заполнен значениями NAN
    /// \return

    int calculate_roots (double roots_array[], double data_arr[]);

    /// \brief Главная функция для решения квадратного уравнения
    /// \note  При её вызове происходит ввод данных и вызов вторичных функций из данного namespace'а

    void solve_quadratic_equation (double data_arr[]);
}

/// \brief Функция для считывания вводимых данных
/// \param data_arr - Заполняемый массив данных ввода
/// \param option - Переменная для выбора типа операции.

bool get_input (double data_arr[], int option);

/// \brief   Решение линейного уравнения
/// \param   roots_array Заполняемый список корней уравнения
/// \param   koef_a, koef_b - Коэфиценты линейного уравнения вида ax + b = 0
/// \warning Может быть бесконечное количество решений
/// \return  Количество корней

int solve_linear_equation (double roots_array[], double koef_a, double koef_b, double koef_c);

/// \brief Проверка равнества двух чисел типа double
/// \note Числа сравниваются с точностью до глобальной константы Accuracy

bool is_equal (double num_1, double num_2);

/// \brief Проверка равнества числа нулю

bool is_zero (double number);

/// \brief Заполнение конкретного массива данными NAN.
/// \param arr [in] Входной массив
/// \param length [in] Длина массива
/// \param filler [in] Чем заполняется массив

void fill_array (double arr[], int length, double filler);

/// \brief Вспомогательная функция для очищения буфера ввода.

void clear_buffer();

/// \brief Проверка введенной "q" Для выхода из меню ввода.

bool check_on_exit();

/// \brief Вывод сообщения с помощью. Переход на документацию

void print_help();

//-----------------------------------------------------------------------------

#endif
