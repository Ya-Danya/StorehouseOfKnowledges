#ifndef __riddle__
#define __riddle__

#include "stdio.h"

//------------------------------------------------------------------------------
// Загадка.
struct riddle {
    char* answer; // Ответ.
    char* text; // Текст.
};

// Ввод параметров загадки из файла.
void In(riddle& t, FILE* fileInput);

// Случайный ввод параметров загадки.
void InRnd(riddle& r);

// Вывод параметров загадки в форматируемый поток.
void Out(riddle& t, FILE* fileOutput);

// Количество знаков пунктуации деленное на длину строки.
float PercentOfPunctuationMarks(riddle& r);

#endif
