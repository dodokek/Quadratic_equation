
//-----------------------------------------------------------------------------

#define $(X) printf ("%s:%03d>>> " #X "\n", __FILE__, __LINE__); X

#define DO(X) fprintf (LOG_FILE, "%s:%03d>>>" #X "\n", __FILE__, __LINE__), X

#define LOG_ARGV(...) fprintf (LOG_FILE, "%s:%03d>>>", __FILE__, __LINE__),  \
                      fprintf (LOG_FILE, __VA_ARGS__),                       \
                      fputc ('\n', LOG_FILE)

//Global/Const-----------------------------------------------------------------

FILE* LOG_FILE = nullptr;

int LOG_LEVEL = 9;

char DEFAULT_LOG_NAME[] = "log.txt";

//Global/Const-----------------------------------------------------------------

//-----------------------------------------------------------------------------

bool get_log_file(char file_name[]);

int open_log (int argc, const char* argv[], int pos);

//-----------------------------------------------------------------------------


bool get_log_file(char file_name[])
{
    if (file_name[0] != '\0')
    {
        printf ("File name %s\n", file_name);

        LOG_FILE = fopen (file_name, "a");

        return true;
    }

    else
    {
        printf ("File name %s\n", DEFAULT_LOG_NAME);

        LOG_FILE = fopen (DEFAULT_LOG_NAME, "a");

        return true;
    }

    return false;
}


int open_log (int argc, const char* argv[], int pos)
{
    Debug = true;
    char file_name[] = "";
    int argument_indx = 0;

    for (int argc_pos = pos + 1; argc_pos < argc; argc_pos++, argument_indx++)
    {
        if (argv[argc_pos][0] != '-')
        {
            switch (argument_indx)
            {
                case 0:
                    strcpy (file_name, argv[argc_pos]);
                    break;

                case 1:
                    LOG_LEVEL = atoi(argv[argc_pos]);
                    break;

                default:
                    printf("Too much additional arguments\n");
            }

            continue;
        }
        break;
    }

    printf("Started to write logs...\n");

    get_log_file(file_name);

    if (!LOG_FILE)
    {
        printf ("Failed to open the file %s\n", file_name);
    }

    return argument_indx;
}













