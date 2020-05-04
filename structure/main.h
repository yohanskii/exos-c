typedef struct Personne Personne;
typedef enum Bool Bool;

struct Personne
{
  int age;
  char prenom[100];

};

enum Bool{
  FALSE = 0, TRUE = 1
};

//prototypes
void initPersonne(Personne *ptrPers);
void askPersonne(Personne *ptrPers);
void lecture(Personne tabPers[],int sizeTab);
void sendInit(Personne tabPers[],int sizeTab);
void sendAsk(Personne tabPers[],int sizeTab);
void send(Personne tabPers[], int sizeTab, void (*ptrFn)(Personne *ptrPersonne));
void lancement(int *ptrNbPersonne);
