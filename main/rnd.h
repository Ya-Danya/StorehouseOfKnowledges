#ifndef __rnd__
#define __rnd__
#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>

// ��������� ����� (riddle, proverb, aphorism).
inline int RandomType() {
    return rand() % 3 + 1;
}

// ��������� ��������� �����.
inline char* RandomString() {
    int l = rand() % 200 + 1; // ��������� ����� �����.
    char* str = new char[l];
	for (int i = 0; i < l-1; i++) {
        str[i] = rand() % 205 + 50;
	}
    str[l - 1] = '\0';
    return str;
}

#endif //__rnd__
