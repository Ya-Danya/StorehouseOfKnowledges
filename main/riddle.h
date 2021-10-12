#ifndef __riddle__
#define __riddle__

#include "stdio.h"

//------------------------------------------------------------------------------
// �������.
struct riddle {
    char* answer; // �����.
    char* text; // �����.
};

// ���� ���������� ������� �� �����.
void In(riddle& t, FILE* fileInput);

// ��������� ���� ���������� �������.
void InRnd(riddle& r);

// ����� ���������� ������� � ������������� �����.
void Out(riddle& t, FILE* fileOutput);

// ���������� ������ ���������� �������� �� ����� ������.
float PercentOfPunctuationMarks(riddle& r);

#endif
