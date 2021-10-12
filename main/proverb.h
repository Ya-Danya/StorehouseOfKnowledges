#ifndef __proverb__
#define __proverb__

#include "stdio.h"

//------------------------------------------------------------------------------
// Пословица.
struct proverb {
    char* country; // Страна.
    char* text; // Текст.
};

// Ввод параметров пословицы из файла.
void In(proverb& p, FILE* fileInput);

// Случайный ввод параметров пословицы.
void InRnd(proverb& p);

// Вывод параметров пословицы в форматируемый поток.
void Out(proverb& p, FILE* fileOutput);

// Количество знаков пунктуации деленное на длину строки.
float PercentOfPunctuationMarks(proverb& p);

#endif