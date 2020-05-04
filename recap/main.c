#include <stdlib.h>
#include <stdio.h>

//prototypes
void readTab(int unTab[], int sizeTab);
int triple( int entier);
void tripleVariableInMemory(int *entier);
void tripleTab(int unTab[], int sizeTab);
void trierTab(int tab[], int sizeTab);
void swap(int *valA, int *valB);

/*

Recap:

1 - instancier des variables et tableau de variables
2 - adresse de ces variables
3 - taille de ces variables en mémoire
4 - Cast de variable
5 - Ternaire
6 - pointeur sur variables
7 - fonction triple
    a - return int
    b - void => modification de la variable grâce à un pointeur.
8 - fonction lecture valeur tableau
9 - fonction triple tableau
10 - fonction tri tableau ordre croissant
11 - permutation des valeurs d'une variable

*/

int main(int agrc, char *argv[])
{
  //1 - instancier des variables et tableau de variables

  int age = 0;
  int myTab[10] = { 10, 22, 1, 3, 9, 8, 10, 8, 7, 31};
  int autreEntier = 31;

  //4 - Cast de variable
  float castFloat;

  //6 - pointeur sur variables
  int *pAge = &age;


  //1 - instancier des variables et tableau de variables
  printf("quel est votre age \n");
  scanf("%d", &age);
  printf("Vous avez %d\n", age);

  //2 - adresse de ces variables
  printf("L adresse de la variable age est %p \n", &age);
  printf("L adresse de la variable myTab est %p \n", myTab);

  //3 - taille de ces variables en mémoire
  printf("La taille de la variable age est %lu \n", sizeof(age));
  printf("La taille de la variable myTab est %lu \n", sizeof(myTab));

  //4 - Cast de variable
  castFloat = (float) age * 0.33;
  printf("Voici la valeur de la valeur castée %f\n", castFloat );


  //7 - fonction triple
      //a - return int
  printf("voici l age triplé %d\n",triple(age));
  printf("Vous avez %d\n", age);

  //5 - Ternaire
  (age < 30 ) ? printf("vous avez moins de 30\n") : printf("vous avez plus de 30\n");

  //7 - fonction triple
      //b - void => modification de la variable grâce à un pointeur.
  tripleVariableInMemory(pAge);

  printf("voici l age triplé %d\n", age);
  printf("Vous avez %d\n", age);

  //5 - Ternaire
  (age < 30 ) ? printf("vous avez moins de 30\n") : printf("vous avez plus de 30\n");

  //8 - fonction lecture valeur tableau
  readTab(myTab, 10);

  //9 - fonction triple tableau
  tripleTab(myTab, 10);

  //8 - fonction lecture valeur tableau
  readTab(myTab, 10);

  //10 - fonction tri tableau ordre croissant
  trierTab(myTab, 10);

  //8 - fonction lecture valeur tableau
  readTab(myTab, 10);



  //11 - permutation des valeurs d'une variable
  printf("Voici la valeur de la variable age %d \n", *pAge);
  printf("Voici la valeur de la variable autreEntier %d\n",autreEntier);
  swap(pAge, &autreEntier);
  printf("Apres swap\n");
  printf("Voici la valeur de la variable age %d \n", *pAge);
  printf("Voici la valeur de la variable autreEntier %d\n",autreEntier);


  return 0;
}

int triple( int entier)
{
  return entier * 3;
}

void tripleVariableInMemory(int *entier)
{
  *entier *= 3;
}

void readTab(int unTab[], int sizeTab)
{
  printf("Début lecture Tab\n");
  for(int i = 0; i < sizeTab; i++)
  {
    printf("%d\n", unTab[i]);
  }

}

void tripleTab(int unTab[], int sizeTab)
{

  for(int i = 0; i < sizeTab; i++)
  {
    unTab[i] *= 3;
  }

}

void trierTab(int tab[], int sizeTab)
{
  //ordre croissant//

  //
  for(int i = 0; (i + 1) < sizeTab; i++)
  {
    if(tab[i] > tab[i + 1])
    {
      int temp = tab[i];
      tab[i] = tab[i + 1];
      tab[i + 1] = temp;

      //i = -1 car en sortant, il va s'incrémanter de 1 et donc basculer à 0;
      i = -1;
    }
  }
}

void swap(int *valA, int *valB)
{
  int temp = *valA;
  *valA = *valB;
  *valB = temp;
}
