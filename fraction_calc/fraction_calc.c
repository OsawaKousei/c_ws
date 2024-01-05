#include <stdio.h>
#include <stdlib.h>
#include "fraction_logic.h" //自作ヘッダファイルは""で囲む

enum
{
    ADD = 1,
    SUB,
    MUL,
    DIV
};

void get_input(fraction *f1, fraction *f2, int *choice);
void calculate_fraction(fraction f1, fraction f2, fraction *result, int choice);
void print_result(fraction result);

int main(void)
{
    int num;
    int choice; // 1: add, 2: sub, 3: mul, 4: div
    fraction *fractions;

    while (1)
    {
        printf("enter number of fraction. (enter 0 to quit): ");
        scanf("%d", &num);

        // 動的メモリ確保
        fractions = (fraction *)malloc(sizeof(fraction) * (num + 1)); // 0番目をresultに使う

        if (num == 0)
        {
            printf("OK quit\n");
            break;
        }

        get_input(&fractions[1], &fractions[2], &choice);

        if (fractions[1].denominator != 0 && fractions[2].denominator != 0)
        {
            calculate_fraction(fractions[1], fractions[2], &fractions[0], choice);
            print_result(fractions[0]);
        }
        else
        {
            printf("ERROR: Denominator is 0\n");
        }

        // メモリ解放
        free(fractions);
    }

    return 0;
}

void get_input(fraction *f1, fraction *f2, int *choice)
{
    printf("Enter operation (1 = add, 2 = sub, 3 = mul, 4 = div, 5 = quit): ");
    scanf("%d", choice);

    printf("Enter fraction 1 numerator: ");
    scanf("%d", &f1->numerator);
    printf("Enter fraction 1 denominator: ");
    scanf("%d", &f1->denominator);

    printf("Enter fraction 2 numerator: ");
    scanf("%d", &f2->numerator);
    printf("Enter fraction 2 denominator: ");
    scanf("%d", &f2->denominator);
}

void calculate_fraction(fraction f1, fraction f2, fraction *result, int choice)
{
    switch (choice)
    {
    case ADD:
        printf("OK calculate %d / %d + %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        add_fraction(f1, f2, result);
        break;

    case SUB:
        printf("OK calculate %d / %d - %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        sub_fraction(f1, f2, result);
        break;

    case MUL:
        printf("OK calculate %d / %d × %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        mul_fraction(f1, f2, result);
        break;

    case DIV:
        printf("OK calculate %d / %d ÷ %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        div_fraction(f1, f2, result);
        break;

    default:
        printf("ERROR: Invalid input\n");
        break;
    }
}
void print_result(fraction result)
{
    printf("result:%d / %d\n", result.numerator, result.denominator);
}
