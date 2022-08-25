
//{---------------------------
//! @file unit_test.h
//{---------------------------

#ifndef UNIT_TEST
#define UNIT_TEST

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <TXlib.h>

#include "log.h"

/// \brief Функция отвечает за вызов Unit тестов квадратного уравнения
/// \param [in] argc Количество аргументов командной строки
/// \param [in] argv Массив аргументов командной строки
/// \param [in] pos  Позиция аргумента командной строки

int unit_test                     (int argc, const char* argv[], int pos);

/// \brief Функция, отвечающая за отдельный тест
/// \param [in] test_data[] Массив хранит в себе тестовые данные(коэфиценты и ответы)
/// \param [in] num_of_test
/// \warning Можно впасть в тильт от написания тестов

void unit_test_quadratic_equation (double test_data[], int num_of_test);

/// \brief Функция открывает открывает файл с помощью get_tests_file и в цикле прогоняет все тесты
/// \param file_name Имя файла с тестами
/// \param argument_indx Номер аргумента командной строки, на котором остановилось считывание
/// \param tests_amount Количество тестов для прогона, отсчет идет с первого
/// \note  На вход может приниматься пустое имя файла, так как в функции get_tests_file написани обработчик этого случая

int start_tests_cycle             (char file_name_tmp[], int argument_indx, int tests_amount);

/// \brief Функция для считывание файлы
/// \param [in] Имя файла
/// \return File stream

FILE* get_tests_file              (char file_name[]);

extern bool is_equal              (double num_1, double num_2);

namespace quadratic_equation
{
    extern int calculate_roots    (double roots_array[], double data_arr[]);
}

#endif
