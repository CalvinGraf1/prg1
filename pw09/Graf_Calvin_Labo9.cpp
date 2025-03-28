/*
Calvin Graf
HEIG-VD | PRG | Labo 9
Calculer la moyenne et la variance des nombres positifs entrés par l'utilisateur
*/

#include <iostream>

using namespace std;

int main() {

  cout << "Veuillez entrer vos valeurs une par une. Pour quittez, merci d'entrer une valeur negatif.\n";

  double valeur = 0;
  double moyenne = 0;
  double variance = 0;
  double somme = 0;
  double sommeCarre = 0;

  int nombre = 0;

  // On récupère les valeurs de l'utilisateur
  while(valeur >= 0)
  {
    somme += valeur;
    sommeCarre += valeur*valeur;
    cout << "Valeur " << nombre + 1 << " : ";
    cin >> valeur;
    nombre++;
  }
  nombre--; // On retire le nombre négatif
  variance = (sommeCarre - (((double)1/nombre) * (somme * somme))) / 3; // Calcul de la variance
  moyenne = somme / nombre; // Calcul de la moyenne

  cout << "La moyenne de vos nombres est : " << moyenne << ".\n" << "La variance de vos nombres est : " << variance;
}
