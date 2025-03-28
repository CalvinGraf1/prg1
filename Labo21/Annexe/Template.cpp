#include <iostream>
#include <vector>

using namespace std;

Uint Uint::operator+(const Uint & rhs)
{
//  cout << val << endl;
//  cout << rhs.val << endl;
  Uint res;
  size_t retenue = 0;
  int lhsSize = val.size() - 1;
  int rhsSize = rhs.val.size() - 1;
  while(retenue != 0 || lhsSize >= 0 || rhsSize >= 0) {
    retenue += lhsSize >= 0 ? val[lhsSize] - 48 : 0;
    retenue += rhsSize >= 0 ? rhs.val[rhsSize] - 48 : 0;
    //res.val.insert(0, to_string(retenue % 2));
    res.val += to_string(retenue % 2);
    retenue /= 2; // Si retenue vaut 3 alors on garde 1 de retenue sinon 0
    lhsSize--;
    rhsSize--;
  }

  
int main()
{

}
