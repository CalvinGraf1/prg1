/*
Calvin Graf
HEIG-VD | PRG | Labo 9
Calculer la moyenne et la variance des nombres positifs entrés par l'utilisateur
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

  cout << "Veuillez entrer vos valeurs une par une. Pour quittez, merci d'entrer une valeur negatif.\n";

  double dblValeur = 0;
  double dblMoyenne = 0;
  double dblVariance = 0;

  vector<double> vValeurs;

  // On récupère chaque valeur 1 par 1
  while(dblValeur >= 0)
  {
    dblMoyenne += dblValeur;
    cout << "Valeur " << (double)vValeurs.size() + 1 << " : ";
    cin >> dblValeur;
    vValeurs.push_back(dblValeur);
  }
  vValeurs.pop_back(); // On retire la dernière valeur qui est négative
  dblMoyenne = dblMoyenne / (double)vValeurs.size(); // On calcul la moyenne

  // On calcul la variance
  for (int i = 0; i < (double)vValeurs.size(); i++)
  { dblVariance += pow(vValeurs[(unsigned)i] - dblMoyenne, 2); }
  dblVariance = dblVariance / ((double)vValeurs.size() - 1);

  cout << "La moyenne de vos nombres est : " << dblMoyenne << ".\n" << "La variance de vos nombres est : " << dblVariance;
}
