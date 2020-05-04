#include <stdlib.h>
#include <stdio.h>

//proto
void readTab(int tab[], int sizeTab);
void swap(int *a, int *b);
void triTabCroissant(int tab[], int sizeTab);
void triTabDecroissant(int tab[], int sizeTab);
void tri(int tab[], int sizeTab, char unChar);
void triFunc(int tab[], int sizeTab, char unChar);
/**
Trions ce tableau dans un ordre croissant et décroissant;

1 - fonction readTab => Lecture d'un tableau
2 - fonction triTabCroissant => ordre croissant
3 - fonction triTabDecroissant => ordre decroissant
4 - une seule méthode de trie avec char C croissant D decroissant
  -tri => qui reutilise les fonctions triTabCroissant et triTabDecroissant
  -triFunc ()

*/

int main(int argc, char *argv[])
{
  int myTab[10] = { 3, 19, 22, 18, 21, 7, 9,8, 10, 12};
  readTab(myTab, 10);
  triTabCroissant(myTab, 10);
  readTab(myTab, 10);
  triTabDecroissant(myTab, 10);
  readTab(myTab, 10);
  tri(myTab,10,'D');
  readTab(myTab, 10);
  triFunc(myTab, 10, 'c');
  readTab(myTab, 10);
  return 0;
}

void readTab(int tab[], int sizeTab)
{
  //do while
  printf("Lecture du tab\n");

  int i = 0;

  do {

    printf("case %d : %d \n",i, tab[i]);
    i++;
  } while(i < sizeTab);
}

void swap(int *a, int *b)
{
  int temp = *a;
  //printf("%d\n",temp );
  *a = *b;
  *b = temp;

}

void triTabCroissant(int tab[], int sizeTab)
{
  //boucle for

  //ordre croissant
  //(i + 1) < sizeTab car on ne veut pas comparer le dernier nombre entier avec une case du tableau qui n'existe pas.
  for(int i = 0; (i + 1) < sizeTab; i++)
  {
    if(tab[i] > tab[i+1])
    {
      //permutation des valeurss
      swap(&tab[i], &tab[i+1]);

      //i = -1 car quand i sort il s'incrémente de 1 ===> -1 + 1 == 0;
      i = -1;


    }
  }
}


void triTabDecroissant(int tab[], int sizeTab)
{
  //while

  // ordre décroissant
  int i = 0;
  //(i + 1) < sizeTab car on ne veut pas comparer le dernier nombre entier avec une case du tableau qui n'existe pas.
  while((i + 1) < sizeTab)
  {
      if(tab[i] < tab[i + 1])
      {
        //permutation des valeurs
        swap(&tab[i], &tab[i+1]);
        //i = -1 car quand i sort il s'incrémente de 1 ===> -1 + 1 == 0;
        i = -1;
      }
      i++;
  }

}

void tri(int tab[], int sizeTab, char unChar)
{
  switch (unChar) {
    case 'C': triTabCroissant(tab, sizeTab);
      break;
    case 'D': triTabDecroissant(tab, sizeTab);
      break;
    default:
      printf("vous devez renseigner un char 'D' ou 'C'\n");
  }
}


void triFunc(int tab[], int sizeTab, char unChar)
{

  if (tab == NULL || sizeTab <= 0 || (unChar != 'D' && unChar != 'C')) {
    exit(EXIT_FAILURE);
  }


  for(int i = 0; i + 1 < sizeTab; i++)
  {
    if(unChar == 'C' && tab[i] > tab[i+1])
    {
      //permutation des valeurs
      swap(&tab[i], &tab[i+1]);
      //i = -1 car quand i sort il s'incrémente de 1 ===> -1 + 1 == 0;
      i = -1;
    }

    if(unChar == 'D' && tab[i] < tab[i+1])
    {
      //permutation des valeurs
      swap(&tab[i], &tab[i+1]);
      //i = -1 car quand i sort il s'incrémente de 1 ===> -1 + 1 == 0;
      i = -1;
    }


  }
}
