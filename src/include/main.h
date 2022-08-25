
#ifndef MAIN_H
#define MAIN_H

#include "square_equation.h"

// Command line arguments

const OptionDef Options[] =
{
    {"--test",     unit_test},
    {"-t",         unit_test},
    {"/t",         unit_test},

    {"--help",     print_help},
    {"-h",         print_help},
    {"/h",         print_help},

    {"--log",      open_log},
    {"-l",         open_log},
    {"/l",         open_log},

    {"--graphics", start_progress_bar},
    {"-g",         start_progress_bar},
    {"/g",         start_progress_bar}
};

// Command line arguments

#endif
