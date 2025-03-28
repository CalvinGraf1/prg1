// By Calvin Graf | 21.09.2022 | HEIG-VD | PRG - Labo 3 | Transformer des secondes en minutes / heures / jours / semaines

#include <iostream>
#include <string>
using namespace std;

    const int MINUTE = 60;
    const int HOUR = 3600;
    const int DAY = 86400;
    const int WEEK = 604800;
	
int main() {
	
	// Déclaration des variables
    int iSeconde;
    int iMinute;
    int iHour;
    int iDay;
    int iWeek;
    
	// Récupérer le nombre de seconde entrée par l'utilisateur
    cout << "Bonjour, veuillez entrer le nombre de seconde(s) : ";
    cin >> iSeconde;
    

	// On récupère le nb de sem. en divisant le nb de sec. total par le nb de sec par sem.
    iWeek = iSeconde / WEEK;
	// On récupère le nb de sec. restante et on réitère l'opération pour les jours, heures, etc.
    iSeconde = iSeconde % WEEK;
    
    iDay = iSeconde / DAY;
    iSeconde = iSeconde % DAY;
    
    iHour = iSeconde / HOUR;
    iSeconde = iSeconde % HOUR;
    
    iMinute = iSeconde / MINUTE;
    iSeconde = iSeconde % MINUTE;
	
   // Affichage du résultat 
   cout << "\nRésultat : " << iWeek << " semaine(s) " << iDay << " jour(s) " << iHour << " heure(s) " << iMinute << " minute(s) " << iSeconde << " secondes." << "\n";
	
	system("pause");
}