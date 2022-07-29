//{----------------------------------------------------------------------------
//! @file square_equation.h
//{----------------------------------------------------------------------------

void clear_buffer  (char stop_sym);

bool check_on_exit (char exit_sym);

//-----------------------------------------------------------------------------

void clear_buffer (char stop_sym)
{
    while (getchar() != stop_sym) ;
}


bool check_on_exit (char exit_sym)
{
    return (getchar() == exit_sym) ? true : false;
}
