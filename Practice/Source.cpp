#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

void Function(const char** odin, const char** dva, const char** tri, const char** chetir, const char** pyat, const char** shest, int a, int b, int c, int d, int e, int f);

const char* edin[] = { "одна", "дв≥", "три", "чотири", "п'€ть", "ш≥сть", "с≥м", "в≥с≥м", "дев'€ть" };
const char* teen[] = { "одинадц€ть", "дванадц€ть", "тринадц€ть", "чотирнадц€ть", "п'€тнадц€ть", "ш≥стнадц€ть", "с≥мнадц€ть", "в≥с≥мнадц€ть", "дев'€тнадц€ть" };
const char* des[] = { "двадц€ть", "тридц€ть", "сорок", "п'€тдес€т", "ш≥стдес€т", "с≥мдес€т", "в≥с≥мдес€т", "дев'€носто" };
const char* sto[] = { "сто", "дв≥ст≥", "триста", "чотириста", "п'€тсот", "ш≥стсот", "с≥мсот", "в≥с≥мсот", "дев'€тсот" };
const char* thousand[] = { "одна тис€ча", "дв≥ тис€ч≥", "три тис€ч≥", "чотир≥ тис€ч≥", "п'€ть тис€ч", "ш≥сть тис€ч", "с≥м тис€ч", "в≥с≥м тис€ч", "д'ев€ть тис€ч" };
int main()
{
    setlocale(LC_ALL, "ukr");

    double  numb, i, drobn;
    int natur, dr;          //перем≥нн≥ дл€ роботи з ц≥лими ≥ дробовими
    int a, b, c, d, e, f;   //"тимчасов≥" перем≥нн≥ дл€ ц≥лих
    int x, y;            //"тимчасов≥" перем≥нн€ дл€ дробовоњ частини
    const char* odin = "", * dva = "", * tri = "", * chetir = "", * pyat = "", * shest = ""; //перем≥нн≥ дл€ ц≥лих
    const char* one = "", * two = "";//переменные дл€ дробной части

    printf("¬ведите число: ");
    scanf_s("%lf", &numb);

    drobn = modf(numb, &i);
    drobn *= 1000;
    dr = drobn + 0.5;
    natur = (int)numb;


    //разбиваем число на составные цифры дл€ целой части
    a = natur % 10;                 //число одиниць
    b = (natur % 100) / 10;         //число дес€тк≥в
    c = (natur % 1000) / 100;       //число сотень
    f = natur / 100000;             //число сотень тис€
    e = (natur % 100000) / 10000;   //число дес€тков тис€ч
    d = (natur % 10000) / 1000;    //число тис€ч

   //р≥шенн€ дл€ ц≥лоњ частини
    Function(&odin, &dva, &tri, &chetir, &pyat, &shest, a, b, c, d, e, f);

    //дробова частина
    x = dr / 100;
    y = (dr % 100) / 10;

    if (y == 0)       //дес€т≥
    {
        if (x == 0)
            one = " ";
        else if (x == 0)
            one = edin[x - 1];
        else
            one = strcat(_strdup(des[x - 2]), " коп≥йок");
    }

    if (y != 0)       //сот≥
    {
        if (x == 0)
        {
            if (y == 1)
                two = strcat(_strdup(edin[y - 1]), " коп≥йок");
            else
                two = strcat(_strdup(edin[y - 1]), " коп≥йок");
        }
        else if (x == 1)
            two = strcat(_strdup(teen[y - 1]), " коп≥йок");
        else if (x != 0)
        {
            two = des[x - 2];
            one = strcat(_strdup(edin[y - 1]), " коп≥йок");
        }
    }
    printf(" %s %s  %s ", shest, pyat, chetir);
    printf(" %s %s  %s ", tri, dva, odin);
    if (a == 1)
        printf(" гривн€");
    else
        printf(" гривень");
    printf(" %s %s ", two, one);
}

void Function(const char** odin, const char** dva, const char** tri, const char** chetir, const char** pyat, const char** shest, int a, int b, int c, int d, int e, int f)
{
    if (a != 0 && b != 1)
        *odin = edin[a - 1];
    else if (a == 0 && b == 1)
        *odin = "дес€ть";
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
        *odin = "ноль";

    if (d != 0)
        *chetir = thousand[d - 1];
    else if (d == 0 && e == 1)
        *chetir = "дес€ть тис€ч";
    else if (d != 0 && e == 1)
        *pyat = strcat(_strdup(teen[d - 1]), " тис€ч");
}