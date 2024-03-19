#include <iostream>
#include "Point.h"

// Définition de la constante pi (partagée par toutes les instances)
const double Point::pi = 3.14159265358979323846;

// Définition du constructeur par défaut
Point::Point()
{
    x = 0.0;
    y = 0.0;
}

// Définition du Getter / Accesseur pour x
double Point::getX() const
{
    return x;
}

// Définition du Getter / Accesseur pour y
double Point::getY() const
{
    return y;
}

// Définition du Setter x
void Point::setX(double newX)
{
    x = newX;
}

// Définition du Setter y
void Point::setY(double newY)
{
    y = newY;
}

// Afficheur
void Point::display() const
{
    std::cout << "Point (" << x << ", " << y << ")" << std::endl;
}

// Entreur des valeurs
void Point::input()
{
    std::cout << "Entrez votre coordonnées x: ";
    std::cin >> x;

    std::cout << "Entrez votre coordonnées y: ";
    std::cin >> y;
}

// Fonction distance
double Point::distanceTo(const Point &other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Fonction pour convertir les coordonnées cartésiennes en polaires
void Point::cartToPolar(double &r, double &a) const
{
    r = sqrt(x * x + y * y);
    if (x > 0)
    {
        if (y > 0)
        {
            a = atan2(y, x);
        }
        else if (y < 0)
        {
            a = atan2(y, x) + 2 * pi;
        }
        else
        {
            a = 0;
        }
    }
    else if (x == 0)
    {
        if (y > 0)
        {
            a = pi / 2;
        }
        else if (y < 0)
        {
            a = 3 * pi / 2;
        }
        else
        {
            a = 0;
        }
    }
    else
    {
        a = atan2(y, x);
    }

    a = a * 180.0 / pi;
    if (a < 0)
    {
        a += 360;
    }
}
