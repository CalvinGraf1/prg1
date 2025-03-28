/*
Calvin Graf
21.10.2022
HEIG-VD | PRG | Labo 13
1. Affiche la suite de Syracuse pour la valeur entrée en paramètre
2. Affiche le nombre de valeurs des n premiers nombres cumulées.
   n étant donné par l'utilisateur.
*/

#include <iostream>

using namespace std;

void SuiteSyracuse(int nombre);
void NombreSuiteSyracuse(int nombre);

int main()
{
  int nombre = 0;
  cout << "Merci d'entrer le nombre de premier entier desire : ";
  cin >> nombre;
  NombreSuiteSyracuse(nombre);

  //SuiteSyracuse(nombre);
}

// Ex 4.16b
void NombreSuiteSyracuse(int nombreEntier)
{
int nombreValeur = 0;
int nombre = 0;

for (int i = 1; i <= nombreEntier; i++) {
  nombre = i;
  while (nombre != 1)
  {
  if (nombre % 2 == 0)
    nombre = nombre / 2;
  else
    nombre = nombre * 3 + 1;
  nombreValeur++;
  }
  nombreValeur++;
}
  cout << "\nVoici le nombre de valeur(s) lorsque l'on additionne les " << nombre << " premier(s) entier(s) : " << nombreValeur;
}



// Ex 4.16a
void SuiteSyracuse(int nombre)
{
  cout << "Nombre : " << nombre << "\n";

int nMoins1 = 0;
int nMoins2 = 0;

  while (nombre != 1 && nombre != 0)
  {
    nMoins2 = nMoins1;
    nMoins1 = nombre;
  if (nombre % 2 == 0)
    nombre = nombre / 2;
  else
    nombre = nombre * 3 + 1;


  cout << nombre << " ";
  }
  cout << "\nLe(s) nombre(s) qui se repetent sont : ";
  if (nMoins2 != 0)
  {
    cout << nMoins2 << " ";
  }
  if (nMoins2 != 0)
  {
    cout << nMoins1 << " ";
  }
   cout << nombre;
}
