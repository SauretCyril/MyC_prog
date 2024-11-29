#include <stdio.h>
#include <stdlib.h>
// Prototype de la fonction d'affichage
void affiche(int *tableau, int tailleTableau);
void ajouteElement(int **tableau, int *tailleTableau, int nouvelElement);

int main(int argc, char *argv[])
{
    int *tableau = malloc(4 * sizeof(int));
    tableau[0] = 10;
    tableau[1] = 15;
    tableau[2] = 3;
    tableau[3] = 0;
    int tailleTableau = 4;

    // On ajoute un nouvel élément au tableau
    ajouteElement(&tableau, &tailleTableau, 25);

    // On affiche le contenu du tableau
    affiche(tableau, tailleTableau);

    free(tableau);
    return 0;
}

void affiche(int tableau[], int tailleTableau)
{
    int i;

    for (i = 0; i < tailleTableau; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

void ajouteElement(int **tableau, int *tailleTableau, int nouvelElement)
{
    *tableau = realloc(*tableau, (*tailleTableau + 1) * sizeof(int));
    if (*tableau == NULL)
    {
        fprintf(stderr, "Erreur de réallocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    (*tableau)[*tailleTableau] = nouvelElement;
    (*tailleTableau)++;
}

/*
 * Explication de int **tableau :
 *
 * int **tableau est un pointeur vers un pointeur d'entier. Cela permet à la fonction ajouteElement
 * de modifier le pointeur original du tableau (c'est-à-dire de réallouer la mémoire pour le tableau
 * et de mettre à jour le pointeur vers le nouvel emplacement mémoire).
 *
 * Voici une explication détaillée :
 *
 * 1. Pointeur vers Pointeur : int **tableau permet à la fonction de modifier le pointeur original du tableau.
 *    Si nous utilisions int *tableau, la fonction ne modifierait qu'une copie locale du pointeur, et les
 *    modifications ne seraient pas reflétées en dehors de la fonction.
 *
 * 2. Allocation Dynamique de Mémoire : Lors de la réallocation de mémoire avec realloc, l'adresse mémoire
 *    du tableau peut changer. En utilisant int **tableau, la fonction peut mettre à jour le pointeur original
 *    pour qu'il pointe vers le nouvel emplacement mémoire.
 *
 * 3. Appel de Fonction : Lors de l'appel de ajouteElement, nous passons l'adresse du pointeur du tableau (&tableau).
 *    Cela permet à la fonction de déréférencer le pointeur vers pointeur (*tableau) et de modifier le pointeur
 *    original du tableau.
 *
 * En résumé, int **tableau est utilisé pour s'assurer que la fonction peut modifier le pointeur original du tableau
 * et gérer correctement l'allocation dynamique de mémoire.
 */