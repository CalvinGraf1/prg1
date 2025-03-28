#include <iostream>

using namespace std;

template <typename T> class Rationnal;

template <typename T> class Rationnal {
  bool bNegatif;
  T num;
  T den;
public:
  Rationnal() {};
  Rationnal(T numerateur, T denominateur, bool neg = false) : num(numerateur), den(denominateur) { neg == false ? bNegatif = false : bNegatif = true; };

  size_t PPDC(size_t lhs, size_t rhs);

  Rationnal operator+(Rationnal & rhs);
  //Rationnal & operator+=(const Rationnal & rhs);
  Rationnal operator-(Rationnal & rhs);
  //Rationnal & operator-=(const Rationnal & rhs);
  Rationnal operator*(Rationnal & rhs);
  Rationnal operator/(Rationnal & rhs);

  size_t PPMC(size_t lhs, size_t rhs);
  size_t PGDC(size_t lhs, size_t rhs);
  void Simplifier(Rationnal & lhs);

  //Rationnal operator<=>(const Rationnal & rhs);
  template <typename U> friend ostream & operator<<(ostream & os, const Rationnal<U> & rhs);
};

/*
template <typename T> Rationnal<T>::Rationnal(T num, T den)
{

}
*/
/*
template <typename T> size_t Rationnal<T>::PPDC(size_t lhs, size_t rhs)
{
  size_t r;
  while(rhs != 0) {
    r = lhs % rhs;
    lhs = rhs;
    rhs = r;
  }
  return abs(r);
}
*/

template <typename T> size_t Rationnal<T>::PPMC(size_t lhs, size_t rhs)
{
  size_t a = lhs;
  size_t b = rhs;

  while(a != b) {
    while(a > b) b += rhs;
    while(a < b) a += lhs;
  }
  return a;
}

template <typename T> size_t Rationnal<T>::PGDC(size_t lhs, size_t rhs)
{
    while(rhs != 0) {
        size_t a = lhs % rhs;
        lhs = rhs;
        rhs = a;
    }
    return lhs;
}

template <typename T> void Rationnal<T>::Simplifier(Rationnal & lhs)
{
  size_t diviseur = PGDC(lhs.num, lhs.den);

  if(diviseur != 1) {
    lhs.num /= diviseur;
    lhs.den /= diviseur;
  }
}

size_t PGG(size_t lhs, size_t rhs){
    while(rhs != 0) {
        size_t a = lhs % rhs;
        lhs = rhs;
        rhs = a;
    }
    return lhs;
}

template <typename T> Rationnal<T> Rationnal<T>::operator+(Rationnal & rhs)
{
  Rationnal simpl;
  simpl.num = num;
  simpl.den = den;

  Simplifier(rhs);
  Simplifier(simpl);

  num = simpl.num;
  den = simpl.den;

  Rationnal res(0, 0);

  size_t divCommun = den;
  if(den != rhs.den) {
    divCommun = PPMC(den, rhs.den);
    num *= divCommun / den;
    rhs.num *= divCommun / rhs.den;
  }

  res.den = divCommun;
  res.bNegatif = false;

  if(bNegatif && rhs.bNegatif) {
    res.num = num + rhs.num;
    res.bNegatif = true;
  }
  else if(bNegatif) {
    if(num > rhs.num) {
      res.num = num - rhs.num;
      res.bNegatif = true;
    }
    else res.num = rhs.num - num;
  }
  else if(rhs.bNegatif) {
    if(num >= rhs.num) res.num = num - rhs.num;
    else {
      res.num = rhs.num - num;
      res.bNegatif = true;
    }
  }
  else res.num = num + rhs.num;

  Simplifier(res);

  return res;
}

template <typename T> Rationnal<T> Rationnal<T>::operator-(Rationnal & rhs)
{
  Rationnal simpl;
  simpl.num = num;
  simpl.den = den;

  Simplifier(rhs);
  Simplifier(simpl);

  num = simpl.num;
  den = simpl.den;

  Rationnal res(0, 0);

  size_t divCommun = den;
  if(den != rhs.den) {
    divCommun = PPMC(den, rhs.den);
    num *= divCommun / den;
    rhs.num *= divCommun / rhs.den;
  }

  res.den = divCommun;
  res.bNegatif = false;

  if(bNegatif && rhs.bNegatif) {
    if(num > rhs.num) {
      res.num = num - rhs.num;
      res.bNegatif = true;
    }
    else res.num = rhs.num - num;
  }
  else if(bNegatif) {
    res.num = num + rhs.num;
    res.bNegatif = true;
  }
  else if(rhs.bNegatif) res.num = num + rhs.num;
  else {
    if(num >= rhs.num) res.num = num - rhs.num;
    else {
      res.num = rhs.num - num;
      res.bNegatif = true;
    }
  }

  Simplifier(res);

  return res;
}

template <typename T> Rationnal<T> Rationnal<T>::operator*(Rationnal & rhs)
{
  Rationnal simpl;
  simpl.num = num;
  simpl.den = den;

  Simplifier(rhs);
  Simplifier(simpl);

  num = simpl.num;
  den = simpl.den;

  Rationnal res(0, 0);

  size_t divCommun = den;
  if(den != rhs.den) {
    divCommun = PPMC(den, rhs.den);
    num *= divCommun / den;
    rhs.num *= divCommun / rhs.den;
  }

  if(!bNegatif && !rhs.bNegatif || bNegatif && rhs.bNegatif) res.bNegatif = false;
  else res.bNegatif = true;

  res.num = num * rhs.num;
  res.den = divCommun;

  Simplifier(res);

  return res;
}

template <typename T> Rationnal<T> Rationnal<T>::operator/(Rationnal & rhs)
{
  Rationnal simpl;
  simpl.num = num;
  simpl.den = den;

  Simplifier(rhs);
  Simplifier(simpl);

  num = simpl.num;
  den = simpl.den;

  Rationnal res(0, 0);
  
  /*
  size_t divCommun = den;
  if(den != rhs.den) {
    divCommun = PPMC(den, rhs.den);
    num *= divCommun / den;
    rhs.num *= divCommun / rhs.den;
  }
  */

  if(!bNegatif && !rhs.bNegatif || bNegatif && rhs.bNegatif) res.bNegatif = false;
  else res.bNegatif = true;

  cout << num << " * " << rhs.den << endl;
  cout << den << " * " << rhs.num << endl;
  res.num = num * rhs.den;
  res.den = den * rhs.num;

  Simplifier(res);

  return res;
}

template <typename U> ostream & operator<<(ostream & os, const Rationnal<U> & rhs)
{
  if(rhs.bNegatif) cout << "- ";
  os << rhs.num << " / " << rhs.den;
  return os;
}


int main()
{
  Rationnal a(12, 1);
  Rationnal b(3, 2);
  cout << a / b;
}
