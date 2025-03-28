/*
Auteur :   Graf Calvin
École :    HEIG-VD | PRG | Département TIC
Date :     23.12.2022
Desc. :    Déclaration des fonctions de la classe Uint et Base | labo 21
*/
#include <iostream>
#include "Uint.hpp"
#include <random>
#include <functional>

using namespace std;

// Opérateur d'affichage Base
ostream & operator<<(ostream & os, const Base & rhs)
{
  return os;
}

// Fonction
Uint ExponentiationModulaire(Uint b, Uint e, Uint m)
{
  Uint r = 1;
  while (e > 0) {
    if (e % 2 == 0)
    {
      b = b * b % m;
      e = e / 2;
    }
    else
    {
      r = r * b % m;
      --e;
    }
  }
  return r;
}

bool prime(Uint p)
{
  auto gen_int1_3 = bind(uniform_int_distribution<uint64_t>(1, 10000), mt19937(382));

  // Aucun nombre premier n'est inférieur à deux
  if (p < 2)
    return false;
  else if (p == 2) // 2 est un nombre premier
    return true;
  else if(p % 2 == 0 || (p % 3 == 0 && p != 3) || (p % 5 == 0 && p != 5) ||
          (p % 7 == 0 && p != 7) || (p % 11 == 0 && p != 11) ||
          (p % 13 == 0 && p != 13) || (p % 17 == 0 && p != 17) ||
          (p % 17 == 0 && p != 17))
    return false;
  /* On exclut tous les multiples de 2, 3, 5, 7, 11, 13, 17 qui sont des
  nombres premier pour accélérer le programme (3.5x). On ne fait pas au
  dessus de 17 car selon mes tests, ce n'est plus rentable. */

  for (int i = 0; i < 10; i++)
  {
    uint64_t nbAleatoire = gen_int1_3();
    Uint a(nbAleatoire);

    if (ExponentiationModulaire(a, p - 1, p) != 1) return false;

    Uint q = 1;
    Uint u = p - 1;
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

Base set_base(size_t b, const size_t FORMAT)
{
  Base v;
  Base::baseNb = b;
  Base::format = FORMAT;
  return v;
}

void arret(string msg)
{
  string arret;
  cout << "Erreur : " << msg << endl << "- Fin du programme -";
  cin >> arret; // Créer un arrêt pour que l'utilisateur puisse voir l'erreur
  exit(0);
}

// Class Base
// Valeur static
size_t Base::baseNb = 10;
size_t Base::format = 0;

// Class Uint
// private
// Fonction
string Uint::construire(size_t binaire)
{
  string str = "";
  if (binaire == 0) str = "0";

  while (binaire != 0) {
    if (binaire % 2 == 0)
      str.insert(0, "0");
    else
      str.insert(0, "1");
    binaire /= 2;
  }
  return str;
}

Uint Uint::retirer_zero(const Uint & lhs) const
{
  Uint res;
  size_t nbZero = 0;
  for (size_t i = 0; i < lhs.val.size() - 1; i++) {
    if(lhs.val[i] == '0') nbZero++;
    else i = lhs.val.size();
  }
  res.val = lhs.val.substr(nbZero);
  return res;
}

// public
// Constructeur
Uint::Uint()
{
  val = ""; // Permet d'éviter les erreurs avec les +=
}

Uint::Uint(size_t v)
{
  val = construire(v);
}

// Opérateur arithmétique

Uint & Uint::operator+=(const Uint & rhs)
{
  *this = *this + rhs;
  return *this;
}

Uint Uint::operator+(const Uint & rhs)
{
  Uint res;
  size_t retenue = 0;
  int lhsSize = val.size() - 1;
  int rhsSize = rhs.val.size() - 1;
  while(retenue != 0 || lhsSize >= 0 || rhsSize >= 0) {
    retenue += lhsSize >= 0 ? val[lhsSize] - 48 : 0;
    retenue += rhsSize >= 0 ? rhs.val[rhsSize] - 48 : 0;
    res.val.insert(0, to_string(retenue % 2));
    retenue /= 2; // Si retenue vaut 2 ou 3 alors on garde 1 sinon 0
    lhsSize--;
    rhsSize--;
  }
  return res;
}

Uint & Uint::operator-=(const Uint & rhs)
{
  *this = *this - rhs;
  return *this;
}

Uint Uint::operator-(const Uint & rhs) const
{
  Uint lhs;
  lhs.val = val;
  if(lhs < rhs) arret("Soustraction donnant un resultat negatif");

  Uint res;
  int bin = 0;
  bool retenue = false;
  int lhsSize = val.size() - 1;
  int rhsSize = rhs.val.size() - 1;
  while(lhsSize >= 0 || rhsSize >= 0) {
    bin += lhsSize >= 0 ? val[lhsSize] - 48 : 0;
    bin -= rhsSize >= 0 ? rhs.val[rhsSize] - 48 : 0;
    if(retenue) bin--;
    if(bin < 0) retenue = true;
    else retenue = false;
    res.val.insert(0, to_string(abs(bin % 2)));
    lhsSize--;
    rhsSize--;
    bin = 0;
  }
  res = retirer_zero(res);
  return res;
}

Uint & Uint::operator*=(const Uint & rhs)
{
  *this = *this * rhs;
  return *this;
}

Uint operator*(const Uint & lhs, const Uint & rhs)
{
  Uint res;
  Uint temp = rhs;
  if(lhs == 0 || rhs == 0)
  {
    res = 0;
    return res;
  }

  for (int i = lhs.val.size() - 1; i >= 0; i--) {
    if (lhs.val.at(i) == '1') res += temp;
    temp.val += "0";
  }
  return res;
}

Uint & Uint::operator/=(const Uint & rhs)
{
  *this = *this / rhs;
  return *this;
}

Uint Uint::operator/(const Uint & rhs)
{
  Uint q;
  Uint divid;
  divid.val = val;
  Uint div = rhs;
  div_mod_binaire(divid, div, q);
  return q;
}

Uint Uint::operator%(const Uint & rhs)
{
  Uint q;
  Uint divid;
  divid.val = val;
  Uint div = rhs;
  return div_mod_binaire(divid, div, q);
}

Uint & Uint::operator++()
{
  *this += 1;
  return *this;
}

Uint & Uint::operator--()
{
  *this -= 1;
  return *this;
}

// Conversion
Uint::operator uint64_t() const
{
  Uint conversion;
  conversion.val = val;
  Uint convMax(string::npos);
  if(conversion > convMax) arret("Conversion d'un Uint trop grand vers un uint64_t");

  uint64_t decimal = stoull(val, 0, 2);
  return decimal;
}

// Opérateur de comparaison
int Uint::operator<=>(const Uint & rhs)
{
  if(val.size() < rhs.val.size()) return -1;
  else if(val.size() > rhs.val.size()) return 1;
  else if (val < rhs.val) return -1;
  else if (val > rhs.val) return 1;
  return 0;
}

bool Uint::operator==(const Uint & rhs) const
{
  if(val == rhs.val) return 1;
  else return 0;
}

bool Uint::operator!=(const Uint & rhs) const
{
  if(val != rhs.val) return 1;
  else return 0;
}

// Opérateur de manipulation de bits
Uint & Uint::operator<<=(const size_t & rhs)
{
  for (size_t i = 0; i < rhs; i++) val.push_back('0');
  return *this;
}

Uint Uint::operator<<(const size_t & rhs)
{
  Uint res;
  res.val = val;
  for (size_t i = 0; i < rhs; i++) res.val.push_back('0');
  return res;
}

// Opérateur d'affichage Uint
ostream & operator<<(ostream & os, const Uint & rhs)
{
  Uint convB = rhs;
  string res = convB.conversion_base(convB, Base::baseNb);
  os << res;
  Base::baseNb = 10;
  return os;
}

// Fonction
string Uint::conversion_base(Uint n, size_t b)
{
  string res;
  Uint digit;
  Uint base(b);
  if(base < 2) return res;
  while (n >= base) {
    digit = n % base;
    res = get_digit(uint64_t(digit)) + res;
    n /= base;
  }
  res = get_digit(uint64_t(n)) + res;
  return res;
}

Uint Uint::div_mod_binaire(const Uint & dividende, const Uint & diviseur, Uint & quotient)
{
  Uint divid;
  divid = dividende;
  Uint div;
  div = diviseur;
  if (retirer_zero(div).val == "0") arret("Division par zero");

  if(div > divid) {
    quotient = 0;
    return divid;
  }

  string boucle = diviseur.val;
  boucle.pop_back();

  // On met la dividende et le diviseur à la même taille
  while(divid.val.size() != div.val.size()) div.val.push_back('0');

  // Si le diviseur est plus grand que le dividende, on retire un 0
  if(div > divid) div.val.pop_back();

  do
  {
      if(divid >= div && div.val != boucle) {
        divid -= div;
        quotient.val += "1";
      }
      else {
        quotient.val += "0";
      }
      if(div.val != boucle) div.val.pop_back();
  }
  while(div.val != boucle);

  if(divid.val.empty()) divid.val = "0";
  return divid;
}

char Uint::get_digit(uint64_t caractere)
{
  string contenu;
  if(Base::format == 0) contenu = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  else if(Base::format == 1) contenu = "0123456789abcdefghijklmnopqrstuvwxyz";
  const string DIGITS = contenu;
  return DIGITS[caractere];
}
