
//-----------------------------------------------------------------------------

#define $(X)  printf  ("%s:%03d>>> " #X "\n", __FILE__, __LINE__); X

#define DO(X)           fprintf    (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);              \
                        fputc      ('|', LOG_FILE);                                           \
                        put_spaces (SPACING*4),                                               \
                        fprintf    (LOG_FILE, "%25s:%03d>>> " #X "\n", __FILE__, __LINE__), X

#define LOG_ARGV(...)   fprintf    (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);              \
                        fputc      ('|', LOG_FILE);                                           \
                        put_spaces (SPACING*4),                                               \
                        fprintf    (LOG_FILE, __VA_ARGS__),                                   \
                        fputc      ('\n', LOG_FILE)

#define LOG_FUNC(...)   fprintf (LOG_FILE, __VA_ARGS__)

#define __TRACK__       MakeSpace Tmp (__func__);


//-----------------------------------------------------------------------------

bool get_log_file(char file_name[]);

int open_log (int argc, const char* argv[], int pos);

void finish_log ();

void put_spaces(int spaces_amount);

//-----------------------------------------------------------------------------

class MakeSpace
{

public:
    MakeSpace (const char* str)
    {
        fprintf (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);
        fputc('|', LOG_FILE);
        put_spaces(SPACING++ * 4);

        LOG_FUNC("%s\n", str);

        this->func_name = str;
    }

   ~MakeSpace ()
   {
        fprintf (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);
        fputc('|', LOG_FILE);
        put_spaces(--SPACING * 4);

        LOG_FUNC("%s\n", this->func_name);
   }

private:
    const char* func_name;

};

//-----------------------------------------------------------------------------

//Global/Const-----------------------------------------------------------------

extern FILE* LOG_FILE = nullptr;

extern int LOG_LEVEL = 9;

extern const char DEFAULT_LOG_NAME[] = "log.txt";

extern char ACTIVE_LOGFILE_NAME[] = "log.txt";

extern int SPACING = 0;

//Global/Const-----------------------------------------------------------------
