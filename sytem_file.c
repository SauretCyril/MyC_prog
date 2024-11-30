#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Element
{
    int nombre;
    struct Element *suivant;
} Element;

typedef struct File
{
    Element *premier;
} File;

void enfiler(File *files, int nvNombre);
int defiler(File *files);
void afficherListe(File *files);
File *initialiser();

void enfiler(File *files, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (files == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (files->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = files->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        files->premier = nouveau;
    }
}

int defiler(File *files)
{
    if (files == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (files->premier != NULL)
    {
        Element *elementDefile = files->premier;

        nombreDefile = elementDefile->nombre;
        files->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}

void afficherListe(File *files)
{
    if (files == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = files->premier;
    printf("Etat de la pile \n");
    while (actuel != NULL)
    {
        printf("%d ", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}

File *initialiser()
{
    File *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}
int main()
{
    File *maListe = initialiser();

    enfiler(maListe, 4);
    enfiler(maListe, 8);
    enfiler(maListe, 15);
    enfiler(maListe, 16);
    enfiler(maListe, 23);
    enfiler(maListe, 42);
    afficherListe(maListe);

    printf("je defile %d\n", defiler(maListe));
    printf("je defile %d\n", defiler(maListe));

    afficherListe(maListe);

    return 0;
}
