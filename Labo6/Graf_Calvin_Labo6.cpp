/* By Calvin Graf
28.09.2022
HEIG-VD | PRG - Labo 6
Le programme calcule la durée d'un trajet de 24h max. Le trajet peut être sur 2 jours.
*/

#include <iostream>
#include <string>

using namespace std;

const int HOUR = 24;
const int MINUTE = 60;

int main(){

	string strDepartureTime;
	string strArrivingTime;

	int iHourDeparture;
	int iMinuteDeparture;

	int iHourArriving;
	int iMinuteArriving;

	int iRouteHour;
	int iRouteMinute;

	int iVerifHour;
	int iVerifMinute;
	int iVerifNegatif;

	cout << "Veuillez entrer l'heure de départ : ";
	cin >> strDepartureTime;

	cout << "Veuillez entrer l'heure d'arrivée : ";
	cin >> strArrivingTime;

	iHourDeparture = stoi(strDepartureTime.substr(0, 2));
	iMinuteDeparture = stoi(strDepartureTime.substr(3));

	iHourArriving = stoi(strArrivingTime.substr(0, 2));
	iMinuteArriving = stoi(strArrivingTime.substr(3));

	// On récupère le nombre d'heure de trajet total (négatif ou positif)
	iRouteHour = iHourArriving - iHourDeparture + HOUR;
	iRouteMinute = iMinuteArriving - iMinuteDeparture + MINUTE;

	// On vérifie si le nombre est en négatif ou non, s'il l'est on attribue la valeur 1 sinon 0
	iVerifNegatif = (iRouteMinute + MINUTE) / MINUTE;

	// Si le nombre de minute est de 60, alors on attribue 0 à la vérification
	iVerifNegatif = iVerifNegatif % 2;

	// On vérifie que le nombre de minute(s) ne dépasse pas 60 et le nombre d'heure 24
	iVerifHour = iRouteHour / HOUR;
	iVerifMinute = iRouteMinute / MINUTE;

	// Si le nombre de minutes dépasse 60, on retire 60 minutes, sinon on retire 0. Pareil pour les heures avec 24
	iRouteHour = iRouteHour - iVerifHour * HOUR - iVerifNegatif;
	iRouteMinute = iRouteMinute - iVerifMinute * MINUTE;

	cout << iRouteHour << " heures " << iRouteMinute << " minutes";
}
