#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

void Function(const char** odin, const char** dva, const char** tri, const char** chetir, const char** pyat, const char** shest, int a, int b, int c, int d, int e, int f);

const char* edin[] = { "����", "��", "���", "������", "�'���", "�����", "��", "���", "���'���" };
const char* teen[] = { "����������", "����������", "����������", "������������", "�'���������", "�����������", "���������", "����������", "���'���������" };
const char* des[] = { "��������", "��������", "�����", "�'�������", "���������", "�������", "��������", "���'������" };
const char* sto[] = { "���", "����", "������", "���������", "�'�����", "�������", "�����", "������", "���'�����" };
const char* thousand[] = { "���� ������", "�� ������", "��� ������", "����� ������", "�'��� �����", "����� �����", "�� �����", "��� �����", "�'����� �����" };
int main()
{
    setlocale(LC_ALL, "ukr");

    double  numb, i, drobn;
    int natur, dr;          //������� ��� ������ � ������ � ���������
    int a, b, c, d, e, f;   //"��������" ������� ��� �����
    int x, y;            //"��������" �������� ��� ������� �������
    const char* odin = "", * dva = "", * tri = "", * chetir = "", * pyat = "", * shest = ""; //������� ��� �����
    const char* one = "", * two = "";//���������� ��� ������� �����

    printf("������� �����: ");
    scanf_s("%lf", &numb);

    drobn = modf(numb, &i);
    drobn *= 1000;
    dr = drobn + 0.5;
    natur = (int)numb;


    //��������� ����� �� ��������� ����� ��� ����� �����
    a = natur % 10;                 //����� �������
    b = (natur % 100) / 10;         //����� �������
    c = (natur % 1000) / 100;       //����� ������
    f = natur / 100000;             //����� ������ ����
    e = (natur % 100000) / 10000;   //����� �������� �����
    d = (natur % 10000) / 1000;    //����� �����

   //������ ��� ���� �������
    Function(&odin, &dva, &tri, &chetir, &pyat, &shest, a, b, c, d, e, f);

    //������� �������
    x = dr / 100;
    y = (dr % 100) / 10;

    if (y == 0)       //�����
    {
        if (x == 0)
            one = " ";
        else if (x == 0)
            one = edin[x - 1];
        else
            one = strcat(_strdup(des[x - 2]), " ������");
    }

    if (y != 0)       //���
    {
        if (x == 0)
        {
            if (y == 1)
                two = strcat(_strdup(edin[y - 1]), " ������");
            else
                two = strcat(_strdup(edin[y - 1]), " ������");
        }
        else if (x == 1)
            two = strcat(_strdup(teen[y - 1]), " ������");
        else if (x != 0)
        {
            two = des[x - 2];
            one = strcat(_strdup(edin[y - 1]), " ������");
        }
    }
    printf(" %s %s  %s ", shest, pyat, chetir);
    printf(" %s %s  %s ", tri, dva, odin);
    if (a == 1)
        printf(" ������");
    else
        printf(" �������");
    printf(" %s %s ", two, one);
}

void Function(const char** odin, const char** dva, const char** tri, const char** chetir, const char** pyat, const char** shest, int a, int b, int c, int d, int e, int f)
{
    if (a != 0 && b != 1)
        *odin = edin[a - 1];
    else if (a == 0 && b == 1)
        *odin = "������";
    else if (a == 0 && b == 0)
        *odin = "";

    if (b == 0)
        *dva = "";
    else if (b == 1 && a != 0)
        *dva = teen[a - 1];
    else if (b != 1)
        *dva = des[b - 2];

    if (c != 0)
        *tri = sto[c - 1];

    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
        *odin = "����";

    if (d != 0)
        *chetir = thousand[d - 1];
    else if (d == 0 && e == 1)
        *chetir = "������ �����";
    else if (d != 0 && e == 1)
        *pyat = strcat(_strdup(teen[d - 1]), " �����");
}