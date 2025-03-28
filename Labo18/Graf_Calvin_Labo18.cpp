/*
Calvin Graf
18.11.2022
HEIG-VD | PRG | Labo 18

*/

#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> recupererMot(string & fichier);
vector<int> iterationMot(vector<string> & v);

int main()
{
  string fichier = "la_comedie_humaine.txt";

  vector<string> mots = recupererMot(fichier);
  vector<int> iteration = iterationMot(mots);
  int iterationMax = 0;
  string motMax = "";

  for (size_t i = 0; i < mots.size(); i++) {
    if (iteration[i] > iterationMax) {
      iterationMax = iteration[i];
      motMax = mots[i];
    }
  }
  cout << "Le mot le plus cite dans " << fichier << " est \"" << motMax << "\" qui est cite " << iterationMax << " fois." << endl;

}

vector<string> recupererMot(string & fichier)
{
  vector<string> listeMot;
  ifstream file;
  file.open(fichier);
  string motSeparer;
  string motMinuscule;
  while (file >> motSeparer) {
    motSeparer.erase(remove_if (motSeparer.begin(), motSeparer.end(), ::ispunct), motSeparer.end());
    /*
    for (size_t i = 0; i < motSeparer.length(); i++) {
      motMinuscule += tolower(motSeparer[i]);
    }
    listeMot.push_back(motMinuscule);
    */
    listeMot.push_back(motSeparer); // Si on ne différencie pas maj / min, enlevez cette ligne et remettre le code en commentaire
    motMinuscule.clear();
  }
  file.close();
  sort(listeMot.begin(), listeMot.end());
  return listeMot;
}

vector<int> iterationMot(vector<string> & v)
{
  vector<int> iteration;

  for (size_t i = 0; i <= v.size(); i++) {
    if(v[i] == v[i - 1])
      iteration.back()++;
    else
      iteration.push_back(1);
  }
  vector<string> v_modif;
  for (size_t i = 0; i <= v.size(); i++) {
    if(v[i] != v[i - 1])
      v_modif.push_back(v[i]);
  }
  v = v_modif;
  return iteration;
}
