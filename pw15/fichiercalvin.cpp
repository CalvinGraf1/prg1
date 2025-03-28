/*
Calvin Graf
11.11.2022
HEIG-VD | PRG | Labo 15
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include<sstream>
#include<string>
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
string str;
string f;
string t;

  cout << "Entrer le nom de votre fichier : ";
  cin >> str;
  cout << "Le mot que vous voulez remplacer : ";
  cin >> f;
  cout << "Remplace par : ";
  cin >> t;

  cout << replace_all(str, f, t);
}
string & replace_all(string & str, const string & from, const string & to)
{
  string temp;
  string strNew = "";
  int i=0,cpos;
  fstream FichierTexte(str); // on fait un fstream qui permet de lire / écrire
  int pos = 0;

   fstream Verification(str);
   if(!Verification){
     cout << "Le fichier n'existe pas, le programme va donc s'eteindre";
     exit(-1);
   }

  getline(FichierTexte, temp, '\0');

  int lettreCorrecte = 0;

  for (int j = 0; j != temp.length(); ++j)
  {
    if (temp.at(j) == from.at(lettreCorrecte)) {
      lettreCorrecte++;
    }
    else
      lettreCorrecte = 0;

    if (lettreCorrecte == from.length()) {
      for (int i = 0; i < lettreCorrecte - 1; i++) {
        strNew.pop_back();
      }
      for (int i = 0; i < to.length(); i++) {
        strNew += to.at(i);
      }
      lettreCorrecte = 0;
      j++;
    }
    strNew += temp.at(j);
  }

  ofstream ecriture(str.c_str(), ios::binary);
      ecriture << strNew;
  FichierTexte.clear();
  FichierTexte.close();

  return str;
}
