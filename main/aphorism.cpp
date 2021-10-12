#define _CRT_SECURE_NO_WARNINGS

#include "aphorism.h"
#include "rnd.h";

//------------------------------------------------------------------------------
// Ввод параметров загадки из файла
void In(aphorism& a, FILE* fileInput) {
	char* str1 = new char[201];
	char* str2 = new char[201];
	char* y = new char[3];
	fgets(y, 3, fileInput);
	fgets(str1, 201, fileInput);
	fgets(str2, 201, fileInput);
	a.text = str1;
	a.author = str2;
}

// Генерация рандомного aphorism.
void InRnd(aphorism& a) {
	a.text = RandomString();
	a.author = RandomString();
}

// Количество знаков пунктуации деленное на длину строки.
float PercentOfPunctuationMarks(aphorism& a) {
	int lengthOfString = 0;
	float countOfPunctuations = 0;
	while (a.text[lengthOfString] != '\0')
	{
		if (a.text[lengthOfString] == ',' || a.text[lengthOfString] == '.' ||
			a.text[lengthOfString] == '?' || a.text[lengthOfString] == ':' ||
			a.text[lengthOfString] == '-' || a.text[lengthOfString] == ';' ||
			a.text[lengthOfString] == '!') {
			countOfPunctuations += 1.0;
		}
		lengthOfString++;
	}
	return countOfPunctuations /lengthOfString;
}

// Вывод параметров загадки в форматируемый поток
void Out(aphorism& a, FILE* fileOutput) {
	fprintf(fileOutput, "Aphorism with text:\n%sAuthor of this aphorism:\n%sPercent of punctuation marks: %f \n\n",
		a.text, a.author, PercentOfPunctuationMarks(a));
}
