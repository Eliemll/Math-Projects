#include <iostream>
#include <cstring>
using namespace std;

class Point
{
private:
    double abscisse, ordonnee;

public:
    // Constructeurs
    Point(double x, double y);

    // Getters
    double getAbscisse();
    double getOrdonnee();

    // Setters
    void setAbscisse(double x);
    void setOrdonnee(double y);

    void afficher();

    // Fonction amie
    friend double distance(Point &p1, Point &p2);
};

// Définition du constructeur
Point::Point(double x, double y) : abscisse(x), ordonnee(y) {}

double Point::getAbscisse()
{
    return this->abscisse;
}

double Point::getOrdonnee()
{
    return this->ordonnee;
}

void Point::setAbscisse(double x)
{
    this->abscisse = x;
}

void Point::setOrdonnee(double y)
{
    this->ordonnee = y;
}

void Point::afficher()
{
    cout << "x = " << this->abscisse << endl;
    cout << "y = " << this->ordonnee << endl;
}

double distance(Point &p1, Point &p2)
{
    return sqrt(((p1.abscisse - p2.abscisse) * (p1.abscisse - p2.abscisse) + (p1.ordonnee - p2.ordonnee) * (p1.ordonnee - p2.ordonnee)));
}

int main()
{
    Point p1(1, 5);
    Point p2(1, -5);

    p1.afficher();
    p2.afficher();

    double dist = distance(p1, p2);
    cout << "Distance entre les points : " << dist << endl;

    return 0;
}
