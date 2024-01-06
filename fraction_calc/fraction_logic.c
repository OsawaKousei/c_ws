#include <stdbool.h> // bool型を使うために必要
#include <stdio.h>

#define MAX(i, j) (((i) > (j)) ? (i) : (j)) // 三項演算子

typedef struct
{
    int numerator;
    int denominator;
} fraction;

void about_fraction(fraction *result)
{
    bool finflag = true;

    while (finflag)
    {
        finflag = false;

        for (int i = 2; i <= MAX(result->numerator, result->denominator); i++)
        {
            if (result->numerator % i == 0 && result->denominator % i == 0)
            {
                result->numerator /= i;
                result->denominator /= i;
                finflag = true;
            }
        }
    }
}
void add_fraction(fraction f1, fraction f2, fraction *result)
{
    result->numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result->denominator = f1.denominator * f2.denominator;

    about_fraction(result);
}
void sub_fraction(fraction f1, fraction f2, fraction *result)
{
    result->numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result->denominator = f1.denominator * f2.denominator;

    about_fraction(result);
}
void mul_fraction(fraction f1, fraction f2, fraction *result)
{
    result->numerator = f1.numerator * f2.numerator;
    result->denominator = f1.denominator * f2.denominator;

    about_fraction(result);
}
void div_fraction(fraction f1, fraction f2, fraction *result)
{
    result->numerator = f1.numerator * f2.denominator;
    result->denominator = f1.denominator * f2.numerator;

    about_fraction(result);
}
bool check_denominator(fraction f1)
{
    if (f1.denominator == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
