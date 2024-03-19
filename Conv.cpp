#include "Conv.h"
#include <iostream>
#include <cmath>

// Définition de la constante pi (partagée par toutes les instances)
const double pi = 3.14159265358979323846;

// Constructeurs
PointCar::PointCar()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

void PointCar::input()
{
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "y = ";
    std::cin >> y;

    std::cout << "z = ";
    std::cin >> z;
}

void PointCar::display()
{
    std::cout << "Point (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void PointCar::CarToCyl(double l, double a)
{
    l = sqrt(x * x + y * y);
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

    std::cout << "Point (" << l << ", " << a << ", " << z << ")" << std::endl;
}

void PointCar::CarToSphe(double r, double a, double p)
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

PointCyl::PointCyl(){
    l = 0.0;
    a = 0.0;
    z = 0.0;
}

void PointCyl::input() {
    std::cout << "l = ";
    std::cin >> l;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "z = ";
    std::cin >> z;
}

void PointCyl::display()
{
    std::cout << "PointCyl (" << l << ", " << a << ", " << z << ")" << std::endl;
}

void PointCyl::CylToCar(double x, double y, double z)
{
    a = a * pi / 180.0;

    x = l * cos(a);
    y = l * sin(a);

    std::cout << "PointCar (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void PointCyl::CylToSphe(double r, double a, double p)
{
    r = sqrt(l * l + z * z);
    p = acos(z / r);

    std::cout << "PointSphe (" << r << ", " << a << ", " << p << ")" << std::endl;
}

PointSphe::PointSphe () {
    r = 0.0;
    a = 0.0;
    p = 0.0;
}

void PointSphe::input() {
    std::cout << "r = ";
    std::cin >> r;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "p = ";
    std::cin >> p;
}

void PointSphe::display() {
    std::cout << "PointSphe (" << r << ", " << a << ", " << p << ")" << std::endl;
}

void PointSphe::SpheToCar(double x, double y, double z) {
    x = r * sin(p) * cos(a);
    y = r * sin(p) * sin(a);
    z = r * cos(p);

    std::cout <<"PointCar (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void PointSphe::SpheToCyl(double l, double z) {
    l = r * sin(p);
    z = r * cos(p);

    std::cout << "PointCyl (" << l << ", " << a << ", " << z << ")" << std::endl;
}

