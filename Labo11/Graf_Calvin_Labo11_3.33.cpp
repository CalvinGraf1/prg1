/*
Calvin Graf
HEIG-VD | PRG | Labo 11
Le jeu des 3 portes
*/

#include <iostream>
#include <random>
#include <functional>

using namespace std;

auto gen_int1_3 = bind(uniform_int_distribution<int>(1,3), mt19937(987)); // un autre germe


int main()
{
    int choixUtilisateur;
    int aleatoire;
    int porteOuverte;

    srand((unsigned) time(NULL));
    int porteLot = rand() % 3 + 1;

    char changementChoix;

    cout << "Veuillez choisir entre la porte 1, 2 et 3 : ";
    cin >> choixUtilisateur;

// On récupère la valeur de la porte à ouvrir
aleatoire = rand() % 3 + 1;
while (aleatoire == porteLot || aleatoire == choixUtilisateur) {
    aleatoire = rand() % 3 + 1;
}

porteOuverte = aleatoire;
cout << "La porte " << porteOuverte << " a ete ouverte et elle ne contient rien !" << endl << endl;

cout << "Voulez-vous modifier votre choix (O/N/A) ? " << endl;
    cin >> changementChoix;

// On vérifie le choix de l'utilisateur et le modifie au besoin
if (changementChoix == 'A') {
  choixUtilisateur = porteOuverte;
  while (choixUtilisateur == porteOuverte) {
    choixUtilisateur = rand() % 3 + 1;
  }
}
else if (changementChoix == 'O')
{
  int verification = choixUtilisateur;
  while (choixUtilisateur == porteOuverte || choixUtilisateur == verification) {
    choixUtilisateur = rand() % 3 + 1;
  }
}

// Annonce du résultat
if (choixUtilisateur == porteLot) {
  cout << "Felicitation ! Vous avez gagne !";
}
else
{
  cout << "Malheureusement tu as choisi la mauvaise porte. Le bon choix etait la porte " << porteLot << ".";
}
}















/*

int main()
{

  int porteporteLot = 0;
  int porteOuverte = 0;
  int dernierePorte = 0;
  int choixUtilisateur = 0;
  char changementPorte;

srand((unsigned) time (NULL));
porteporteLot = rand() % 3 + 1; // On ajoute 1 pour avoir les porte 1-2-3 et non 0-1-2
cout << porteporteLot;

cout << "Veuillez choisir la porte 1, 2 ou 3 : ";
cin >> choixUtilisateur;


// if bonne porte -> ouverture aléatoire d'une porte
    // demadner é l'utilisateur de changer
      // changer porte

      // ne pas changer porte$

while (porteOuverte = 0 || porteOuverte == choixUtilisateur || porteOuverte == porteporteLot)
{
  porteOuverte = rand() % 3 + 1;
}
porteOuverte = 6 - choixUtilisateur - porteporteLot;
cout << "La porte " << porteOuverte << " a ete ouverte et est vide !" << endl;
cout << "Voulez-vous modifier le choix votre porte ? (O = oui, N = non, A = aleatoire)" << endl;
cin >> changementPorte;

if (changementPorte == 'O') {
  choixUtilisateur = 6 - porteOuverte - porteporteLot; // Va récupérer la dernière porte disponible
  cout << "Ton choix se porte desormais sur la porte" << choixUtilisateur << "." << endl;
}
else if (changementPorte == 'A')
{
  choixUtilisateur = porteOuverte;
  while (choixUtilisateur == porteOuverte)
  { choixUtilisateur = rand() % 3 + 1; }
}

if (choixUtilisateur == porteporteLot) {
  cout << "C'est gagne ! Felicitation a toi !";
}
else
{ cout << "Malheureusement le porteLot etait derrière la porte " << porteporteLot << ". Tu feras mieux la prochaine fois !"; }

/*
if (choixUtilisateur == porteporteLot) {

}
else
{
  porteOuverte = choixUtilisateur;
  while (porteOuverte == choixUtilisateur)
  {
    porteOuverte = rand() % 2 + 1; // On ajoute 1 pour avoir les porte 1-2-3 et non 0-1-2
  }
  cout << "La porte " << porteOuverte << " a ete ouverte et ne contient aucun porteLot.";
  }
  else
  {

    while (dernierePorte == porteporteLot || dernierePorte == choixUtilisateur || dernierePorte == 0) {
      dernierePorte = rand() % 2 + 1;
    }
  }
  cout << "Il ne vous reste plus que la porte : " << dernierePorte << "." << endl;
  cout << "Voulez-vous changez de porte ? (O = oui, N = non, A = aleatoire)" << endl;
  cin >> changementPorte;

  if (changementPorte == 'A') {
    choixUtilisateur = porteOuverte;
    while (choixUtilisateur == porteOuverte) {
      changementPorte = rand() % 3 + 1;
    }
  }
  else if (changementPorte == 'O')
  {     int verification = choixUtilisateur;
      while (changementPorte == verification)
      { changementPorte = rand() % 3 + 1; }
  }
}
*/
