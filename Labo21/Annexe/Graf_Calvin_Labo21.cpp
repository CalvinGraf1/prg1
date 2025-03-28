/*
Calvin Graf
09.12.2022
HEIG-VD | PRG | Labo 21
Explication :
*/
#include <iostream>

using namespace std;

class Uint {
  string nbB;
  string construire(int binaire);
  string retirer_zero(string & str);
public:
  // Constructeur
  Uint(uint64_t value = 0) { nbB = construire(value); }

  // Fonction membre
  string plus_binaire(const Uint & lhs, const Uint & rhs);
  string multiplication_binaire(const Uint & lhs, const Uint & rhs);
  string soustraction_binaire(const Uint & lhs, const Uint & rhs);
  string div_mod_binaire(const Uint & dividende, const Uint & diviseur, string & quotient);
  void affiche(Uint a);

  // Opérateur
  Uint & operator+=(const Uint & rhs) { Uint a; a.nbB = nbB; nbB = plus_binaire(a, rhs); return *this;}
  friend Uint operator+(Uint lhs, const Uint & rhs) {lhs += rhs; return lhs;}
  Uint & operator-=(const Uint & rhs) { Uint a; a.nbB = nbB; nbB = soustraction_binaire(a, rhs); return *this;}
  friend Uint operator+(Uint lhs, const Uint & rhs) {lhs -= rhs; return lhs;}


  int operator<=>(const Uint & rhs) const {
    if(nbB.size() > rhs.nbB.size()) {
      return 1;
    }
    else if (nbB.size() == rhs.nbB.size()) {
        for (size_t i = 0; i < rhs.nbB.size(); i++) {
          if (nbB[i] == '1' && rhs.nbB[i] == '0') return 1;
          if (nbB[i] == '0' && rhs.nbB[i] == '1') return -1;
        }
        return 0;
    }
    return -1;
  }

};

string Uint::construire(int binaire)
{
  string str = "";

  // On ne met pas "binaire" en size_t pour pouvoir gérer l'erreur
  if(binaire < 0) return "Erreur";

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

string Uint::retirer_zero(string & str) {
  while(str[0] == '0') str = str.substr(1);
  return str;
}

string Uint::plus_binaire(const Uint & lhs, const Uint & rhs)
{
  string res = "";
  size_t retenue = 0;
  int lhsSize = lhs.nbB.size() - 1;
  int rhsSize = rhs.nbB.size() - 1;
  while(retenue != 0 || lhsSize >= 0 || rhsSize >= 0) {
    retenue += lhsSize >= 0 ? lhs.nbB[lhsSize] - 48 : 0;
    retenue += rhsSize >= 0 ? rhs.nbB[rhsSize] - 48 : 0;
    res.insert(0, to_string(retenue % 2));
    retenue /= 2; // Si retenue vaut 3 alors on garde 1 de retenue sinon 0
    lhsSize--;
    rhsSize--;
  }

  // Verifier que des 0 s'ajoute pas sinon retirer_zero(); - Normalement OK
  return res;
}

string Uint::soustraction_binaire(const Uint & lhs, const Uint & rhs)
{
  // Verifier que rhs est plus petit que lhs
//  if(lhs < rhs) return "Erreur";

  string res = "";
  int bin = 0;
  bool retenue = false;
  int lhsSize = lhs.nbB.size() - 1;
  int rhsSize = rhs.nbB.size() - 1;
  while(lhsSize >= 0 || rhsSize >= 0) {
    bin += lhsSize >= 0 ? lhs.nbB[lhsSize] - 48 : 0;
    bin -= rhsSize >= 0 ? rhs.nbB[rhsSize] - 48 : 0;
    if(retenue) bin--;
    if(bin < 0) retenue = true;
    else retenue = false;
    res.insert(0, to_string(abs(bin % 2)));
    lhsSize--;
    rhsSize--;
    bin = 0;
  }
  return retirer_zero(res);
}

string Uint::multiplication_binaire(const Uint & lhs, const Uint & rhs)
{
  // Si l'un des nombres est erronée, gérer l'erreur
  if(lhs.nbB == "Erreur" || rhs.nbB == "Erreur") return "Erreur";

  Uint res(0);
  Uint temp(0);
  temp.nbB = rhs.nbB;
  for (int i = lhs.nbB.size() - 1; i >= 0; i--) {
    if (lhs.nbB.at(i) == '1') res.nbB = plus_binaire(res, temp);
    temp.nbB += "0";
  }
  return res.nbB;
}

string Uint::div_mod_binaire(const Uint & dividende, const Uint & diviseur, string & quotient)
{
  Uint divid(0);
  divid.nbB = dividende.nbB;
  Uint div(0);
  div.nbB = diviseur.nbB;
  if (div.nbB.find("1") == string::npos) {
    quotient = "Erreur";
    return "Erreur";
  }
  if(div > divid) {
    quotient = "0";
    return divid.nbB;
  }

  while(divid.nbB.size() != div.nbB.size()) div.nbB.push_back('0');
  for (size_t i = 0; i < divid.nbB.size(); i++) {
    if (div.nbB[i] == '1' && divid.nbB[i] == '0') {
      div.nbB.pop_back();
      i = divid.nbB.size();
    }
    if (div.nbB[i] == '0' && divid.nbB[i] == '1') i = divid.nbB.size();
  }

  string boucle = "";
  if(diviseur.nbB.size() > 1) boucle = diviseur.nbB.substr(0, diviseur.nbB.size() - 1);
  do
  {
    if(divid.nbB.size() == 0) quotient += "0";
    for (size_t i = 0; i < divid.nbB.size(); i++) {
      if (div.nbB.size() < divid.nbB.size() || div.nbB[i] == '0' && divid.nbB[i] == '1' || i == divid.nbB.size() - 1) {
        quotient += "1";
        divid.nbB = soustraction_binaire(divid, div);
        i = divid.nbB.size();
      }
      else if (div.nbB[i] == '1' && divid.nbB[i] == '0' || div.nbB.size() > divid.nbB.size()) {
        quotient += "0";
        i = divid.nbB.size();
      }
    }
    div.nbB.pop_back();
  }
  while(div.nbB != boucle);
  if(divid.nbB.empty()) divid.nbB = "0";
  return divid.nbB;
}

void Uint::affiche(Uint a)
{
  cout << "Nombre en base 2 : " << a.nbB << endl;
}

int main()
{
  Uint a(6);
  Uint b(2);
  Uint c = 3;
  string q;
  cout << c.div_mod_binaire(a, b, q) << " et " << q << endl;
string iSeconde;
    cin >> iSeconde;
}
