#ifndef __rnd__
#define __rnd__
#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>

// Генератор типов (riddle, proverb, aphorism).
inline int RandomType() {
    return rand() % 3 + 1;
}

// Генератор рандомных строк.
inline char* RandomString() {
    int l = rand() % 200 + 1; // Генерация длины слова.
    char* str = new char[l];
	for (int i = 0; i < l-1; i++) {
        str[i] = rand() % 205 + 50;
	}
    str[l - 1] = '\0';
    return str;
}

#endif //__rnd__
