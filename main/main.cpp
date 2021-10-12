//------------------------------------------------------------------------------
// main.cpp - �������� ������� �������, 
// �������������� ������� ������������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
        "  Waited:\n"
        "     command -f inputfile outfile01 outfile02\n"
        "  Or:\n"
        "     command -n inputfile outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
        "  Waited:\n"
        "     command -f infile outfile01 outfile02\n"
        "  Or:\n"
        "     command -r number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
// ���������� ������ ���������� ���207 262. ������� 10 19.
// argc - ���-�� ���������� ��������� ������.
// argv - ���� ���������.
int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Programm begins.\n");
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        FILE* fileInput = fopen(argv[2], "r");
        In(c, fileInput);
    }
    else if (!strcmp(argv[1], "-r")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = \n");
            printf(argv[2]);
            printf(". Set 0 < number <= 10000\n");
            return 3;
        }
        // ��������� ���� � �������� ��������������
        srand(static_cast<unsigned int>(time(0)));
        // ���������� ���������� ����������� ��������� �����
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // ����� ����������� ���������� � ����
    FILE* fileOutput = fopen(argv[3], "w");
    fprintf(fileOutput, "Filled container:\n");
    Out(c, fileOutput);

    // ������ ������ ������ ����� �������.
    FILE* outfile2 = fopen(argv[4], "w");
    fprintf(outfile2, "Container after deleting elements:\n");
    DeletingElements(c);
    Out(c, outfile2);

    Clear(c);
    printf("Program ended.\n");
    return 0;
}
