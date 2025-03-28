/*
Calvin Graf
HEIG-VD | PRG | Labo 12

*/

#include <iostream>
#include <cmath>
using namespace std;

const int LETTRE_ASCII = 'A';

int main()
{
  int taille = 0;
  cout << "Combien de carre voulez-vous afficher : ";
  cin >> taille;

  char lettreLigne = (LETTRE_ASCII + taille - 1);
  char lettreDepart = lettreLigne;
  char lettreAfficher = lettreLigne;
  bool augmentation = false;

for (int ligne = 0; ligne < taille * 2 - 1; ligne++) {
  lettreAfficher = lettreDepart;
  augmentation = false;
  for (int colonne = 0; colonne < taille * 2 - 1; colonne++) {
    if (ligne < taille) {

      if (colonne == taille * 2 - 1 - ligne) {
        augmentation = true;
      }
      else if (lettreLigne == lettreAfficher) {
        cout << (char)(lettreAfficher);
      }
      else if (augmentation == false)
      { cout << (char)(lettreLigne + ligne - colonne);
        lettreAfficher--;
      }
      if (augmentation) {
        lettreAfficher++;
        cout << (char)(lettreAfficher);
      }
    }

    else {
      if (colonne == taille * 2 - 1 - (taille * 2 - 1 - ligne)) {
        augmentation = true;
      }
      else if (lettreLigne == lettreAfficher) {
        cout << (char)(lettreAfficher);
      }
      else if (augmentation == false)
      { cout << (char)(lettreLigne - 1 + taille * 2 - 1 - ligne - colonne);
        lettreAfficher--;
      }
      if (augmentation) {
        lettreAfficher++;
        cout << (char)(lettreAfficher);
      }

    }
  }
  if (ligne >= 3) {
    lettreLigne++;
  }
  else
  { lettreLigne--; }
  cout << endl;
}

/*
for (int ligne = 0; ligne < taille * 2 - 1; ligne++) {
  for (int colonne = 0; colonne < taille * 2 - 1; colonne++)
  {
    if (colonne == lettreDepart - lettre - ligne) {
      cout << (char)(lettreDepart - colonne);
      //cout << "Test 1";
    }
    if (colonne == lettre - LETTRE_ASCII + ligne + taille * 2 - 1) {
      cout << (char)(LETTRE_ASCII + taille - 1);
      cout << "Test 2";
    }
    cout << (char)(lettre);
  }
  cout << endl;
  lettre--;
}



      for (int ligne = taille * 2 - 1; ligne > 0; ligne--) {
        for (int colonne = taille * 2 - 1; colonne > 0; colonne--) {

            char lettre = (LETTRE_ASCII + (ligne / 2 + 1));

            if (colonne == taille - 1 || colonne == taille + 1) {
              lettre += 1;
            }

            cout << lettre;

        }
        cout << endl;
      }
      */
  }
