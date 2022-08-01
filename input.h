//{----------------------------------------------------------------------------
//! @file square_equation.h
//{----------------------------------------------------------------------------

void clear_buffer  (char stop_sym);

bool check_on_exit (char exit_sym);

//-----------------------------------------------------------------------------

void clear_buffer (char stop_sym)
{
    __TRACK__
    while (getchar() != stop_sym) ;
}


bool check_on_exit (char exit_sym)
{
    __TRACK__
    return (getchar() == exit_sym) ? true : false;
}
