/*
Calvin Graf
09.12.2022
HEIG-VD | PRG | Labo 20

*/

#include <iostream>

using namespace std;

class Uint {
  string nbBinaire;
public:
  string construire(size_t binaire);
  Uint(uint64_t value) { nbBinaire = construire(value); }
  string plus_binaire(const Uint & a, const Uint & b);
  string multiplication_binaire(const string & a, const string & b);
  string soustraction_binaire(const Uint & a, const Uint & b);
  string division_binaire(const string & dividende, const string & diviseur);
  void affiche(string b);
};

string Uint::construire(size_t binaire)
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
string Uint::plus_binaire(const Uint & a, const Uint & b)
{
  if (b.nbBinaire.size() > a.nbBinaire.size())
    return plus_binaire(b, a);

    int diffTaille = a.nbBinaire.size() - b.nbBinaire.size();
    int retenue = 0;
    int aValue;
    int bValue;
    string res = "";

    for (int i = a.nbBinaire.size() - 1; i >= 0; i--) {
      if(i - diffTaille >= 0) bValue = (int)b.nbBinaire[i - diffTaille] - 48;
      else bValue = 0;
      aValue = (int)a.nbBinaire[i] - 48;

      if (aValue + bValue + retenue == 3) {
        res.insert(0, "1");
        retenue = 1;
      }
      else if(aValue + bValue +  retenue == 2)
      {
        res.insert(0, "0");
        retenue = 1;
      }
      else if(aValue + bValue + retenue == 1)
      {
        res.insert(0, "1");
        retenue = 0;
      }
      else
      {
        res.insert(0, "0");
        retenue = 0;
      }
    }
    if (retenue) res.insert(0, "1");

    return res;
}

string Uint::soustraction_binaire(const Uint & a, const Uint & b)
{
  Uint bComplDeux = b;
  Uint cplUn(1);
  for (size_t i = 0; i < bComplDeux.nbBinaire.size() ; i++) {
    if(bComplDeux.nbBinaire[i] == '1') bComplDeux.nbBinaire[i] = '0';
    else bComplDeux.nbBinaire[i] = '1';
  }
  bComplDeux.nbBinaire = bComplDeux.plus_binaire(bComplDeux, cplUn);
  cout << a.nbBinaire << " et " << bComplDeux.nbBinaire << endl;

  bComplDeux.nbBinaire = bComplDeux.plus_binaire(a, bComplDeux);

  return bComplDeux.nbBinaire;
  /*
  if (b.nbBinaire.size() > a.nbBinaire.size())
    return soustraction_binaire(b, a);

  int diffTaille = a.nbBinaire.size() - b.nbBinaire.size();
  int aValue;
  int bValue;
  string res = "";

  for (int i = a.nbBinaire.size() - 1; i >= 0; i--) {
    cout << "a : " << (int)a.nbBinaire[i] - 48 << endl;
    cout << "b : " << (int)b.nbBinaire[i - diffTaille] - 48 << endl;
    aValue = (int)a.nbBinaire[i] - 48;
    if(i - diffTaille >= 0) bValue = (int)b.nbBinaire[i - diffTaille] - 48;
    else bValue = 0;

    if(aValue + bValue == 2 || aValue + bValue == 0) res.insert(0, "0");
    else res.insert(0, "1");
  }

  return res;
  */
}

string Uint::multiplication_binaire(const string & a, const string & b)
{
  string resultat = "";
  string temp = b;
  for (int i = a.size() - 1; i >= 0; i--) {
  //  if (a.at(i) == '1') resultat = plus_binaire(resultat, temp);
    temp += "0";
  }
  return resultat;
}

string Uint::division_binaire(const string & dividende, const string & diviseur)
{
  string div = diviseur;
  string divid = dividende;
  string quotien = "";
  string reste = "";
  if (div.find("1")) return "Erreur";
  if(div.size() > divid.size()) return "Q : 0 \nR : " + divid;
  else if (div.size() == divid.size()) {
      for (size_t i = 0; i < divid.size(); i++) {
        if (div[i] == '1' && divid[i] == '0') return "Q : 0 \nR : " + divid;
        if (div[i] == '0' && divid[i] == '1') i = divid.size();
      }
  }

  while(div.size() < divid.size()) div.push_back('0');

  if(div > divid) div.pop_back();

  while(div != diviseur) {
    cout << div << " et " << divid << endl;
    if(div < divid) quotien.push_back('0');
    else {
       quotien.push_back('1');
       cout << " Whhhhaaaat ? : " << divid << endl;
       //divid = soustraction_binaire(div, divid);
       cout << "What : " << divid << endl;
    }
    div.pop_back();
  }

  cout << "Q : " << quotien << " R : " << divid << endl;

  return quotien;




/*

  bool dividendePlusGrand = true;
  do {
      for (size_t i = 0; i < divid.size(); i++) {
        if (div[i] == '1' && divid[i] == '0') quotien.push_back('0');
        if (div[i] == '0' && divid[i] == '1')  {
          quotien.push_back('1');
          divid = soustraction_binaire(divid, div);
        }
      }
      if(div != diviseur) {
        div.pop_back();
      }
      else {
        dividendePlusGrand = false;
        reste = divid;
      }
  }
  while(dividendePlusGrand);

  return quotien;
  */
}

void Uint::affiche(string b) {
  cout << "Nombre en base 2 : " << b << endl;
}


int main()
{
  Uint a(13);
  Uint b(5);
  //cout << a.division_binaire("100001", "101");
  cout << a.soustraction_binaire(a, b);
}
