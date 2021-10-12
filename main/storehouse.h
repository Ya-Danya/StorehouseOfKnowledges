#ifndef __storehouse__
#define __storehouse__

#include "riddle.h"
#include "proverb.h"
#include "aphorism.h"
#include "rnd.h";

//------------------------------------------------------------------------------
// ���������, ���������� ��� ��������� ������.
struct storehouse {
    // �������� ������ ��� ������ �� �����.
    enum key { RIDDLE, PROVERB, APHORISM };
    key k; // ����.
    // ������������ ������������.
    union { // ���������� ���������� ����������.
        riddle r;
        proverb p;
        aphorism a;
    };
};

// ���� ���������� ������.
bool In(storehouse& s, FILE* fileInput, int k);

// ��������� ���� ���������� ������.
bool InRnd(storehouse& s);

// ����� ���������� ������
void Out(storehouse& s, FILE* fileOutput);

// ���������� ������ ���������� �������� �� ����� ������.
float PercentOfPunctuationMarks(storehouse& s);

#endif