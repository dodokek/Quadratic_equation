//{---------------------------
//! @file unit_tests.h
//{---------------------------

/// \brief Функция отвечает за вызов Unit тестов квадратного уравнения

void start_unit_test();

/// \brief Функция, отвечающая за отдельный тест
/// \param test_data[] Массив хранит в себе тестовые данные(коэфиценты и ответы)
/// \param num_of_test
/// \warning Можно впасть в тильт от написания тестов

void unit_test_quadratic_equation (double test_data[], int num_of_test);

FILE* get_tests_file();

void start_unit_test()
{
    Debug = true;

    FILE *tests_file = get_tests_file();

    if (tests_file == NULL)
    {
        printf ("Failed to open the file %s\n", default_file_name);

        return;
    }

    int num_of_test = 1;

    while (true)
    {
        int check_EOF = 1;
        double test_data[5] = {};

        check_EOF = fscanf (tests_file, "%lg %lg %lg %lg %lg",
                            test_data,
                            test_data + 1,  test_data + 2,
                            test_data + 3,  test_data + 4);

        if (check_EOF == EOF) break;

        unit_test_quadratic_equation (test_data, num_of_test);

        assert (num_of_test > 0);

        num_of_test++;

    }

    fclose (tests_file);
}


void unit_test_quadratic_equation (double test_data[], int    num_of_test)
{
    assert (test_data != NULL && num_of_test > 0);

    int a_indx = 0;
    int b_indx = 0;
    int c_indx = 0;

    int x1_indx = 3;
    int x2_indx = 4;

    double roots_array[2] = { POISON_NUM, POISON_NUM };

    quadratic_equation::calculate_roots (roots_array, test_data);

    assert (roots_array[0] == roots_array[0] && roots_array[1] == roots_array[1]);

    if (roots_array[0] < roots_array[1])
    {
        std::swap (roots_array[0], roots_array[1]);
    }

    if (   is_equal (test_data[x1_indx], roots_array[0])
        && is_equal (test_data[x2_indx], roots_array[1]))
    {
        $sg; printf ("Unit test %d passed\n", num_of_test);
    }
    else
    {
        $sr; printf ("Unit test %d not passed, with data %lg %lg %lg,"
                     "excepted %lg %lg, received %lg %lg\n",
                     num_of_test,
                     test_data[a_indx],   test_data[b_indx ], test_data[c_indx],
                     test_data[x1_indx],  test_data[x2_indx],
                     roots_array[a_indx], roots_array[c_indx]);
    }

    txSleep (100);
}


FILE* get_tests_file()
{

    char file_name[]  = {};

    if (strcmp (default_file_name, "keyboard_input") == 0)
    {
        printf ("Enter file name.\n");

        scanf  ("%s", file_name);

        assert (file_name[0] != '\0');

        return fopen (file_name, "r");
    }

    else
    {
        return fopen (default_file_name, "r");
    }

    printf ("File name %s\n", file_name);
}
