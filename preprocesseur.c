#include <stdio.h>
/*  __LINE__ donne le numéro de la ligne actuelle.

__FILE__ donne le nom du fichier actuel.

__DATE__ donne la date de la compilation.

__TIME__ donne l'heure de la compilation. */

#define COUCOU() printf("Coucou\n");
#define MAJEUR(age, nom) \
    if (age >= 18)       \
        printf("Vous etes majeur %s\n", nom);
int main(int argc, char *argv[])
{
    COUCOU()
    MAJEUR(22, "maxime")
    return 0;
}
