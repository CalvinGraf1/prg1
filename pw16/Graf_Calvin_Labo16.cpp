/*
Calvin Graf
18.11.2022
HEIG-VD | PRG | Labo 16

*/

#include <iostream>

using namespace std;

string construire(size_t binaire);
string plus_binaire(const string & a, const string & b);
string multiplication_binaire(const string & a, const string & b);
void Fibonnaci(size_t n);


int main()
{
  //cout << construire(2) << endl << construire(4) << endl;
  //cout << plus_binaire(construire(9), construire(1));
  //Fibonnaci(95)
  //cout << multiplication_binaire(construire(37), construire(43)) << endl;;

  // Factorielle
  size_t nbFactorielle = 10;
  string resultat = "1";
  for (size_t i = 1; i <= nbFactorielle; i++) {
    resultat = multiplication_binaire(resultat, construire(i));
  }
  cout << resultat;
}

string multiplication_binaire(const string & a, const string & b)
{
  string resultat = "";
  string temp = b;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a.at(i) == '1') resultat = plus_binaire(resultat, temp);
    temp += "0";
  }
  return resultat;
}

void Fibonnaci(size_t n)
{
  string f_1 = construire(0);
  string f_2 = construire(1);
  string f_3;
  cout << "F0 : " << f_1 << endl << "F1 : " << f_2 << endl;
  for (size_t i = 0; i < n; i++) {
    f_3 = plus_binaire(f_1, f_2);
    cout << "F" << i + 2 << " : " << f_3 << endl;
    f_1 = f_2;
    f_2 = f_3;
  }
}

string construire(size_t binaire)
{
  string str = "";
  while (binaire != 0) {
    if (binaire % 2 == 0)
      str.insert(0, "0");
    else
      str.insert(0, "1");
    binaire /= 2;
  }
  if (str == "") str = "0";
  return str;
}

// lhs = left hand side
string plus_binaire(const string & a, const string & b)
{
  string result = "";
   int temp = 0;
   int size_a = a.size() - 1;
   int size_b = b.size() - 1;
   while (size_a >= 0 || size_b >= 0 || temp == 1){
      temp += ((size_a >= 0) ? a[size_a] - '0': 0);
      temp += ((size_b >= 0) ? b[size_b] - '0': 0);
      result = char(temp % 2 + '0') + result;
      temp /= 2;
      size_a--; size_b--;
   }
   return result;
}
