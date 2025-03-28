#include <iostream>

using namespace std;

template <typename T> size_t occ_le(const T tbl[], const int TAILLE, const T val);
template <typename T, typename U> size_t occ_le(const T tbl[], const int TAILLE, const U val[]);

class Temps {
  size_t heure, minute;
public:
  Temps(size_t h, size_t m) : heure(h), minute(m) {}
  int operator<=>(const Temps & rhs) const;
//  bool operator==(const Temps & rhs) const = default;
};

int Temps::operator<=>(const Temps & rhs) const
{
  if(heure > rhs.heure) return 1;
  else if (heure < rhs.heure) return -1;
  else
  {
    if(minute > rhs.minute) return 1;
    else if (minute < rhs.minute) return -1;
    else return 0;
  }
}

template <typename T> size_t occ_le(const T tbl[], const int TAILLE, const T val)
{
  size_t nbOccurence = 0;
  for (size_t i = 0; i < TAILLE; i++) {
    if(tbl[i] <= val) nbOccurence++;
  }
  return nbOccurence;
}

template <typename T, typename U> size_t occ_le(const T tbl[], const int TAILLE, const U val[])
{
  size_t nbOccurence = 0;
  for (size_t i = 0; i < TAILLE; i++) {
    if(tbl[i] <= val) nbOccurence++;
  }
  return nbOccurence;
}

int main()
{
  const int N = 6;
  int ti[] = {0,1,2,0,3,0};
  const char TC[] = {"PaulJa"};
  const Temps TT[] = {{7, 45}, {9, 20}, {12, 0}, {21, 30}, {20, 13}, {18, 3}};
  string ts[] = {"Paul", "Jacques", "Paul", "Pie", "Pierre", "Paul"};
  cout << occ_le(ti, N, 0) << endl            // 3
       << occ_le(TC, N, 'a') << endl          // 4
       << occ_le(TT, N, Temps(12, 0)) << endl // 3
       << occ_le(ts, N, "Paul"s) << endl      // 4
       << occ_le(ts, N, "Paul") << endl       // 4
       << occ_le(TT, N, {12, 0}) << endl;     // 3
}
