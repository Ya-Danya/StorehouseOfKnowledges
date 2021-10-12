#define _CRT_SECURE_NO_WARNINGS

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти).
void Clear(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void In(container& c, FILE* fileInput) {
    int k;
    while (fscanf(fileInput, "%d", &k) != EOF) {
        if ((In(c.cont[c.len], fileInput, k))) {
            c.len++;
        }
    }
}

// Рандомный ввод.
void InRnd(container& c, int size) {
    while (c.len < size) {
        if (InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}
//------------------------------------------------------------------------------
// Удаление элементов, значение перцентиля знаков препинания которых меньше среднего.
void DeletingElements(container& c) {
    if (c.len != 0) {
        double sum = 0;
        for (int i = 0; i < c.len; ++i) {
            sum += PercentOfPunctuationMarks(c.cont[i]);
        }
        double average = sum / c.len;
        int counter = 0;
        for (int i = 0; i < c.len; ++i) {
            if (PercentOfPunctuationMarks(c.cont[i]) < average) {
                for (int j = i + 1; j < c.len; ++j) {
                    c.cont[j - 1] = c.cont[j];
                }
                c.len--;
                i--;
            }
        }
    }
}
//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Out(container& c, FILE* fileOutput) {
    fprintf(fileOutput, "Container contains %d elements.\n\n", c.len);
    for (int i = 0; i < c.len; i++) {
        fprintf(fileOutput, "%d: ", i);
        Out(c.cont[i], fileOutput);
    }
}


