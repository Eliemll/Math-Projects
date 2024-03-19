#include "Point3D.h"
#include <iostream>
#include <cmath> 

int main () {
    while (true)
    {
        Point3D p1;

        // Entrée du point
        std::cout << "Rentrez les coordonnées de votre point3D ('stop' pour arrêter)" << std::endl;
        p1.input();

        // Affichage du point
        p1.affichePoint();

        // Conversion en polaire
        double r1, a1;
        p1.CartToCyl(r1, a1);

        // Conversion en sphérique
        double r2, a2, p2;
        p1.CartToSphèrique(r2, a2, p2);

        if (p1.getX() == 'stop')
            break;
    }
}