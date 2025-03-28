J'ai repris le programme et test (test.cpp) et rajouté la ligne 109 puisque mon LOWER_CASE est un int (ce qui me permet d'ajouter facilement d'autre affichage) ainsi que 132 et 133 pour faire un arrêt du programme.

Pour les opérateurs <<= et << on réutilise le même code (ce qui est évitable) mais puisque celui-ci fait 2 lignes, c'est plus simple ainsi et ça leur permet en plus d'être indépendant l'un de l'autre

J'ai décidé de ne pas faire de classe prime.hpp mais de mettre mes fonctions de primalité dans la classe Uint.

Pour les fichiers .o je n'ai pas compris comment les récupérer puisque nous n'en avons jamais parlé en cours.

J'ai appris le dernier jour que l'on avait pas le droit d'utiliser using namespace et tout ça dans le .hpp, mais pour des raisons de temps je l'ai laisser comme ça.

Le programme s'éxécute en 14 secondes avec la compilation -O5

(J'ai mis le .exe avec au cas où même si y'en a pas besoin normalement