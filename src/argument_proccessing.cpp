
#include "include/argument_proccessing.h"

//Global/Constant

double INF = 1000000000;

//Global/Constants

int print_help(int argc, const char* argv[], int pos)
{
    printf ("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "html\\index.html";

    system (help_src);

    return 0;
}


void process_arguments (int                    argc,      const char* argv[],
                        const struct OptionDef Options[], int         options_range)
{
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
}
