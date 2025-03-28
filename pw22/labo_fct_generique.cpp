int main() {
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
