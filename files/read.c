#include <stdio.h>
int main(int arg, char *argv[])
{

    FILE *fichier = NULL;
    fichier = fopen("test.txt", "r");
    int caractereActuel = 0;
    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c\n", caractereActuel);  // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}