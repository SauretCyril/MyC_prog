#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* strlen pour calculer la longueur d'une chaîne.

strcpy pour copier une chaîne dans une autre.

strcat pour concaténer 2 chaînes.

strcmp pour comparer 2 chaînes.

strchr pour rechercher un caractère.

strpbrk pour rechercher le premier caractère de la liste.

strstr pour rechercher une chaîne dans une autre.

sprintf pour écrire dans une chaîne. */

int main(int argc, char *argv[])
{
    char chaine[] = "Salut";
    int longueurChaine = 0;

    // On récupère la longueur de la chaîne dans longueurChaine
    longueurChaine = strlen(chaine);

    // On affiche la longueur de la chaîne
    printf("La chaine %s fait %d caracteres de long", chaine, longueurChaine);

    return 0;
}