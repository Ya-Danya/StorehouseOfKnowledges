#ifndef __storehouse__
#define __storehouse__

#include "riddle.h"
#include "proverb.h"
#include "aphorism.h"
#include "rnd.h";

//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся фигуры.
struct storehouse {
    // Значения ключей для каждой из фигур.
    enum key { RIDDLE, PROVERB, APHORISM };
    key k; // Ключ.
    // Используемые альтернативы.
    union { // Используем простейшую реализацию.
        riddle r;
        proverb p;
        aphorism a;
    };
};

// Ввод обобщенной фигуры.
bool In(storehouse& s, FILE* fileInput, int k);

// Случайный ввод обобщенной фигуры.
bool InRnd(storehouse& s);

// Вывод обобщенной фигуры
void Out(storehouse& s, FILE* fileOutput);

// Количество знаков пунктуации деленное на длину строки.
float PercentOfPunctuationMarks(storehouse& s);

#endif