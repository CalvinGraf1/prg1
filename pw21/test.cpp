/*
Auteur :   Graf Calvin
École :    HEIG-VD | PRG | Département TIC
Date :     23.12.2022
Desc. :    Programme de test d'une classe Uint permettant de travailler
           sur des entiers naturels de taille non limitée.
*/

#include <iostream>
#include "Uint.hpp" 

using namespace std;

Uint fibo(size_t n) {
  Uint f_i_moins_1(0), f_i(1), f_i_plus_1;
  if (n == 0) return f_i_moins_1;
  if (n == 1) return f_i;
  for (size_t i = 2; i <= n; i++){
    f_i_plus_1 = f_i_moins_1 + f_i;
    f_i_moins_1 = f_i;
    f_i = f_i_plus_1;
  }
  return f_i;
}

Uint factorielle(size_t n) {
  Uint res(1);
  for (size_t i = 2; i <= n; i++)
    res *= i;
  return res;
}

int main() {

  Uint a(10);
  cout << "Constructeur avec size_t OK\n";

  Uint erreur(0);
  Uint g(0);

  Uint b;
  cout << "Constructeur vide OK\n";

  b = 3;
  cout << "Affectation OK\n";

  const Uint c = 13;
  cout << uint64_t(c) << " = 13: cast explicite vers uint64_t\n";

  if (a < c)
    cout << "Operateur < OK\n";
  else
    cout << "a < c : " << (a < c) << " pas bon!!!\n";

  b += a;
  cout << "Operateur+=\n";

  if (c == b)
    cout << "Comparaison == OK\n";
  else
    cout << "c == b : " << (c == b) << " Operateur == ou += pas bon!!!\n";

  a = fibo(50);
  cout << "fibo(50)\n";

  b = fibo(51);
  const Uint d = fibo(52);
  if (d == a + b)
    cout << "Operateur+ OK\n";
  else
    cout << "+ ou == pas bon!!!\n";

  if (d - b != a)
    cout << "- ou != pas bon!!!\n";
  else
    cout << "Operateur- OK\n";

  a = factorielle(50);
  cout << "Factorielle\n";

  b = factorielle(51);
  if (51 * a == b)
    cout << "Operateur* et *= OK\n";
  else
    cout << "* ou *= ou == pas bon!!!\n";

  if (51 != b / a)
    cout << "/ ou != pas bon!!!\n";
  else
    cout << "Operateur/ OK\n";

  cout << "51! en base 10 = " << b << endl;

  //  Le modificateur set_base(...) n'affecte que la prochaine impression d'un Uint
  cout << set_base(16) << "Modificateur d'impression Uint\n";
  cout << "51! en base 16 = " << b << endl;

  cout << "52e terme de la suite de Fibonacci, en base 10 = " << d << endl;

  a = 1;
  a <<= 99;
  cout << "Operateur <<=\n";

  cout << "2 ^ 99 = " << a << endl;

  b = (Uint(1) << 100) -1;
  cout << "Operateur <<\n";

  const int LOWER_CASE = 1; // LIGNE AJOUTÉE
  cout << set_base(16, LOWER_CASE);
  cout << "2 ^ 100 - 1 (base 16, bas de casse) = " << b << endl;

  cout << "10 plus petits nombres premiers > 2^99\n";
  size_t nb = 0;
  while (nb < 10) {
    if (prime(a)) {
      cout << a << endl;
      nb++;
    }
    ++a;
 }
 cout << "10 plus grands nombres premiers < 2^100\n";
 nb = 0;
 while (nb < 10) {
   if (prime(b)) {
     cout << b << endl;
     nb++;
   }
   --b;
  }

  string str; // LIGNE AJOUTÉE
  cin >> str; // LIGNE AJOUTÉE
}

/* Résultat de l'exécution:

Constructeur avec size_t OK
Constructeur vide OK
Affectation OK
13 = 13: cast explicite vers uint64_t
Operateur < OK
Operateur+=
Comparaison == OK
fibo(50)
Operateur+ OK
Operateur- OK
Factorielle
Operateur* et *= OK
Operateur/ OK
51! en base 10 = 1551118753287382280224243016469303211063259720016986112000000000000
Modificateur d'impression Uint
51! en base 16 = EBA8F91E823EE3E18972ACC521C1C87CED2093CFDBE800000000000
52e terme de la suite de Fibonacci, en base 10 = 32951280099
Operateur <<=
2 ^ 99 = 633825300114114700748351602688
Operateur <<
2 ^ 100 - 1 (base 16, bas de casse) = fffffffffffffffffffffffff
10 plus petits nombres premiers > 2^99
633825300114114700748351602943
633825300114114700748351603131
633825300114114700748351603197
633825300114114700748351603263
633825300114114700748351603341
633825300114114700748351603389
633825300114114700748351603407
633825300114114700748351603431
633825300114114700748351603467
633825300114114700748351603477
10 plus grands nombres premiers < 2^100
1267650600228229401496703205361
1267650600228229401496703205277
1267650600228229401496703205223
1267650600228229401496703205193
1267650600228229401496703205109
1267650600228229401496703205091
1267650600228229401496703205019
1267650600228229401496703204897
1267650600228229401496703204773
1267650600228229401496703204543

*/
