#include "liste.h"

Liste *initialisation()
{
  Liste *uneListe = malloc(sizeof(Liste));
  //on doit vérifer != NULL
  if(uneListe == NULL)
  {
    exit(EXIT_FAILURE);
  }
  uneListe->total = 0;
  uneListe->premier = NULL;
  uneListe->dernier = NULL;

  return uneListe;
}

void nombreListe(Liste *uneListe)
{
  printf("La liste compte %d Personnes\n",uneListe->total);
}

int nombreLettresPrenom(char prenom[])
{

  int i = 0;
  while (prenom[i] != '\0') {

    i++;
  }
  //printf("%s taille : %d\n", prenom, i);
  return i;
}

void ajouter(Liste *uneListe, char prenom[], int age)
{
  Personne *unePersonne = malloc(sizeof(Personne));
  //on doit vérifer != NULL
  if(unePersonne == NULL)
  {
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while (prenom[i] != '\0') {
    unePersonne->prenom[i] = prenom[i];
    i++;
  }
  unePersonne->age = age;


  unePersonne->suivant = uneListe->premier;
  unePersonne->precedant = NULL;

  if(uneListe->premier != NULL)
  {
    uneListe->premier->precedant = unePersonne;
  }

  if(uneListe->premier == NULL)
  {
    uneListe->dernier = unePersonne;
  }

  uneListe->total += 1;
  uneListe->premier = unePersonne;

}

void supprimer(Liste *uneListe, char prenom[])
{

  //on vérifie que la liste n'est pas vide;
  if(uneListe->total <= 0)
  {
    exit(EXIT_FAILURE);
  }



  Personne *ptrPersoFirst = uneListe->premier;
  while(ptrPersoFirst != NULL)
  {


    if(nombreLettresPrenom(prenom) != nombreLettresPrenom(ptrPersoFirst->prenom))
    {
      ptrPersoFirst = ptrPersoFirst->suivant;
      continue;

    }

    for(int i = 0; i < nombreLettresPrenom(prenom); i++)
    {

      if(prenom[i] != ptrPersoFirst->prenom[i])
      {
        break;
      }

      if((i+1 == nombreLettresPrenom(prenom)))
      {
        printf("%s existe, nous allons le supprimer\n",ptrPersoFirst->prenom);
        //printf("%s devant %s\n",ptrPersoFirst->suivant->prenom, ptrPersoFirst->prenom);
        //printf("%s apres %s\n",ptrPersoFirst->precedant->prenom, ptrPersoFirst->prenom);

        Personne *toDelete = ptrPersoFirst;

        ptrPersoFirst->precedant->suivant = ptrPersoFirst->suivant;
        ptrPersoFirst->suivant->precedant = ptrPersoFirst->precedant;
        uneListe->total--;
        free(toDelete);
      }
    }

    ptrPersoFirst = ptrPersoFirst->suivant;
  }
  free(ptrPersoFirst);

}

void depile(Liste *uneListe)
{
  printf("dépile =====> LIFO\n");
  int chiffre = uneListe->total;

  Personne *ptrPersoFirst = uneListe->premier;

  while (ptrPersoFirst != NULL) {
    /* code */
    printf("%s a %d ans. en position %d et celui qui me precede est %s, celui me suit est %s\n",
      ptrPersoFirst->prenom, ptrPersoFirst->age,
      chiffre-1,
      ptrPersoFirst->precedant->prenom,
      ptrPersoFirst->suivant->prenom
    );
    ptrPersoFirst = ptrPersoFirst->suivant;
    chiffre--;
  }

  free(ptrPersoFirst);
}

void defile(Liste *uneListe)
{
  printf("defile =====> FIFO\n");

  if(uneListe == NULL)
  {
    exit(EXIT_FAILURE);
  }
  int chiffre = uneListe->total;

  Personne *ptrPersoFirst = uneListe->dernier;

  while (ptrPersoFirst != NULL) {
    /* code */
    printf("%s a %d ans. en position %d et celui qui me precede est %s, celui me suit est %s\n",
      ptrPersoFirst->prenom, ptrPersoFirst->age,
      chiffre-1,
      ptrPersoFirst->precedant->prenom,
      ptrPersoFirst->suivant->prenom
    );
    ptrPersoFirst = ptrPersoFirst->precedant;
    chiffre--;
  }

  free(ptrPersoFirst);

}


void find(Liste *uneListe, char prenom[])
{
  if(uneListe == NULL)
  {
    exit(EXIT_FAILURE);
  }

  if(nombreLettresPrenom(prenom) == 0)
  {
    exit(EXIT_FAILURE);
  }

  Personne *ptrPersoFirst = uneListe->premier;

  while (ptrPersoFirst != NULL)
  {

    int nbChars = nombreLettresPrenom(prenom);

    if(nombreLettresPrenom(ptrPersoFirst->prenom) == nbChars)
    {
      //printf("ce prenom à la meme taille %s\n",uneListe->premier->prenom);

      for(int i = 0; i < nbChars; i++)
      {
        if(ptrPersoFirst->prenom[i] != prenom[i])
        {
           //printf("ce prenom n existe pas %s\n",ptrPersoFirst->prenom);
           break;
        }

        if((i + 1 )== nbChars )
        {
          printf("ce prenom existe %s\n",ptrPersoFirst->prenom);
        }
      }
    }

    ptrPersoFirst = ptrPersoFirst->suivant;
  }
  free(ptrPersoFirst);


}
