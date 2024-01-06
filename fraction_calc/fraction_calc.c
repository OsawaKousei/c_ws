#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fraction_logic.h" //自作ヘッダファイルは""で囲む

enum
{
    ADD = 1,
    SUB,
    MUL,
    DIV,
    STOP
};

typedef struct
{
    fraction fractions;
    int operation;
} formula;

void get_input(formula formulas[], int i);
void calculate_fraction(fraction f1, fraction f2, fraction *result, int choice);
void print_result(fraction result);

int main(void)
{
    int num;
    int choice; // 1: add, 2: sub, 3: mul, 4: div, 5: stop
    formula *formulas;

    while (1)
    {
        printf("enter number of fraction. (enter 0 to quit): ");
        scanf("%d", &num);

        // 動的メモリ確保
        formulas = (formula *)malloc(sizeof(formula) * (num + 2)); // 0番目をresultに使う,n+1番目は終了処理を一般化するため確保

        if (num == 0)
        {
            printf("OK quit\n");
            break;
        }

        for (int i = 1; i <= num; i++)
        {

            get_input(formulas, i);
            if (!check_denominator(formulas[i].fractions))
            {
                printf("ERROR: denominator is 0\n");
                i--;
            }
        }

        for (int i = 1; i <= num; i++)
        {
            calculate_fraction(formulas[i].fractions, formulas[i + 1].fractions, &formulas[0].fractions, formulas[i].operation);
        }
        print_result(formulas[0].fractions);

        // メモリ解放
        free(formulas);
    }

    return 0;
}

void get_input(formula formulas[], int i)
{
    printf("Enter fraction %d numerator: ", i);
    scanf("%d", formulas[i].fractions.numerator);
    printf("Enter fraction %d denominator: ", i);
    scanf("%d", formulas[i].fractions.denominator);

    printf("Enter operation (1 = add, 2 = sub, 3 = mul, 4 = div, 5 = stop): ");
    scanf("%d", formulas[i].operation);
}

void calculate_fraction(fraction f1, fraction f2, fraction *result, int choice)
{
    switch (choice)
    {
    case ADD:
        printf("calculate %d / %d + %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        add_fraction(f1, f2, result);
        break;

    case SUB:
        printf("calculate %d / %d - %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        sub_fraction(f1, f2, result);
        break;

    case MUL:
        printf("calculate %d / %d × %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        mul_fraction(f1, f2, result);
        break;

    case DIV:
        printf("calculate %d / %d ÷ %d / %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
        div_fraction(f1, f2, result);
        break;

    case STOP:
        printf("calculate finished\n");
        break;

    default:
        printf("ERROR: something went mad\n");
        break;
    }
}
void print_result(fraction result)
{
    printf("result:%d / %d\n", result.numerator, result.denominator);
}
