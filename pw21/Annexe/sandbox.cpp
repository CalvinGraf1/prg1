#include <iostream>

using namespace std;

class Uint {
  int val;
  public:
    // Constructeur
    Uint(int v = 0): val(v) {}

    // Opérateur arithmétique
    Uint & operator=(const int & rhs);
    Uint & operator+=(const Uint & rhs);
    //Uint operator+(Uint lhs, const Uint & rhs);
    Uint & operator-=(const Uint & rhs);
    //Uint operator-(Uint lhs, const Uint & rhs);

    // Opérateur de comparaison

};

Uint & Uint::operator=(const int & rhs)
{
  val = rhs;
  return *this;
}

int main()
{

}
