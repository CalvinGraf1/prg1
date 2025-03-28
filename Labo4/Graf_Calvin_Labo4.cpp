/* By Calvin Graf
21.09.2022
HEIG-VD | PRG - Labo 4
 */
 
 #include <iostream>
 #include <string>
 using namespace std;
 
 	 const int iTransformationHundred = 100;
 	 const int iTransformationThousand = 1000;
	 const int iTransformationTen = 10;
 	  	 
 int main() {
	 
	 int iKm1, iM1, iCm1, iMm1;
	 int iKm2, iM2, iCm2, iMm2;
	 
	 int iKmTot, iMTot, iCmTot, iMmTot;
	 
	 cout << "Bonjour, merci d'entrer le nombre de kilomètre(s), mètre(s), centièmère(s) et millimètre(s) : ";
	 cin >> iKm1 >> iM1 >> iCm1 >> iMm1;
	 
    cout << "Merci d'entrer la deuxième valeur pour le nombre de kilomètre(s), mètre(s), centièmère(s) et millimètre(s) : ";
	 cin >> iKm2 >> iM2 >> iCm2 >> iMm2;
	 
	 iCmTot = (iCm1 + iCm2) + (iMm1 + iMm2) / iTransformationTen;
	 iMmTot = (iMm1 + iMm2) % iTransformationTen;
	 
	 iMTot = (iM1 + iM2) + (iCm1 + iCm2) / iTransformationHundred;
	 iCmTot = iCmTot % iTransformationHundred;
	 
	 iKmTot = (iKm1 + iKm2) + (iM1 + iM2) / iTransformationThousand;
	 iMTot = iMTot % iTransformationThousand;
	 
	 
	 cout << iKm1 << "km, " << iM1 << "m, " << iCm1 << "cm, " << iMm1 << "mm + "
	 << iKm2 << "km, " << iM2 << "m, " << iCm2 << "cm, " << iMm2 << "mm font : " << iKmTot << "km, " << iMTot << "m, " << iCmTot << "cm, " << iMmTot << "mm";
 }