#include "main.h"

int main(int arg, char *argv[])
{

    FILE *fichier = NULL;
    fichier = fopen("test.txt", "w");

    if (fichier != NULL)
    {
        printf("fichier test.txt ouvert"); // On peut lire et écrire dans le fichier
        fputc('A', fichier);               // Écriture du caractère A
        fprintf(fichier, "Le Monsieur qui utilise le programme, il a 56a ans");

        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}