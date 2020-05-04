#include "libc.h"

/****

Nous avons 2 structures:
  - Personne qui represente une personne (prenom, age, pointeur sur personne suivante, pointeur sur personne precedante)
  - Liste qui permet d'accéder au 1er et au dernier

Nous avons plusieurs méthodes:
  - initialisation() => qui permet d'initialiser une Liste
  - ajouter => pour ajouter une personne
  - supprimer => pour supprimer une personne de la liste A FAIRE TODO
  - find => vérifier que la personne existe
  - nombreListe => le nombre total de personnes dans la liste
  - lecture =>
    - depile => LIFO
    - défile => FIFO

**/


int main(int agrc, char *agrv[])
{
  Liste *uneListe = initialisation();

  ajouter(uneListe, "yoann", 31);
  ajouter(uneListe, "john", 30);
  ajouter(uneListe, "bob", 28);
  ajouter(uneListe, "mike", 29);
  depile(uneListe);
  nombreListe(uneListe);
  find(uneListe, "john");
  defile(uneListe);
  supprimer(uneListe, "bob");
  nombreListe(uneListe);
  defile(uneListe);
  depile(uneListe);



  return 0;
}
