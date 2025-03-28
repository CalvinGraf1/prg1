// Fichier uint.hpp
#include <iostream>
#include <string>

using namespace std;

#ifndef UINT // Protection contre les inclusions multiples
#define UINT

class Base;
class Uint;

// Opérateur d'affiche Base
ostream & operator<<(ostream & os, const Base & rhs);

// Fonctions
Uint ExponentiationModulaire(Uint b, Uint e, Uint m);
bool prime(Uint p);
Base set_base(size_t b, const size_t FORMAT = 0);
void arret(string msg = "Inconnue");

// Classe qui gère la base et le format d'affichage des nombres
class Base {
public:
    static size_t baseNb;
    static size_t format;
    Base() {};
};

class Uint {
  string val;
  // Transforme un nombre en binaire
  string construire(size_t binaire);
  // Retire les zéros inutile d'un Uint
  Uint retirer_zero(const Uint & lhs) const;
  public:
    // Constructeur
    Uint();
    Uint(size_t v);

    // Opérateur arithmétique
    Uint & operator+=(const Uint & rhs);
    Uint operator+(const Uint & rhs);
    Uint & operator-=(const Uint & rhs);
    Uint operator-(const Uint & rhs) const;
    Uint & operator*=(const Uint & rhs);
    friend Uint operator*(const Uint & lhs, const Uint & rhs);
    Uint & operator/=(const Uint & rhs);
    Uint operator/(const Uint & rhs);
    Uint operator%(const Uint & rhs);
    Uint & operator++();
    Uint & operator--();

    // Conversion
    explicit operator uint64_t() const;

    // Opérateur de comparaison
    int operator<=>(const Uint & rhs);
    bool operator==(const Uint & rhs) const;
    bool operator!=(const Uint & rhs) const;

    // Opérateur de manipulation de bits
    Uint & operator<<=(const size_t & rhs);
    Uint operator<<(const size_t & rhs);

    // Opérateur d'affichage
    friend ostream & operator<<(ostream & os, const Uint & rhs);

    // Fonction
    string conversion_base(Uint n, size_t b);
    char get_digit(uint64_t caractere);
    Uint div_mod_binaire(const Uint & dividende, const Uint & diviseur, Uint & quotient);
};

#endif
