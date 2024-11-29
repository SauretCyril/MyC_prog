#include "main.h"

#define MAX 100
#define MIN 1

int main(int argc, char **argv)
{
    // L'ordinateur tire au sort un nombre entre 1 et 100.
    // L'utilisateur doit trouver ce nombre.
    // A chaque fois que l'utilisateur propose un nombre, l'ordinateur lui dit si le nombre à trouver est plus grand ou plus petit.
    srand(time(NULL));
    int rnd = rand() % 100 + 1;
    int i = 0;
    int nb;

    while (i <= 100)
    {
        // demander un chiffre entre 1 et 100
        printf("Entrez un nombre entre 1 et 100 : ");
        scanf("%d", &nb); /* code */
        // il vous indique si le nombre mystère est supérieur ou inférieur.
        if (nb < rnd)
        {
            printf("Le nombre mystère est plus grand\n");
        }
        else if (nb > rnd)
        {
            printf("Le nombre mystère est plus petit\n");
        }
        else
        {
            printf("Bravo, vous avez trouvé le nombre mystère !!!\n");
            break;
        }
    }
}
