// Fichier point.hpp
#ifndef POINT // Protection contre les inclusions multiples
#define POINT
class Point {
public:
// Constructeur implanté en ligne
Point(int abscisse, int ordonnee): x(abscisse), y(ordonnee) {}
// Fonctions membres
void deplace(int dx, int dy); // Déplacement d'un point
void affiche();
 private:
int x; // abscisse
int y; // ordonnée
};
#endif
