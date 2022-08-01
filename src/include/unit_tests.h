//{---------------------------
//! @file unit_tests.h
//{---------------------------

/// \brief Функция отвечает за вызов Unit тестов квадратного уравнения

int start_unit_test (int argc, const char* argv[], int pos);

/// \brief Функция, отвечающая за отдельный тест
/// \param test_data[] Массив хранит в себе тестовые данные(коэфиценты и ответы)
/// \param num_of_test
/// \warning Можно впасть в тильт от написания тестов

void unit_test_quadratic_equation (double test_data[], int num_of_test);

FILE* get_tests_file(char file_name[]);


