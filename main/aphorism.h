#ifndef __aphorism__
#define __aphorism__

#include "stdio.h"

//------------------------------------------------------------------------------
// Афоризм.
struct aphorism {
    char* author; // Автор.
    char* text; // Текст.
};

// Ввод параметров афоризма из файла.
void In(aphorism& a, FILE* fileInput);

// Случайный ввод параметров афоризма.
void InRnd(aphorism& a);

// Вывод параметров афоризма в форматируемый поток.
void Out(aphorism& a, FILE* fileInput);

// Количество знаков пунктуации деленное на длину строки.
float PercentOfPunctuationMarks(aphorism& a);

#endif