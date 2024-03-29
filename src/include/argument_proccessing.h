//{---------------------------
//! @file argument_proccessing.h
//{---------------------------

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


/// ��������� ��� �������� �������� ���������� ��������� ������
struct OptionDef
{
    const char* name;

    int (*func)(int argc, const char* argv[], int argc_pos);
};


/// \brief   ������� ��������� ���������� ��������� ������
/// \arg     argc - ���������� ���������� ��������� ������ ��� ������� .exe �����
/// \arg     argv - ������ �������� ����������
/// \arg     options - ������ �������� � ��������� ��������� � ��������������� ��� ��������
/// \arg     options_range - ������ ������� ����������
/// \note    ���������� ��������� ���� ��������� ���������� �� ����� ������� ����������.
/// \warning ������� �� ����� ���������� ����� ������ �������� ������ �������.

void process_arguments (int                    argc,      const char* argv[],
                       const struct OptionDef  Options[], int         options_range);

/// \brief ������� ��� ��������� ��������� ��������� ������ -h, /h, --help
/// \arg     argc - ���������� ���������� ��������� ������ ��� ������� .exe �����
/// \arg     argv - ������ �������� ����������

int print_help(int argc, const char* argv[], int pos);

//-----------------------------------------------------------------------------

#endif
