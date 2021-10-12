#include "storehouse.h"

//------------------------------------------------------------------------------
// ���������� ��������� �� ������ ����������� �������.
struct container {
    enum { max_len = 10000 }; // ������������ �����.
    int len; // ������� �����
    storehouse cont[max_len];
};

// ������������� ����������.
void Init(container& c);

// ������� ���������� �� ��������� (������������ ������).
void Clear(container& c);

// ���� ����������� ���������� �� ���������� ������.
void In(container& c, FILE* fileInput);

// ��������� ����.
void InRnd(container& c, int n);

// �������� ���������, �������� ���������� ������ ���������� ������� ������ ��������.
void DeletingElements(container& c);

// ����� ����������� ���������� � ��������� �����.
void Out(container& c, FILE* fileOutput);
