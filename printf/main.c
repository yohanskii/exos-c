#include "libc.h"
#include "main.h"

/***
Recréer la fonction printf:

  - printChar => fonction qui permet d'afficher dans la sortie standard (1) un char
  - printString => fonction qui permet d'afficher des chaines de char grace à l'appel de la fonction printChar
  - printInt => fonction qui permet d'aficher un int grace à printChar

  - myPrintF => fonction variadique

**/
int main(int argc, char *argv[])
{

  myPrintF("j'ai: %d ans, je m'appelle: %s et ma lettre préféree est %c \n", 31, "yoann", 'A');

  return 0;
}

void printChar(char c)
{
  write(1, &c,1);
}

void printString(char string[])
{
  int i = 0;
  while(string[i])
  {
    printChar(string[i]);
    i++;
  }
}

void printInt(int unChiffre)
{
  if(unChiffre < 0)
  {
    printChar('-');
    unChiffre *= (-1);
  }

  if(unChiffre >= 10)
  {
    printInt(unChiffre / 10);
    printInt(unChiffre % 10);

  }else{
    printChar('0' + unChiffre);
  }

}

void myPrintF(char chaine[], ...)
{
  va_list ap;

  va_start(ap, chaine);


  int i = 0;

  do{
    if(chaine[i] == '%')
    {
      switch (chaine[i+1]) {
        case 'd':
          printInt((int) va_arg(ap, int));
          i += 2;
          break;
        case 'c':
          printChar((int) va_arg(ap, int));
          i += 2;
          break;
        case 's':
          printString((char*) va_arg(ap, char*));
          i += 2;
          break;
      }
    }
    printChar(chaine[i]);
    i++;
  }while(chaine[i] != '\0');

  va_end(ap);
}
