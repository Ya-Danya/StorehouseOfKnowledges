#define _CRT_SECURE_NO_WARNINGS

#include "proverb.h"
#include "rnd.h";

//------------------------------------------------------------------------------

// Ввод параметров пословицы из файла.
void In(proverb& p, FILE* fileInput) {
	char* str1 = new char[202];
	char* str2 = new char[202];
	char* y = new char[3];
	fgets(y, 3, fileInput);
	fgets(str1, 202, fileInput);
	fgets(str2, 202, fileInput);
	p.text = str1;
	p.country = str2;
}

// Генерация рандомного proverb.
void InRnd(proverb& p) {
	p.text = RandomString();
	p.country = RandomString();
}

float PercentOfPunctuationMarks(proverb& p) {
	int lengthOfString = 0;
	float countOfPunctuations = 0;
	while (p.text[lengthOfString] != '\0')
	{
		if (p.text[lengthOfString] == ',' || p.text[lengthOfString] == '.' ||
			p.text[lengthOfString] == '?' || p.text[lengthOfString] == ':' ||
			p.text[lengthOfString] == '-' || p.text[lengthOfString] == ';' ||
			p.text[lengthOfString] == '!') {
			countOfPunctuations += 1.0;
		}
		lengthOfString++;
	}
	return countOfPunctuations / lengthOfString;
}

// Вывод параметров пословицы в форматируемый поток.
void Out(proverb& p, FILE* fileOutput) {
	fprintf(fileOutput, "Proverb with text:\n%sCountry of this proverb:\n%sPercent of punctuation marks: %f \n\n",
		p.text, p.country, PercentOfPunctuationMarks(p));
}

