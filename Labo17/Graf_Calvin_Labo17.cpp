/*
Calvin Graf
18.11.2022
HEIG-VD | PRG | Labo 17

*/

#include <iostream>
#include <vector>

using namespace std;

const vector<string> chiffreFr {"Zero", "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf"};

string imprime(size_t n, size_t base = 10, size_t t = 0) {
  string resultat = "";

  if(base < 2) return "Erreur : base invalide";

  if (n > base)
   resultat += imprime(n/base, base);
  if(n%base >= 9)
    resultat += char(n%base + '7');
  else
    resultat += char(n%base + '0');

  if(t != 0)
  {
    vector<string> chiffre;
    for (size_t i = 0; i < resultat.size(); i++) {
      chiffre.push_back(to_string(resultat.at(i) - 48));
    }
    resultat.erase();

    if(t == 1)
    {
      for(auto & e : chiffre)
      {
        e.replace(0, chiffreFr.at(stoi(e)).size(), chiffreFr.at(stoi(e)));
        resultat += e + " ";
      }
    }
    else if(t == 2)
    {

    }
  }

  return resultat;
 }

int main()
{
  cout << imprime(30, 5, 1);

    /*
  size_t n, base, t;
  cout << "Introduire un nombre entier, une base et un numéro de table de correspondance : ";
  cin >> n >> base >> t;
  cout << "En base par défaut, avec la table par défaut : " << imprime(n) << endl;
  cout << "En base " << base << " avec les chiffres " << imprime(n, base) << endl;
  */
}
