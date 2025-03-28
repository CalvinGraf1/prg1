// By Calvin Graf | 21.09.2022 | PRG - Labo 2

#include <iostream>
#include <string>
using namespace std;
int main() {
string strFirstName;
int iAge;
int iYearOfBirth;
cout << "Bonjour, veuillez entrer votre prenom : ";
getline(cin, strFirstName); // "getline" récupère toute la ligne à l'inverse de "cin" qui s'arrête à l'espace
cout << "Veuillez entrer votre age : ";
cin >> iAge;
time_t tYear = time(0); // On récupère le temps écoulé depuis 1900
tm *const C_TIME = localtime(&tYear); 
tYear = 1900 + C_TIME->tm_year; // On ajoute 1900 pour obtenir l'année actuelle
iYearOfBirth = tYear - iAge; // On soustrait l'âge de la personne à l'année en cours
cout << "\nBonjour, " << strFirstName << "\nVous avez " << iAge << " ans et vous etes ne(e) en " << iYearOfBirth;
}