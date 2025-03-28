#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> class Rationnal;
template <typename T> ostream & operator<<(ostream & os, const Rationnal<T> & rhs);

template <typename T>
T PGDC(T lhs, T rhs)
{
  while(rhs != 0) {
    T temp = rhs;
    rhs = lhs % rhs;
    rhs = temp;
  }
  return lhs;
}

template <typename T>
class Rationnal
{
  T num;
  T den;
  bool neg;
public:
  Rationnal(T numerateur, T denominateur, bool negatif = 0);

  // Opération arithmétique
  Rationnal operator+(const Rationnal<T> & rhs);
  Rationnal operator-(const Rationnal<T> & rhs);
  Rationnal operator*(const Rationnal<T> & rhs);
  Rationnal operator/(const Rationnal<T> & rhs);

  // Opération d'affichage
  friend ostream & operator<< <>(ostream & os, const Rationnal<T> & rhs);
};

template <typename T> ostream & operator<<(ostream & os, const Rationnal<T> & rhs)
{
  os << rhs.num << " / " << rhs.den;
  return os;
}

template <typename T> Rationnal<T>::Rationnal(T numerateur, T denominateur, bool negatif)
{
  num = numerateur;
  den = denominateur;
  neg = negatif;

  const size_t LIMITE = 1000;

  // Gestion des non-signées
  if(num < 0 || den < 0)
    cout << "Nombre négatif"; // Arrêter programme

  // Simplifier
  T pgdc = PGDC(num, den);
  num /= pgdc;
  den /= pgdc;

  if(num > LIMITE || den > LIMITE)
    throw length_error("Depassement de la capacite");
  if(den == 0)
    throw overflow_error("Division par zero");
}

template <typename T> Rationnal<T> Rationnal<T>::operator+(const Rationnal<T> & rhs)
{
  //if(!neg && !rhs.neg)

  T n = num * rhs.den + rhs.num * den;
  T d = den * rhs.den;
  return Rationnal<T>(n, d);
}

template <typename T> Rationnal<T> Rationnal<T>::operator-(const Rationnal<T> & rhs)
{
  T n = num * rhs.den - rhs.num * den;
  T d = den * rhs.den;
  return Rationnal<T>(n, d);
}

template <typename T> Rationnal<T> Rationnal<T>::operator*(const Rationnal<T> & rhs)
{
  T n = num * rhs.num;
  T d = den * rhs.den;
  return Rationnal<T>(n, d);
}

template <typename T> Rationnal<T> Rationnal<T>::operator/(const Rationnal<T> & rhs)
{
  T n = num * rhs.den;
  T d = den * rhs.num;
  return Rationnal<T>(n, d);
}

const int NB_CHIFFRES = 12;

template <typename VF>
void imprime_ligne(const VF &ligne)
{
  for (size_t j = 0; j < ligne.size(); j++)
  {
    cout.width(NB_CHIFFRES);
    cout << setw(NB_CHIFFRES) << ligne[j] << " ";
  }
  cout << endl;
}

template <typename VVF>
void imprime_matrice(const VVF &t)
{
  for (size_t j = 1; j < (NB_CHIFFRES + 1) * t[0].size(); j++)
    cout << "-";
  cout << endl;
  for (size_t i = 0; i < t.size(); i++)
    imprime_ligne(t[i]);
  for (size_t j = 1; j < (NB_CHIFFRES + 1) * t[0].size(); j++)
    printf("-");
  cout << endl
       << endl;
}

// Opération de pivotage
template <typename VVF, typename S>
void pivote(VVF &t, S ligne, S colonne)
{
  for (size_t i = 0; i < t.size(); i++)
    if (i != ligne)
      for (size_t j = 0; j < t[0].size(); j++)
        if (j != colonne)
          t[i][j] = t[i][j] - t[i][colonne] * t[ligne][j] / t[ligne][colonne];

  for (size_t i = 0; i < t.size(); i++)
    if (i != ligne)
      t[i][colonne] = -t[i][colonne] / t[ligne][colonne];

  for (size_t j = 0; j < t[0].size(); j++)
    if (j != colonne)
      t[ligne][j] = t[ligne][j] / t[ligne][colonne];

  t[ligne][colonne] = 1 / t[ligne][colonne];
}

int main()
{
  cout << "~~~~~~~~~~~~~~~~~~ Equations a X inconnues ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  size_t nb_lignes = 6, nb_colonnes = 7;
  vector<vector<float>> t;

  t.push_back({17, 6, 93, 21, 95, 80, 312});
  t.push_back({32, 75, 45, 77, 95, 49, 373});
  t.push_back({91, 29, 48, 39, 17, 73, 297});
  t.push_back({93, 26, 92, 11, 37, 28, 287});
  t.push_back({56, 15, 59, 23, 9, 66, 228});
  t.push_back({37, 24, 72, 31, 45, 66, 275});

  /* Pivotages; si on choisit tous les éléments de la diagonale, on résout le système*/
  size_t row = 0, col = 0;
  for (size_t _ = 0; _ < min(nb_lignes, nb_colonnes); _++, row++, col++)
  {
    imprime_matrice(t);
    if (row < nb_lignes and col < nb_colonnes and t[row][col] != 0.0)
      pivote(t, row, col);
    else
      cout << "pivot non valide!\n";
  }
  imprime_matrice(t);

  Rationnal<uint64_t> a(3, 5), b(5, 1), c(6, 3), z(4, 1);
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fractions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << a << endl;  // 3/5
      // << b << endl  // 5
      // << c << endl; // 2
/*
  cout << a / z << endl  // 3/25
       << b - a << endl  // 22/5
       << b + c << endl  // 7
       << c * a << endl; // 6/5 */
}
