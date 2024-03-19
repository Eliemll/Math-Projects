#include <iostream>
#include <cmath> 
using namespace std;

double x, y, r, a, o;
double pi = M_PI;

void cartpol(double &, double &, double, double);
void convraddeg(double &, double);

int main()
{
    while (true)
    {
        cout << endl <<"Cette fonction transforme vos coordonées cartésiennes en polaires (Stop pour arrêter)" << endl;
        cout << "---------------" << endl;
        cout << "x: ";
        cin >> x;

        if (x == 'Stop')
        {
            cout << "Arrêt du programme." << endl;
            break;
        }

        cout << "y: ";
        cin >> y;
        cartpol(r, a, x, y, pi);
        convraddeg(o, a);

        cout << endl
             << "Coordonnées polaires" << endl
             << "---------------" << endl;
        cout << "r = " << r << endl
             << "o = " << o << endl;
    }
    return 0;
}

void cartpol(double &r, double &a, double x, double y)
{
    r = sqrt(x * x + y * y);

    if (x > 0)
    {
        if (y > 0)
        {
            a = atan2(y, x);
        }
        else if (y < 0) // Utiliser "else if" pour éviter les conflits
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
}
void convraddeg(double &, double)
{
    o = a * 180.0 / pi;
    if (o < 0)
    {
        o += 360;
    }
}