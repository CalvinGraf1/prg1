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
  const string f = "de";
  const string t = "Heeey";
  string str = "Au milieu de la rue Saint-Denis, presque au coin de la rue du Petit-Lion, existait naguère une de ces maisons précieuses qui donnent aux historiens la facilité de reconstruire par analogie l’ancien Paris. Les murs menaçants de cette bicoque semblaient avoir été bariolés.";

  cout << replace_all(str, f, t);
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
}

string & replace_all(string & str, const string & from, const string & to)
{
  if(str.empty() or from.empty()) // Traiter les cas limites
    return str;


  size_t nb = 0; // Nombre d'occurrences à remplacer
  for (size_t i = 0; (i = str.find(from, i)) < string::npos; i += from.size())
  {
    nb++;
  }

  if (nb == 0)
    return str;

  if (from.size() < to.size()){
    size_t deb = nb * (to.size()-from.size());
    str = string(deb, 'X') + str;
    size_t fin = str.find(from, deb);
    size_t i = 0;
    do {
      for (; deb < fin; deb++)
        str.at(i++) = str.at(deb);
      str.replace(i, to.size(), to);
      i += to.size();
      deb += from.size();
      fin = str.find(from, deb);
   }
   while (fin < str.size());
  }
  else {
    size_t fin = str.find(from, 0);
    size_t i = fin;
    do {
      str.replace(i, to.size(), to);
      i += to.size();
      size_t deb = fin + from.size();
      fin = str.find(from, deb);
      for (; deb < fin && deb < str.size(); deb++)
        str.at(i++) = str.at(deb);
    }
    while (fin < str.size());
    str.resize(i);
  }
  return str;
}
