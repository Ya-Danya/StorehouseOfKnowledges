#include "storehouse.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum { max_len = 10000 }; // максимальная длина.
    int len; // текущая длина
    storehouse cont[max_len];
};

// Инициализация контейнера.
void Init(container& c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container& c);

// Ввод содержимого контейнера из указанного потока.
void In(container& c, FILE* fileInput);

// Рандомный ввод.
void InRnd(container& c, int n);

// Удаление элементов, значение перцентиля знаков препинания которых меньше среднего.
void DeletingElements(container& c);

// Вывод содержимого контейнера в указанный поток.
void Out(container& c, FILE* fileOutput);
