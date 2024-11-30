#include <stdio.h>

int tableau[4] = {12, 7, 14, 33};

int main()
{
    printf("%d", tableau[2]);
    return 0;
}

int hachage(char *chaine)
{
    int i = 0, nombreHache = 0;

    for (i = 0; chaine[i] != '\0'; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= 100;

    return nombreHache;
}