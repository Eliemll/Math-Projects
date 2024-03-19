#include "Point3D.h"
#include <iostream>
#include <cmath>

// Définition de la constante pi (partagée par toutes les instances)
const double Point3D::pi = 3.14159265358979323846;

//Constructeurs
Point3D::Point3D() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

// Setters
void Point3D::setX (double newX) {
    x = newX;
}

void Point3D::setY(double newY)
{
    y = newY;
}

void Point3D::setZ(double newZ)
{
    z = newZ;
}

// Getters 
double Point3D::getX () {
    return x;
}

double Point3D::getY()
{
    return y;
}

double Point3D::getZ()
{
    return z;
}

void Point3D::input() {
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "y = ";
    std::cin >> y;

    std::cout << "z = ";
    std::cin >> z;
}

void Point3D::affichePoint() {
    std::cout << "Point (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void Point3D::CartToCyl(double &r, double &a) {
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

    std::cout << "Point (" << r << ", " << a << ", " << z << ")" << std::endl;
}

void Point3D::CartToSphèrique(double &r, double &a, double &p) 
{
    
    r = sqrt(x * x + y * y + z * z);
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

    if (r == 0.0)
    {
        p = 0;
    }
    else
    {
        p = acos(z / r);
    p = p * 180.0 / pi;
    }

    if (p < 0)
    {
        p += 360;
    }

    std::cout << "Point (" << r << ", " << a << ", " << p << ")" << std::endl;
}
