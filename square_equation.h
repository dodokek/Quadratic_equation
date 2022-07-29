//{---------------------------
//! @file square_equation.h
//{---------------------------


/// Нумерация количества корей уравнения.
enum NUM_OF_ROOTS
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
};

/// Структура для хранения значений аргументов командной строки
struct OptionDef
{
    const char* option_name;

    void (*func)();
};

/// \brief Кластер функций для решений квадратного уравнения
namespace quadratic_equation
{
    /// \brief Функция отвечает за вывод ответа, количество корней
    /// \note  Рассмотрены случаи с бесконечным количеством ответов и пустым множеством ответов
    /// \param roots_amount Количество корней уравнения, приходящее из функции calculate_roots_return_amount
    /// \param roots_array[] Массив корней уравнения

    void print_answer(int roots_amount, double roots_array[]);

    /// \brief  Функция подсчета количества корней и их значения
    /// \param  roots_array Массив заполняется заполняется значениями корней в ходе работы функции
    /// \param  data_arr Массив значений коэфицентов уравнения
    /// \note   Изначально массив корней заполнен значениями NAN
    /// \return

    int calculate_roots_return_amount(double roots_array[], double data_arr[]);

    /// \brief Главная функция для решения квадратного уравнения
    /// \note  При её вызове происходит ввод данных и вызов вторичных функций из данного namespace'а

    void solve_quadratic_equation(double data_arr[]);
}

/// \brief Функция отвечает за вызов Unit тестов квадратного уравнения

void start_unit_test();

/// \brief Функция, отвечающая за отдельный тест
/// \param test_data[] Массив хранит в себе тестовые данные(коэфиценты и ответы)
/// \param num_of_test
/// \warning Можно впасть в тильт от написания тестов

void unit_test_quadratic_equation(double test_data[], int num_of_test);

/// \brief   Решение линейного уравнения
/// \param   roots_array Заполняемый список корней уравнения
/// \param   koef_a, koef_b - Коэфиценты линейного уравнения вида ax + b = 0
/// \warning Может быть бесконечное количество решений
/// \return  Количество корней

int solve_linear_equation_return_amount(double roots_array[], double koef_a, double koef_b);

/// \brief Проверка равнества двух чисел типа double
/// \note Числа сравниваются с точностью до глобальной константы Accuracy

bool is_equal(double num_1, double num_2);

/// \brief Функция для считывания вводимых данных
/// \param data_arr - Заполняемый массив данных ввода
/// \param option - Переменная для выбора типа операции.

bool get_input(double data_arr[], int option);

/// \brief Проверка равнества нулю числа типа double.
/// \note Число сравнивается с нулем с точностью до глобальной константы Accuracy.

bool is_zero(double number);

/// \brief Заполнение конкретного массива данными NAN.

void fill_array_with_NAN(double arr[], int length);

/// \brief Вспомогательная функция для очищения буфера ввода.
/// \param length - количество элементов, начиная с 0-го для заполнения.

void clear_buffer();

/// \brief Проверка введенной "q" Для выхода из меню ввода.

bool check_on_exit();

/// \brief   Функция обработки аргументов командной строки
/// \arg     argc - Количество аргументов командной строки при запуске .exe файла
/// \arg     argv - Массив значений аргументов
/// \arg     options - Массив структур с названием аргумента и соответствующей ему функцией
/// \arg     options_range - Размер массива аргументов
/// \note    Происходит сравнение всех введенных аргументов со всеми заранее известными.
/// \warning Функция не может определять какой именно аргумент введен неверно.

void process_arguments(int                    argc,      const char* argv[],
                      const struct OptionDef  Options[], int         options_range);

/// \brief Вывод сообщения с помощью. Переход на документацию

void print_help();


//Constants
const int Debug = false;

const double Accuracy = 0.000001;

const int SolveSqrOpt = 1;

const double POISON_NUM = 12345.6;

const int MAX_DATA_SIZE = 100;

const double INF = 1000000000;

const OptionDef Options[] = {
    {"--test", start_unit_test},
    {"-t",     start_unit_test},
    {"/t",     start_unit_test},

    {"--help", print_help},
    {"-h",     print_help},
    {"/h",     print_help}
};

const char default_file_name[] = "tests.txt";
//---------
