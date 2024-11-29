#include "../headers/main.h"
#include "../headers/aire.h"
/* Contenu de votre fichier .h (autres include, prototypes, define...) */

int main(int arg, char *argv[])
{
    double resultat;
    resultat = aireRectangle(5.0, 10.0);
    printf("L'aire du rectangle est : %.2f\n", resultat);
    return 0;
}