
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
typedef struct Coordonnees Coord;
struct Coordonnees
{
    int x; // Abscisses
    int y; // Ordonnées
};
void initialiserCoordonnees(Coord *point);
#endif