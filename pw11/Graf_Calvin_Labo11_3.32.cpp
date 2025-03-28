/*
Calvin Graf
HEIG-VD | PRG | Labo 11

*/

#include <iostream>
#include <random>
#include <functional>

using namespace std;

auto gen_double01 = bind(uniform_real_distribution<double>(0,1), mt19937(1234)); // germe: 1234
auto gen_int1_3 = bind(uniform_int_distribution<int>(1,3), mt19937(987)); // un autre germe

const double PRECISION = 0.0000001;
const int TROIS = 3;

int main()
{
  double pi = 2 * acos(0.0) - TROIS;

  double estimationPi = 0;

  int troisRandom = 0;

  bool verification = true;
  while (verification) {
    if (troisRandom != 3)
    { troisRandom = gen_int1_3(); }

    estimationPi = gen_double01();
  if (estimationPi < pi + PRECISION && estimationPi > pi - PRECISION && troisRandom == TROIS) {
  verification = false;
  }
}
  estimationPi += TROIS;
}
