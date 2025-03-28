/*
Graf Calvin
04.10.2022
HEIG-VD | PRG | Labo 8
Le programme lit des coordonées données par l'utilisateur et définit sa transformer.
*/

#include <iostream>
#include <string>

using namespace std;


int main() {

  int x1 = 0;
  int y1 = 0;

  int x2 = 0;
  int y2 = 0;

  int x3 = 0;
  int y3 = 0;

  int x4 = 0;
  int y4 = 0;

  string strReponse = "";

  bool bPerpendiculaire = false;

  int iParallele = 0;
  int iIsometrique = 0;

  cout << "Merci d'entrer les points de votre forme [format : (x,y)(x,y)(x,y)(x,y)] : ";
  cin >> strReponse;

  // On récupère toutes les valeurs transmises par l'utilisateur
  x1 = stoi(strReponse.substr(1));
  y1 = stoi(strReponse.substr(3));

  x2 = stoi(strReponse.substr(6));
  y2 = stoi(strReponse.substr(8));

  x3 = stoi(strReponse.substr(11));
  y3 = stoi(strReponse.substr(13));

  x4 = stoi(strReponse.substr(16));
  y4 = stoi(strReponse.substr(18));

  // On crée les vecteurs à l'aide des points
  int ABx = x2 - x1;
  int ABy = y2 - y1;

  int BCx = x3 - x2;
  int BCy = y3 - y2;

  int CDx = x4 - x3;
  int CDy = y4 - y3;

  int DAx = x1 - x4;
  int DAy = y1 - y4;


  // On vérifie le nombre de parallèles
 if (ABx * CDy == ABy * CDx)
  { iParallele++; }
 if (BCx * DAy == BCy * DAx)
  { iParallele++; }

  // On vérifie qu'il y au moins 1 perpendiculaires
 if (ABx * BCx + ABy * BCy == 0)
  { bPerpendiculaire = true; }

 // On vérifie le nombre d'isométrie
 if (ABx * ABx + ABy * ABy == BCx * BCx + BCy * BCy)
  { iIsometrique++; }
 if (ABx * ABx + ABy * ABy == CDx * CDx + CDy * CDy)
  { iIsometrique++; }
 if (ABx * ABx + ABy * ABy == DAx * DAx + DAy * DAy)
  { iIsometrique++; }
 if (BCx * BCx + BCy * BCy == DAx * DAx + DAy * DAy)
  { iIsometrique++; }

  // On affiche le résultat
  if (iParallele == 1)
   { cout << "Votre forme est un trapeze."; }
  else if (iParallele == 2 && bPerpendiculaire == false && iIsometrique == 2)
   { cout << "Votre forme est un parallelograme."; }
  else if (iIsometrique == 4 && bPerpendiculaire == false)
   { cout << "Votre forme est un losange."; }
  else if (iIsometrique == 2)
   { cout << "Votre forme est un rectangle."; }
  else if (iIsometrique == 4 && bPerpendiculaire == true)
   { cout << "Votre forme est un carre."; }

}
