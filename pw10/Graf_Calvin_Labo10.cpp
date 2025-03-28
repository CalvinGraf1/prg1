/*
Calvin Graf
HEIG-VD | PRG | Labo 10
Calculer la racine carré d'un nombre avec 10 chiffres significatifs
*/

#include <iostream>

using namespace std;

const double VERIFICATION = 0.000000001 ; // On utilise 10 nombres qui correspondent aux 10 nombres significatifs

int main() {

double x = 0;
double r = 0;
bool nombrePositif = false;
int iteration = 0;

// On vérifie que le nombre n'est pas négatif
while (!nombrePositif)
{
  cout << "Merci d'entrer un nombre positif pour calculer sa racine carre : ";
  cin >> x;
  if (x < 0){
    cout << "Votre nombre est negatif. Merci de recommencer" << endl; }
  else
  { nombrePositif = true; }
}

r = x / 2;
while(r * r > x + VERIFICATION || r * r < x - VERIFICATION) // On vérifie qu'il y a bien 10 chiffres significatifs semblables
{
   r = (r + x / r) / 2;
   iteration++;
}

cout << "La racine carre de " << x << " est : " << r << endl;
cout << "Le programme a realise " << iteration << " iterations.";

}
