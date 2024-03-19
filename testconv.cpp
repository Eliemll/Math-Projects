#include "Conv.h"
#include <iostream>

int main()
{
    int choix1, choix2;

    while (true)
    {
        // Saisie du choix de coordonnées
        std::cout << "Choisissez votre système de coordonées: 1-Cartésien  2-Cylindrique  3-Sphérique ";
        std::cin >> choix1;

        // Choix cartésien
        if (choix1 == 1)
        {
            PointCar p1;
            // Saisie du point
            p1.input();

            // Affichage du point
            p1.display();

            // Saisie du choix de conversion
            std::cout << "Choisissez votre système de coordonées de conversion: 1-Cylindrique  2-Sphérique  3-Les deux ";
            std::cin >> choix2;

            // Choix cylindrique
            if (choix2 == 1)
            {
                p1.CarToCyl();
            }
            else if (choix2 == 2)
            {
                p1.CarToSphe();
            }
            else if (choix2 == 3)
            {
                p1.CarToCyl();
                p1.CarToSphe();
            }
        }
        else if (choix1 == 2)
        {
            PointCyl p1;
            // Saisie du point
            p1.input();

            // Affichage du point
            p1.display();

            // Saisie du choix de conversion
            std::cout << "Choisissez votre système de coordonées de conversion: 1-Cartésien  2-Sphérique  3-Les deux ";
            std::cin >> choix2;

            if (choix2 == 1)
            {
                p1.CylToCar();
            }
            else if (choix2 == 2)
            {
                p1.CylToSphe();
            }
            else if (choix2 == 3)
            {
                p1.CylToCar();
                p1.CylToSphe();
            }
        }
        else if (choix1 == 3)
        {
            PointSphe p1;

            // Saisie du point
            p1.input();

            // Affichage du point
            p1.display();

            // Saisie du choix de conversion
            std::cout << "Choisissez votre système de coordonées de conversion: 1-Cartésien  2-Cylindrique  3-Les deux ";
            std::cin >> choix2;

            if (choix2 == 1)
            {
                p1.SpheToCar();
            }
            else if (choix2 == 2)
            {
                p1.SpheToCyl();
            }
            else if (choix2 == 3)
            {
                p1.SpheToCar();
                p1.SpheToCyl();
            }
        }
    }

    return 0;
}
