/*
Calvin Graf
09.12.2022
HEIG-VD | PRG | Labo 20

*/

#include <iostream>

using namespace std;

class Uint {
  string nbB;
  string construire(int binaire);
  string retirer_zero(string & str);
  string div_mod_binaire(const Uint & dividende, const Uint & diviseur, const bool & quotient);
public:
  Uint(uint64_t value = 0) { nbB = construire(value); }
  string plus_binaire(const Uint & lhs, const Uint & rhs);
  string multiplication_binaire(const Uint & lhs, const Uint & rhs);
  string soustraction_binaire(const Uint & lhs, const Uint & rhs);
  string division_binaire(const Uint & dividende, const Uint & diviseur);
  string modulo_binaire(const Uint & n, const Uint & mod);
  void affiche(Uint a);

  Uint & operator+= (const Uint & rhs) { Uint a; a.nbB = nbB; nbB = plus_binaire(a, rhs); return *this;}
  friend Uint operator+(Uint lhs, const Uint & rhs) {lhs += rhs; return lhs;}
  Uint & operator-= (const Uint & rhs) { Uint a; a.nbB = nbB; nbB = soustraction_binaire(a, rhs); return *this;}
  friend Uint operator-(Uint lhs, const Uint & rhs) {lhs -= rhs; return lhs;}

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

/*

  if (lhs.nbB.size() < rhs.nbB.size())
    return plus_binaire(rhs, lhs);

  string res = "";
  bool retenue = false;
  int diffTaille = lhs.nbB.size() - rhs.nbB.size();
  for (int i = lhs.nbB.size() - 1; i >= 0; i--) {
    cout << lhs.nbB[i] << " et " << rhs.nbB[i - diffTaille] << endl;
    if (lhs.nbB[i] == rhs.nbB[i - diffTaille]) {
      if (retenue) res.insert(0, "1");
      else res.insert(0, "0");
      if(lhs.nbB[i] == '1') retenue = true;
    }
    else
    {
      if(retenue) {
        res.insert(0, "0");
        retenue = false;
      }
      else res.insert(0, "1");
    }
  }
  cout << res << endl;
  return res;

  */
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

/*

  if(lhs.nbB == "0") return rhs.nbB;
//  if(rhs.nbB > lhs.nbB) return "Erreur";
  if(rhs.nbB == "0") return lhs.nbB;

  Uint bComplDeux = lhs;
  while(rhs.nbB.size() != bComplDeux.nbB.size()) bComplDeux.nbB.insert(0, "0");
  while(bComplDeux.nbB.size() % 4 != 0) bComplDeux.nbB.insert(0, "0");
  size_t posUn = bComplDeux.nbB.rfind('1');

  for (size_t i = 0; i < posUn; i++) {
    if(bComplDeux.nbB[i] == '1') bComplDeux.nbB[i] = '0';
    else bComplDeux.nbB[i] = '1';
  }
  Uint res(0);
  res.nbB = bComplDeux.plus_binaire(rhs, bComplDeux).substr(2);

//  posUn = bComplDeux.nbB.rfind('1');

  return res.nbB;

  */

  /*
  Uint bComplDeux = b;
  Uint cplUn(1);
  for (size_t i = 0; i < bComplDeux.nbB.size() ; i++) {
    if(bComplDeux.nbB[i] == '1') bComplDeux.nbB[i] = '0';
    else bComplDeux.nbB[i] = '1';
  }
  bComplDeux.nbB = bComplDeux.plus_binaire(bComplDeux, cplUn);
  cout << a.nbB << " et " << bComplDeux.nbB << endl;

  bComplDeux.nbB = bComplDeux.plus_binaire(a, bComplDeux);

  return bComplDeux.nbB;
  */
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

string Uint::div_mod_binaire(const Uint & dividende, const Uint & diviseur, const bool & quotient)
{
  Uint divid(0);
  divid.nbB = dividende.nbB;
  Uint div(0);
  div.nbB = diviseur.nbB;
  string q = "";
  string r = "";
  if (div.nbB.find("1") == string::npos) return "Erreur";

  if(div.nbB.size() > divid.nbB.size()) {
    if(quotient) return "0";
    else return divid.nbB;
  }
  else if (div.nbB.size() == divid.nbB.size()) {
      for (size_t i = 0; i < divid.nbB.size(); i++) {
        if (div.nbB[i] == '1' && divid.nbB[i] == '0') {
          if(quotient) return "0";
          else return divid.nbB;
        }
        if (div.nbB[i] == '0' && divid.nbB[i] == '1') i = divid.nbB.size();
      }
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
//  cout << "dividende : " << divid.nbB << endl << "diviseur : " << div.nbB << endl;
  do
  {
    if(divid.nbB.size() == 0) q += "0";
    for (size_t i = 0; i < divid.nbB.size(); i++) {
    //    cout << "div : " << div.nbB[i] << " et " << divid.nbB[i] << endl;
      if (div.nbB.size() < divid.nbB.size() || div.nbB[i] == '0' && divid.nbB[i] == '1' || i == divid.nbB.size() - 1) {
        q += "1";
        //cout << "Divid avant : " << divid.nbB << " Div avant : " << div.nbB << endl;
        divid.nbB = soustraction_binaire(divid, div);
        i = divid.nbB.size();
        //cout << "Divid apres : " << divid.nbB << " Div apres : " << div.nbB << endl;
      }
      else if (div.nbB[i] == '1' && divid.nbB[i] == '0' || div.nbB.size() > divid.nbB.size()) {
        q += "0";
        i = divid.nbB.size();
      }
    }
    div.nbB.pop_back();
  //  cout << div.nbB << " != " << boucle << endl;
  }
  while(div.nbB != boucle);

  r = divid.nbB;
  if(r.empty()) r = "0";

  if(quotient) return q;
  else return r;
}

string Uint::division_binaire(const Uint & dividende, const Uint & diviseur)
{
  return div_mod_binaire(dividende, diviseur, 1);
}

string Uint::modulo_binaire(const Uint & n, const Uint & mod)
{
  return div_mod_binaire(n, mod, 0);
}

void Uint::affiche(Uint a)
{
  cout << "Nombre en base 2 : " << a.nbB << endl;
}

int main()
{
  string s1 = "1100";
  string s2 = "1000";
  if(s1.compare(s2)) cout << "OK" << endl;


  Uint a(34);
  Uint b(2);
  Uint c;
  string str = a.multiplication_binaire(a, b);
  cout << str;
//  c.affiche(c);
}
