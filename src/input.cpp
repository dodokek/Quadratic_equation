
#include "include/input.h"

//-----------------------------------------------------------------------------

void clear_buffer (char stop_sym)
{
    while (getchar() != stop_sym) ;
}


bool check_on_exit (char exit_sym)
{
    return getchar() == exit_sym;
}

