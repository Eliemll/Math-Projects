#include <iostream>
#include "Point.h"

int main () {
    Point p1;
    Point p2;
    
    // Input p1
    p1.input();

    // Input p2
    p2.input();

    //Affichage des deux points
    p1.display();
    p2.display();

    //Fonction distance
    double distance = p1.distanceTo(p2);
    std::cout << "Distance entre les points : " << distance << std::endl;

    // Fonction conversion
    double r1, a1, r2, a2;
    p1.cartToPolar(r1, a1);
    p2.cartToPolar(r2, a2);

    std::cout << "Coordonnées polaires de p1 : r = " << r1 << ", a = " << a1 << std::endl;
    std::cout << "Coordonnées polaires de p2 : r = " << r2 << ", a = " << a2 << std::endl;

    return 0;
}