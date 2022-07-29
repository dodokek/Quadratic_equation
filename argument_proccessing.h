//{---------------------------
//! @file argument_proccessing.h
//{---------------------------


/// \brief   Функция обработки аргументов командной строки
/// \arg     argc - Количество аргументов командной строки при запуске .exe файла
/// \arg     argv - Массив значений аргументов
/// \arg     options - Массив структур с названием аргумента и соответствующей ему функцией
/// \arg     options_range - Размер массива аргументов
/// \note    Происходит сравнение всех введенных аргументов со всеми заранее известными.
/// \warning Функция не может определять какой именно аргумент введен неверно.

void process_arguments (int                    argc,      const char* argv[],
                       const struct OptionDef  Options[], int         options_range);

/// Структура для хранения значений аргументов командной строки
struct OptionDef
{
    const char* option_name;

    void (*func)();
};


void print_help()
{
    printf ("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "html\\index.html";

    system (help_src);
}


void process_arguments (int                    argc,      const char* argv[],
                        const struct OptionDef Options[], int         options_range)
{
    assert (argc > 0 && argv != NULL && Options != NULL && options_range < INF);

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
        printf ("Some arguments are incorrect.\n");
    }
}
