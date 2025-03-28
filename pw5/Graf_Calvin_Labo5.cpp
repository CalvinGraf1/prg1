/* By Calvin Graf
27.09.2022
HEIG-VD | PRG - Labo 5
Le programme sert a calculé l'angle de l'aiguille des secondes d'une montre
à l'horizontal en dixième de degré.
 */

#include <iostream>
#include <string>

using namespace std;

const int MINUTE = 60;
const int CONVERSION = 3600;
const int HORIZONTAL = 900;

int main(){

	int iSeconde;
	int iMinute;
	int iDegre;
	int iVerifHours;
	int iNbTours;

	cout << "Veuillez entrer le dixième de degré : ";
	cin >> iDegre;

	// On récupère le nomobre de tour(s) de la montre
	iNbTours = iDegre / CONVERSION;

	// On ajoute 900 pour mettre à l'horizontal + 3600 * le nombre de tour(s) pour avoir un chiffre positif.
	iSeconde = -iDegre + HORIZONTAL + CONVERSION * iNbTours;

  // On récupère le nombre de minute(s) et de seconde(s)
	iMinute = iSeconde / MINUTE;
  iSeconde = iSeconde % MINUTE;

	// On vérifie que le nombre de minute(s) ne dépasse pas 60
	iVerifHours = iMinute / MINUTE;

	// Si le nombre de minutes dépasse 60, on retire 60 minutes, sinon on retire 0
	iMinute = iMinute - iVerifHours * MINUTE;

    cout << iMinute << " minute(s) et " << iSeconde << " seconde(s)";

}
