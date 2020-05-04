#ifndef DEF_LISTE
#define DEF_LISTE

typedef struct Liste Liste;

struct Liste
{
  int total;

  Personne *premier;
  Personne *dernier;

};

Liste *initialisation();
void nombreListe(Liste *uneListe);
int nombreLettresPrenom(char prenom[]);
void ajouter(Liste *uneListe, char prenom[], int age);
void supprimer(Liste *uneListe, char prenom[]);
void depile(Liste *uneListe);
void defile(Liste *uneListe);
void find(Liste *uneListe, char prenom[]);

#endif
