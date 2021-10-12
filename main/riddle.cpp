#define _CRT_SECURE_NO_WARNINGS

#include "riddle.h"
#include "rnd.h";

//------------------------------------------------------------------------------

// Ввод параметров загадки из файла
void In(riddle& r, FILE* fileInput) {
	char* str1 = new char[202];
	char* str2 = new char[202];
	char* y = new char[3];
	fgets(y, 3, fileInput);
	fgets(str1, 202, fileInput);
	fgets(str2, 202, fileInput);
	r.text = str1;
	r.answer = str2;
}

// Генерация рандомного riddle.
void InRnd(riddle& r) {
	r.text = RandomString();
	r.answer = RandomString();
}

float PercentOfPunctuationMarks(riddle& r) {
	int lengthOfString = 0;
	float countOfPunctuations = 0;
	while (r.text[lengthOfString] != '\0')
	{
		if (r.text[lengthOfString] == ',' || r.text[lengthOfString] == '.' ||
			r.text[lengthOfString] == '?' || r.text[lengthOfString] == ':' ||
			r.text[lengthOfString] == '-' || r.text[lengthOfString] == ';' ||
			r.text[lengthOfString] == '!') {
			countOfPunctuations += 1.0;
		}
		lengthOfString++;
	}
	return countOfPunctuations / lengthOfString;
}

// Вывод параметров загадки в форматируемый поток
void Out(riddle& r, FILE* fileOutput) {
	fprintf(fileOutput, "Riddle with text:\n%sAnswer:\n%sPercent of punctuation marks: %f \n\n",
		r.text, r.answer, PercentOfPunctuationMarks(r));
}
