typedef struct
{
    int numerator;
    int denominator;
} fraction;

void add_fraction(fraction f1, fraction f2, fraction *result);
void sub_fraction(fraction f1, fraction f2, fraction *result);
void mul_fraction(fraction f1, fraction f2, fraction *result);
void div_fraction(fraction f1, fraction f2, fraction *result);
void about_fraction(fraction *result);