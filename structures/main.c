#include "main.h" // Inclusion du .h qui contient les prototypes et structures

int main(int argc, char *argv[])
{
    Coord point = {0, 12}; // Création d'une variable "point" de type Coordonnees
    Coord point1;
    initialiserCoordonnees(&point1);
    printf("Coordonnees du point : x=%d, y=%d\n", point.x, point.y);   // Affichage des coordonnées du point
    printf("Coordonnees du point : x=%d, y=%d\n", point1.x, point1.y); // Affichage des coordonnées du point
    return 0;
}

void initialiserCoordonnees(Coord *point)
{
    //(*point).x = 6;
    point->x = 125;
    //(*point).y = 10;
    point->y = 201;
    // Initialisation de chacun des membres de la structure ici
}