#include <stdio.h>
#include "../headers/aire.h"

int main(int arg, char *argv[])
{
    double resultat;
    resultat = aireRectangle(5.0, 10.0);
    printf("L'aire du rectangle est : %.2f\n", resultat);
    return 0;
}