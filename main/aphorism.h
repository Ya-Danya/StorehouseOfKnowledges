#ifndef __aphorism__
#define __aphorism__

#include "stdio.h"

//------------------------------------------------------------------------------
// �������.
struct aphorism {
    char* author; // �����.
    char* text; // �����.
};

// ���� ���������� �������� �� �����.
void In(aphorism& a, FILE* fileInput);

// ��������� ���� ���������� ��������.
void InRnd(aphorism& a);

// ����� ���������� �������� � ������������� �����.
void Out(aphorism& a, FILE* fileInput);

// ���������� ������ ���������� �������� �� ����� ������.
float PercentOfPunctuationMarks(aphorism& a);

#endif