/*
Auteur:   Changanaqui Yoann
Desc:     Labo23
École:    HEIG-VD
Date:     13.01.2023
Fichier:  labo23_Changanaqui_Yoann.cpp
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
T findPgdc(T a, T b)
{
  while (b != 0)
  {
    T temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

template <typename T, size_t MaxNum, size_t MaxDen>
class Rationnal
{
  T num_;
  T den_;

public:
  // Ctor
  Rationnal(T num, T den) : num_(num), den_(den)
  {
    // Gestion des Non Signés
    if (num_ < 0)
      num_ = -num_;
    if (den_ < 0)
      den_ = -den_;
    // Réduit la fraction à la forme la plus petite (Ex: 5/15 --> 1/3)
    T pgdc = findPgdc(num_, den_);
    num_ /= pgdc;
    den_ /= pgdc;

    // Dépassements
    if (num_ > MaxNum || den_ > MaxDen)
      throw overflow_error("Dépassement de capacitées");
  }
  Rationnal(T num) : num_(num), den_(1)
  {
    // Gestion des Non Signés
    if (num_ < 0)
      num_ = -num_;
    if (den_ < 0)
      den_ = -den_;

    // Dépassements
    if (num_ > MaxNum || den_ > MaxDen)
      throw overflow_error("Dépassement de capacitées");
  }
  Rationnal() : num_(0), den_(1) {}

  // Getter (Accès aux attributs de la classe)
  T num() const { return num_; }
  T den() const { return den_; }

  // Opérations Arithmétiques
  Rationnal<T, MaxNum, MaxDen> operator+(const Rationnal<T, MaxNum, MaxDen> &other)
  {
    T num = num_ * other.den_ + other.num_ * den_;
    T den = den_ * other.den_;
    return Rationnal<T, MaxNum, MaxDen>(num, den);
  }
  Rationnal<T, MaxNum, MaxDen> operator-(const Rationnal<T, MaxNum, MaxDen> &other)
  {
    T num = num_ * other.den_ - other.num_ * den_;
    T den = den_ * other.den_;
    return Rationnal<T, MaxNum, MaxDen>(num, den);
  }
  Rationnal<T, MaxNum, MaxDen> operator*(const Rationnal<T, MaxNum, MaxDen> &other)
  {
    T num = num_ * other.num_;
    T den = den_ * other.den_;
    return Rationnal<T, MaxNum, MaxDen>(num, den);
  }
  Rationnal<T, MaxNum, MaxDen> operator/(const Rationnal<T, MaxNum, MaxDen> &other)
  {
    if (other.den() == 0)
      throw overflow_error("Division par 0 Impossible !");
    // cerr << "Division par 0 Impossible !";
    T num = num_ * other.den_;
    T den = den_ * other.num_;
    return Rationnal<T, MaxNum, MaxDen>(num, den);
  }

  // Affichage de Fraction (Format: x/y)
  friend ostream &operator<<(ostream &os, const Rationnal<T, MaxNum, MaxDen> &r)
  {
    if (r.den() != 1)
      os << r.num() << '/' << r.den();
    else
      os << r.num();
    return os;
  }
};

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

/*Opération de pivotage */
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
  cout << "~~~~~~~~~~~~~~~~~~Équations à X inconnues~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

  const int LIMIT = 100;
  Rationnal<int, LIMIT, LIMIT> a(-3, 5), b(-5), c(6, 3), z(4, 1);
  // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~Fractions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << a << endl  // 3/5
       << b << endl  // 5
       << c << endl; // 2

  cout << a / z << endl  // 3/25
       << b - a << endl  // 22/5
       << b + c << endl  // 7
       << c * a << endl; // 6/5
}
