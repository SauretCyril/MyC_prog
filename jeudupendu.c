#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Ajoutez cette ligne
// #include <ctype.h>

// prototypes des fonctions
int tailleMot(char motSecret[]);
void initTableau(int *lettreTrouvee, int taille);
int gagne(int *lettreTrouvee, int nombreLettres);
char lireCaractere();
int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee);

int main(int argc, char *argv[])
{
    char lettre = 0;            // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10;     // Compteur de coups restants (0 = mort)
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL;
    lettreTrouvee = malloc(nombreLettres * sizeof(int));

    if (lettreTrouvee == NULL)
    {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return 1;
    }

    initTableau(lettreTrouvee, nombreLettres);

    printf("Bienvenue dans le jeu du pendu !\n\n");
    printf("Le mot à deviner contient %d lettres.\n", nombreLettres);

    // Afficher le tableau pour vérifier l'initialisation
    for (int i = 0; i < nombreLettres; i++)
    {
        printf("%d ", lettreTrouvee[i]);
    }
    printf("\n");
    while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
    {
        /* il faut demander une lettre et vérifier si cette lettre est présente dans le mot à deviner. */
        printf("\n\nIl vous reste %d coups a jouer\n", coupsRestants);
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        // convertir la lettre en majuscule
        // lettre = toupper(lettre);
        printf("Vous avez proposé la lettre : %c\n", lettre);
        /*  for (int i = 0; i < nombreLettres; i++)
         {
             if (motSecret[i] == lettre)
             {
                 lettreTrouvee[i] = 1;
             }
         } */
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            printf("Cette lettre n'est pas dans le mot.\n");
            coupsRestants--;
        }

        // Afficher le tableau pour vérifier l'initialisation
        for (int i = 0; i < nombreLettres; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }
    }
    // Afficher le mot secret
    if (gagne(lettreTrouvee, nombreLettres))
    {
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    }
    else
    {
        printf("\n\nPENDU !!! Vous avez perdu ! Le mot secret était : %s\n\n", motSecret);
    }
    // Libérer la mémoire allouée
    free(lettreTrouvee);

    return 0;
}

int tailleMot(char motSecret[])
{
    int nombreLettres = 0;
    for (int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettres++;
    }
    return nombreLettres;
}

void initTableau(int *lettreTrouvee, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        lettreTrouvee[i] = 0;
    }
}

int gagne(int *lettreTrouvee, int nombreLettres)
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0; i < nombreLettres; i++)
    {
        if (lettreTrouvee[i] == 0)
        {
            joueurGagne = 0;
            break;
        }
    }

    return joueurGagne;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();          // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n')
        ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee)
{
    int i = 0, bonneLettre = 0;
    for (i = 0; motSecret[i] != '\0'; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}