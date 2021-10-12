#ifndef __proverb__
#define __proverb__

#include "stdio.h"

//------------------------------------------------------------------------------
// ���������.
struct proverb {
    char* country; // ������.
    char* text; // �����.
};

// ���� ���������� ��������� �� �����.
void In(proverb& p, FILE* fileInput);

// ��������� ���� ���������� ���������.
void InRnd(proverb& p);

// ����� ���������� ��������� � ������������� �����.
void Out(proverb& p, FILE* fileOutput);

// ���������� ������ ���������� �������� �� ����� ������.
float PercentOfPunctuationMarks(proverb& p);

#endif