/*
Calvin Graf
11.11.2022
HEIG-VD | PRG | Labo 15

*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string & replace_all(string & str, const string & from, const string & to);

// Replace 1
string replace(const int carDepart, const int NbCar, const string str, const string strRemplacement)
{
  string nouveauStr = str.substr(0, carDepart);
  nouveauStr += strRemplacement;
  nouveauStr += str.substr(carDepart + strRemplacement.size());

  return nouveauStr;
}

// Replace 2
string replace(const int carDepart, const int NbCar, const string str, const string strRemplacement,
               const int carDepartSousChaine, const int NbCarSousChaine)
{
  string strRemplSub = strRemplacement.substr(carDepartSousChaine, NbCarSousChaine);
  string nouveauStr = str.substr(0, carDepart);
  nouveauStr += strRemplSub;
  nouveauStr += str.substr(carDepart + strRemplacement.size());

  return nouveauStr;
}

// Replace 3
string replace(const int carDepart, const int NbCar, const string str, const string strRemplacement,
               const int NbCarSousChaine)
{
  string strRemplSub = strRemplacement.substr(0, NbCarSousChaine);

  string nouveauStr = str.substr(0, carDepart);
  nouveauStr += strRemplSub;
  nouveauStr += str.substr(carDepart + strRemplacement.size());

  return nouveauStr;
}

// Replace 4
string replace(const int carDepart, const int NbCar, const string str, const int NbLettre, char lettre)
{
  string nouveauStr = str.substr(0, carDepart);
  for (size_t i = 0; i < NbLettre; i++) {
    nouveauStr += lettre;
  }
  nouveauStr += str.substr(carDepart + NbLettre);

  return nouveauStr;
}

size_t find(string s, const string & str, size_t pos = 0, size_t taille = -1)
{
  // Si les chaînes sont vide ou que le texte recherchée est plus grand que le texte initial, la fonction s'arrête
  if (str.empty() || s.empty() || str.size() < s.size())
  { return string::npos; }

  // On récupère la sous-chaîne si l'utilisateur n'a pas mis de taille ou un taille négative.
  if (taille <= 0)
    taille = s.length();
  s = s.substr(pos, taille);

  // Recherche des caractères désirée et retourne le résultat
  for (size_t i = pos; i < str.size() - s.size(); i++) {
    size_t j = 0;
    while(j < s.size() && str[i+j] == s[j])
    { j++; }
    if (j == s.size()) {
      return i;
    }
  }
  return string::npos;
}

int main()
{
  const string f = "test";
  const string t = "reussite";
  string str = "calvin.txt";

// Test de find
//  cout << find("tut", "pourquoi tu parles ?", 0, 2);

// Test de replace
/*
  int cDepart = 3;
  int NbCar = 4;
  string strChaine = "Bonjour je suis Calvin";
  string strRemp = "soir";
  int cDepartSousChaine = 2;
  int NbCarSousChaine = 2;
  int NbLettre = 4;
  char lettre = 'b';

  cout << replace(cDepart, NbCar, strChaine, strRemp); // Replace 1
  cout << replace(cDepart, NbCar, strChaine, strRemp, cDepartSousChaine, NbCarSousChaine); // Replace 2
  cout << replace(cDepart, NbCar, strChaine, strRemp, NbCarSousChaine); // Replace 3
  cout << replace(cDepart, NbCar, strChaine, NbLettre, lettre); // Replace 4
*/

// Entrée utilisateur
/*
  cout << "Entrer le nom de votre fichier : ";
  cin >> str;

  cout << "Le mot que vous voulez remplacer : ";
  cin >> f;

  cout << "Remplacé par : ";
  cin >> t;
*/
  cout << replace_all(str, f, t);
}

string & replace_all(string & str, const string & from, const string & to)
{
  fstream file(str);
  string newStr = "";
  int pos = 0;

  getline(file, newStr, '\0');

  pos = find(from, str, 0);
  newStr.replace(pos, from.length(), to);

  cout << newStr;

  return str;
  /*
  int lettreCorrecte = 0;
  for (int j = 0; j != str.length(); ++j)
  {
      cout << replace << endl << "JIDSJKADSKL"<< endl;
    if (replace.at(j) == from.at(lettreCorrecte)) {
      lettreCorrecte++;
    }
  //  cout << lettreCorrecte << " = " << from.length() << endl;
    if (lettreCorrecte == from.length()) {
      for (int i = 0; i < lettreCorrecte; i++) {
        //cout << endl << replace << endl;
        replace.pop_back();
      }
    //  cout  << endl << endl << endl << replace << endl << endl <<endl << "SADASDAS";
      for (int i = 0; i < to.length(); i++) {
        replace += to.at(i);
      }
      lettreCorrecte = 0;
      j++;
    }
    replace += replace.at(j);
  }
  file << replace;
  cout << replace;
  file.close();
  //str = replace;
  str = "";
  return str;
  */

}

/*     cout << str[j] << " == " << from[0] << endl;
      for (int i = 0; str[j] == from[i]; i++) {
        cout << "Coucou";
        if (i == from.length()) {
          for (size_t i = 0; i != from.length(); i++) {
            str[j - from.length() + i] = from[i];
          }
        }
      }

      */
