#ifndef DEF_PERSONNE
#define DEF_PERSONNE

typedef struct Personne Personne;

struct Personne
{
  char prenom[100];
  int age;

  Personne *suivant;
  Personne *precedant;
};


#endif
