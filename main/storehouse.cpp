#define _CRT_SECURE_NO_WARNINGS

#include "storehouse.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
bool In(storehouse& s, FILE* fileInput, int k) {
    switch (k) {
    case 1:
        s.k = storehouse::APHORISM;
        In(s.a, fileInput);
        return true;
    case 2:
        s.k = storehouse::RIDDLE;
        In(s.r, fileInput);
        return true;
    case 3:
        s.k = storehouse::PROVERB;
        In(s.p, fileInput);
        return true;
    default:
        return false;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод обобщенной фигуры
bool InRnd(storehouse& s) {
    int k = RandomType();
    switch (k) {
    case 1:
        s.k = storehouse::APHORISM;
        InRnd(s.a);
        return true;
    case 2:
        s.k = storehouse::RIDDLE;
        InRnd(s.r);
        return true;
    case 3:
        s.k = storehouse::PROVERB;
        InRnd(s.p);
        return true;
    default:
        return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(storehouse& s, FILE* fileOutput) {
    switch (s.k) {
    case storehouse::APHORISM:
        Out(s.a, fileOutput);
        break;
    case storehouse::RIDDLE:
        Out(s.r, fileOutput);
        break;
    case storehouse::PROVERB:
        Out(s.p, fileOutput);
        break;
    default:
        fprintf(fileOutput, "Incorrect type."); // дописать
    }
}

float PercentOfPunctuationMarks(storehouse& s) {
    switch (s.k) {
    case storehouse::APHORISM:
        return PercentOfPunctuationMarks(s.a);
    case storehouse::RIDDLE:
        return PercentOfPunctuationMarks(s.r);
    case storehouse::PROVERB:
        return PercentOfPunctuationMarks(s.p);
    default:
        return 4;
    }
}
