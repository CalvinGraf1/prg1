/*
Calvin Graf
02.11.2022
HEIG-VD | PRG | Labo 14
Permet de vérifier à l'aide d'une fonction qu'un nombre est un entier premier
*/

#include <iostream>
#include <random>
#include <functional>

using namespace std;

long long int ExponentiationModulaire(long long int b, long long  int e, long long  int m);
bool Primalite(long long int p);
bool NombrePremier(long long int n);

int main()
{
  long long int nombre = 360000001200000001;
  cout << "Fonction personnel : " << NombrePremier(nombre) << endl;
  cout << "Fonction de primalité : " << Primalite(nombre) << endl;

}

// Permet de vérifier si un nombre est premier ou non
bool NombrePremier(long long int n)
{
  for (int i = 2; i <= n/2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Permet de vérifier si un nombre est premier ou non
bool Primalite(long long int p)
{
  // Si 2 -> return true
  // Si le dernier bit = 0 --> return false


  auto gen_int1_3 = bind(uniform_int_distribution<long long int>(1,p - 1), mt19937(382));
  long long int a = 0;
  // Aucun nombre premier n'est inférieur à deux
  if (p < 2)
    return false;
  else if (p == 2) // 2 est un nombre premier
    return true;
  for (int i = 0; i < 10; i++)
  {
    a = gen_int1_3();
    if (ExponentiationModulaire(a, p - 1, p) != 1)
       return false;

    long long int q = 1;
    long long int u = p - 1;
    while (u % 2 == 0 && q == 1)
    {
      u = u / 2;
      q = ExponentiationModulaire(a, u, p);
      if (q != 1 && q != p - 1)
        return false;
    }
  }
  return true;
}

long long int ExponentiationModulaire(long long int b, long long int e, long long int m)
{
  long long int r = 1;
  while (e > 0) {
    if (e % 2 == 0)
    {
      b = b * b % m;
      e = e / 2;
    }
    else
    {
      r = r * b % m;
      e--;
    }
  }
  return r;
}

/*
long long Puissance(long long n, int p)
{
  long long nDeBase = n;
  for (int i = 1; i < p; i++) {
    n = nDeBase * n;
  }
  return n;
}
*/ // Ne pas prendre en compte
