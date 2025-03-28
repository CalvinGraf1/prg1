/*
By Calvin Graf
04.10.2022
HEIG-VD | PRG | Labo 7
Le programme permet de transformer des degré celcius en Fahrenheit et vice-versa
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

  char cAnswer;
  int iFahrenheit;
  int iCelsius;

  cout << "Voulez-vous transformer des degres Celsius (C) ou des Fahrenheit (F) ? ";
  cin >> cAnswer;

  // On vérifie le choix de l'utilisateur
  if(cAnswer == 'C' || cAnswer == 'c')
  {
    cout << "Nombre de degré celsius : ";
    cin >> iCelsius;
    iFahrenheit = ((18 * iCelsius + 5) / 10) + 32; // Transformation en Fahrenheit
    if (iCelsius < 0)
    { iFahrenheit--; }
    cout << iCelsius << " degres Celsius font " << iFahrenheit << " Fahrenheit";
  }
  else if (cAnswer == 'F' || cAnswer == 'f')
  {
    cout << "Nombre de Fahrenheit : ";
    cin >> iFahrenheit;
    iCelsius = (10 * (iFahrenheit - 32) + 9) / 18; // Transformation en degré celsius
    if (iCelsius < 0)
    { iCelsius--; }
    cout << iFahrenheit << " Fahrenheit font " << iCelsius << " degres Celsius";
  }
  else // Permet de vérifier que la valeur entrée est correcte
  { cout << "La valeur entree n'est pas correcte.";  }

}
