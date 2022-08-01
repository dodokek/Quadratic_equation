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

const char default_file_name[] = "tests.txt";

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

int print_help(int argc, const char* argv[], int pos)
{
    __TRACK__
    printf ("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "html\\index.html";

    system (help_src);

    return 0;
}


void process_arguments (int                    argc,      const char* argv[],
                        const struct OptionDef Options[], int         options_range)
{
    __TRACK__
    assert (argc > 0 && argv != NULL && Options != NULL && options_range < INF);

    int count_processed_options = 0;

    for (int argc_pos = 0; argc_pos < argc; argc_pos++)
    {
        for(int i = 0; i < options_range; i++)
        {
            if (strcmp(argv[argc_pos], Options[i].name) == 0)
            {
                int skip_argv = Options[i].func(argc, argv, argc_pos);

                argc_pos += skip_argv;
            }
        }
    }

    //if (count_processed_options != argc - 1)
    //{
    //    printf ("Some arguments are incorrect.\n");
    //}
}
