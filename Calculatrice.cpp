#include <iostream>
#include <vector>

class RobotMobile
{
private:
    int positionX;
    int positionY;

public:
    RobotMobile() : positionX(0), positionY(0) {}

    // Méthode pour afficher la position du robot
    void afficherPosition() const
    {
        std::cout << "Position actuelle du robot : (" << positionX << ", " << positionY << ")" << std::endl;
    }

    // Méthode pour déplacer le robot vers une nouvelle position
    void deplacer(int nouvellePositionX, int nouvellePositionY)
    {
        positionX = nouvellePositionX;
        positionY = nouvellePositionY;
        std::cout << "Le robot s'est déplacé vers la nouvelle position." << std::endl;
    }

    // Méthode pour éviter les obstacles (simulé ici)
    void eviterObstacles()
    {
        std::cout << "Le robot évite les obstacles." << std::endl;
    }
};

class Environnement
{
private:
    std::vector<std::vector<int> > grille;

public:
    Environnement(int tailleX, int tailleY) : grille(tailleX, std::vector<int>(tailleY, 0)) {}

    // Méthode pour placer des obstacles dans l'environnement
    void placerObstacle(int positionX, int positionY)
    {
        grille[positionX][positionY] = 1;
    }

    // Méthode pour vérifier la présence d'obstacles
    bool verifierObstacle(int positionX, int positionY) const
    {
        return grille[positionX][positionY] == 1;
    }
};

int main()
{
    // Créer un environnement de taille 5x5
    Environnement environnement(5, 5);

    // Placer des obstacles dans l'environnement
    environnement.placerObstacle(2, 3);
    environnement.placerObstacle(4, 1);

    // Créer un robot mobile
    RobotMobile robot;

    // Déplacer le robot et afficher sa position
    robot.deplacer(2, 2);
    robot.afficherPosition();

    // Vérifier s'il y a des obstacles avant de déplacer le robot
    if (environnement.verifierObstacle(3, 2))
    {
        robot.eviterObstacles();
    }
    else
    {
        robot.deplacer(3, 2);
        robot.afficherPosition();
    }

    return 0;
}
