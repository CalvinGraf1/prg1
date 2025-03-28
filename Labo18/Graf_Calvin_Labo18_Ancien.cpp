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

using namespace std;

class Mot {
  string m;
  size_t n;
  public:
    Mot(string mot, size_t nombre);

    // GETTER
    string getMot();

    void ajouterIteration(size_t nombre);
};

vector<Mot> recupererMot(string & fichier);

int main()
{
  string fichier = "calvin.txt";
  vector <Mot> vMot = recupererMot(fichier);
  for(Mot m : vMot)
  {
    cout << m.getMot() << endl;
  }
}

Mot::Mot(string mot, size_t nombre)
{
  m = mot;
  n = nombre;
}

void Mot::ajouterIteration(size_t nombre)
{ n++; }

string Mot::getMot() {
  return m;
}

vector<Mot> recupererMot(string & fichier)
{
  vector<Mot> listeMot;
  ifstream file;
  file.open(fichier);
  string motSeparer;
  while (file >> motSeparer) {
    motSeparer.erase(remove_if (motSeparer.begin(), motSeparer.end(), ::ispunct), motSeparer.end());
    Mot m1(motSeparer, 1);
    //cout << find(listeMot.begin(), listeMot.end(), m1);
    //if(find(listeMot.begin(), listeMot.end(), m1) != listeMot.end()) cout << "Coucou";
    listeMot.push_back(m1);
  }
  file.close();
  return listeMot;
}
