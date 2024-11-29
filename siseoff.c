#include <stdio.h>
#include <stdlib.h>
typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    printf("Coordonnees : %d octets\n", sizeof(Coordonnees));

    int *memoireAllouee = NULL;           // On crée un pointeur sur int
    memoireAllouee = malloc(sizeof(int)); // La fonction malloc inscrit dans notre pointeur l'adresse qui a été reservée.
    if (memoireAllouee == NULL)           // Si l'allocation a échoué
    {
        exit(0); // On arrête immédiatement le programme
    }

    free(memoireAllouee); // On n'a plus besoin de la mémoire, on la libère
    return 0;
}