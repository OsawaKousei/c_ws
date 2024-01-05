#include <stdio.h>
#include "fraction_logic.h" //自作ヘッダファイルは""で囲む

enum
{
    ADD = 1,
    SUB,
    MUL,
    DIV,
    ABOUT,
    QUIT
};

void get_input(fraction *f1, fraction *f2, int *choice);
void calculate_fraction(fraction f1, fraction f2, fraction *result, int choice);
void print_result(fraction result);

int main(void)
{
    fraction f1, f2, result;
    int choice;

    while (1)
    {
        get_input(&f1, &f2, &choice);

        if (choice == QUIT)
        {
            printf("OK quit\n");
            break;
        }

        if (f1.denominator != 0 && f2.denominator != 0)
        {
            calculate_fraction(f1, f2, &result, choice);
            print_result(result);
        }
        else
        {
            printf("ERROR: Denominator is 0\n");
        }
    }

    return 0;
}

void get_input(fraction *f1, fraction *f2, int *choice)
{
    printf("Enter operation (1 = add, 2 = sub, 3 = mul, 4 = div, 5 = about, 6 = quit): ");
    scanf("%d", choice);

    if (*choice == QUIT) // 引数はポインタなので、*で値を取得することに注意
    {
        return;
    }

    printf("Enter fraction 1 numerator: ");
    scanf("%d", &f1->numerator);
    printf("Enter fraction 1 denominator: ");
    scanf("%d", &f1->denominator);

    if (*choice != ABOUT)
    {
        printf("Enter fraction 2 numerator: ");
        scanf("%d", &f2->numerator);
        printf("Enter fraction 2 denominator: ");
        scanf("%d", &f2->denominator);
    }
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

    case ABOUT:
        printf("OK about %d / %d\n", f1.numerator, f1.denominator);

        result->numerator = f1.numerator;
        result->denominator = f1.denominator;

        about_fraction(result);
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
