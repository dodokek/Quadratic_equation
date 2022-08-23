//{---------------------------
//! @file log.h
//{---------------------------

#ifndef LOGGING

//-----------------------------------------------------------------------------

#define $(X)            printf  ("%s:%03d>>> " #X "\n", __FILE__, __LINE__); X

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

#define __TRACKBEGIN__       add_tree_level       (__func__);
#define __TRACKEND__         substract_tree_level (__func__);

#define LOGGING _LOGGING

//Global/Const-----------------------------------------------------------------

static FILE* LOG_FILE = nullptr;

static int LOG_LEVEL = 9;

const char DEFAULT_LOG_NAME[] = "log.txt";

static char ACTIVE_LOGFILE_NAME[] = "log.txt";

static int SPACING = 0;

//Global/Const-----------------------------------------------------------------

//-----------------------------------------------------------------------------

/// \brief Функция для считывания файла, куда будут писаться логи
/// \param file_name [in] Имя файла
/// \return Успешно ли было считывание файла

bool get_log_file         (char file_name[]);

/// \brief Функция для считывания аргументов командной строки для работы с логами
/// \param argc [in] Количество аргументов командной строки
/// \param pos [in]  Текущая позиция аргумента командной строки
/// \note Файл можно задавать самому

int open_log              (int argc, const char* argv[], int pos);

/// \brief Окончание логирования

void finish_log           ();

/// \brief Постановка пробелов для дерева функций
/// \param [in] spaces_amount Количество нужных для постановки пробелов

void put_spaces           (int spaces_amount);

/// \brief Функция для углубления на один уровень в дереве функций
/// \param Имя функцию, в которую мы входим
/// \note Важно писать в самом начале

void add_tree_level       (const char* func_name);

/// \brief Функция, противоположная add_tree_level
/// \note Важно писать прямо перед завершающим элементом функции

void substract_tree_level (const char* func_name);

//-----------------------------------------------------------------------------

#endif
