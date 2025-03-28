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

class Mot {
  string m;
  size_t cpt;
public:
  Mot(string mot) : m(mot) { cpt = 1; }
  void ajouterCpt() { cpt++; }
  string getMot() { return m; }
  size_t getCpt() { return cpt; }
};

vector<Mot> recupererMot(string & fichier);
vector<Mot> iterationMot(vector<Mot> & v);

int main()
{
  /*
  Mot m("Coucou");
  cout << m.getMot() << endl;
  cout << m.getCpt() << endl;
  m.ajouterCpt();
  cout << m.getCpt() << endl;
  Mot m2("Test");
  m.ajouterCpt();
  m2.ajouterCpt();
  cout << m.getCpt() << endl;
  cout << m2.getCpt() << endl;
  */
  string fichier = "la_comedie_humaine.txt";

  vector<Mot> mots = recupererMot(fichier);
  mots = iterationMot(mots);
  int iterationMax = 0;
  string motMax = "";

  for(auto e : mots)
  { cout << e.getMot() << " - " << e.getCpt() << " fois" << endl; }

  /*
  for (size_t i = 0; i < mots.size(); i++) {
    if (iteration[i] > iterationMax) {
      iterationMax = iteration[i];
      motMax = mots[i];
    }
  }

  cout << "Le mot le plus cite dans " << fichier << " est \"" << motMax << "\" qui est cite " << iterationMax << " fois." << endl;
  */
}

vector<Mot> recupererMot(string & fichier)
{
  vector<string> listeMot;
  vector<Mot> v_mots;
  ifstream file;
  file.open(fichier);
  string motSeparer;
  while (file >> motSeparer) {
    motSeparer.erase(remove_if (motSeparer.begin(), motSeparer.end(), ::ispunct), motSeparer.end());
    listeMot.push_back(motSeparer);
  }
  file.close();
  sort(listeMot.begin(), listeMot.end());

  for(auto e : listeMot)
    v_mots.push_back(Mot(e));

  return v_mots;
}

vector<Mot> iterationMot(vector<Mot> & v)
{
  vector<Mot> v_modif;
  string motAnterieur = "";
  size_t iteration = 1;

  for (size_t i = 0; i < v.size(); i++) {
    if(v[i].getMot() == motAnterieur) {
      v[i - iteration].ajouterCpt();
      iteration++;
    }
    else {
      motAnterieur = v[i].getMot();
      iteration = 1;
    }
  }
  cout << v.size() << endl;
  for (size_t i = 0; i < v.size(); i++) {
    cout << i << endl;
    if(v[i].getMot() != v[i - 1].getMot())
      v_modif.push_back(v[i]);
  }

    cout << v_modif.size() << " Le bug est ici" << endl;

  return v_modif;
}
