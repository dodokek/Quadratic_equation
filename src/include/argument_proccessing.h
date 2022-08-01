//{---------------------------
//! @file argument_proccessing.h
//{---------------------------


/// Структура для хранения значений аргументов командной строки
struct OptionDef
{
    const char* name;

    int (*func)(int argc, const char* argv[], int argc_pos);
};


//Global/Constant

extern const char default_file_name[] = "tests.txt";

//Global/Constants


/// \brief   Функция обработки аргументов командной строки
/// \arg     argc - Количество аргументов командной строки при запуске .exe файла
/// \arg     argv - Массив значений аргументов
/// \arg     options - Массив структур с названием аргумента и соответствующей ему функцией
/// \arg     options_range - Размер массива аргументов
/// \note    Происходит сравнение всех введенных аргументов со всеми заранее известными.
/// \warning Функция не может определять какой именно аргумент введен неверно.

void process_arguments (int                    argc,      const char* argv[],
                       const struct OptionDef  Options[], int         options_range);

int print_help(int argc, const char* argv[], int pos);

//-----------------------------------------------------------------------------

