#include "libc.h"
#include "main.h"

/****
main.h
  - création d'une structure Personne
  - prototypes

main.c
  1 - tableau de structure Personne (taille variable )
  2 - pointeurs sur fonction
  3 - inittialisation du tab
  4 - demande data set pour tab Personne;
  5 - création d'une focntion init qui prend en paramtre une autre fonction => HOC (react js)

***/
int main(int argc, char *argv[])
{
  //On peut initialiser de plusieurs façons:
  //Personne tabJoueur[2] = {{0,""}, {0, ""}};

  int size = 0;
  Personne *tabJoueur = NULL;

  lancement(&size);

  if(size <= 0 )
  {
    exit(0);
  }

  //1 - tableau de structure Personne
  tabJoueur = malloc(size * sizeof(Personne));
  if(tabJoueur == NULL)
  {
    exit(0);
  }

  //2 - pointeurs sur fonction
  void (*ptrFnInit)(Personne *ptrPersonne) = &initPersonne;
  void (*ptrFnAsk)(Personne *ptrPersonne) = &askPersonne;

  //lecture du tab avant initialisation
  lecture(tabJoueur, size);

  //3 - inittialisation du tab
  send(tabJoueur, size,ptrFnInit);
  //sendInit(tabJoueur, 2);

  lecture(tabJoueur, size);
  //4 - demande data set pour tab Personne;
  send(tabJoueur, size,ptrFnAsk);
  //sendAsk(tabJoueur, 2);

  lecture(tabJoueur, size);

  free(tabJoueur);
  return 0;
}
void lancement(int *ptrNbPersonne)
{
  printf("Combien de joueurs svp\n");
  scanf("%d",&*ptrNbPersonne);
}

void send(Personne tabPers[], int sizeTab, void (*ptrFn)(Personne *ptrPersonne))
{
  for(int i = 0; i < sizeTab; i++)
  {
    Personne *ptrPers = &tabPers[i];
    (*ptrFn)(ptrPers);
  }
}
void sendInit(Personne tabPers[],int sizeTab)
{
  for(int i = 0; i < sizeTab; i++)
  {
    Personne *ptrPers = &tabPers[i];
    initPersonne(ptrPers);
  }
}

void sendAsk(Personne tabPers[],int sizeTab)
{
  for(int i = 0; i < sizeTab; i++)
  {
    Personne *ptrPers = &tabPers[i];
    askPersonne(ptrPers);
  }
}

void lecture(Personne tabPers[],int sizeTab)
{
  for(int i = 0; i < sizeTab; i++)
  {
    printf("%s vous avez: %d ans\n",tabPers[i].prenom, tabPers[i].age);
  }
}

void initPersonne(Personne *ptrPers)
{
  (*ptrPers).age = 0;
  for(int i = 0; i < 10; i++)
  {
    ptrPers->prenom[i] = 0;
  }

}

void askPersonne(Personne *ptrPers)
{
  printf("Quel est votre prenom\n");
  scanf("%s",ptrPers->prenom);

  printf("Quel est votre age %s\n", ptrPers->prenom);
  scanf("%d",&ptrPers->age);

}
