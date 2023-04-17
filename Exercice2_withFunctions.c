#include <stdio.h>

#define MAX_ETUDIANTS 100
// l'utilisation d'une énumération pour les résultats ADM et AJN
/**
 enum Resultat {
    AJN, ADM
};
*/
struct Etudiant
{
    char id[10];
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
    char resultat[4];
    //  enum Resultat resultat;
};

void saisirEtudiants(struct Etudiant etudiants[], int nbEtudiants)
{
    int i;

    for (i = 0; i < nbEtudiants; i++)
    {
        printf("\nEtudiant n°%d\n", i + 1);

        printf("Identifiant : ");
        scanf("%s", etudiants[i].id);

        printf("Nom : ");
        scanf("%s", etudiants[i].nom);

        printf("Prenom : ");
        scanf("%s", etudiants[i].prenom);

        printf("Age : ");
        scanf("%d", &etudiants[i].age);

        printf("Moyenne : ");
        scanf("%f", &etudiants[i].moyenne);
    }
}

void calculerResultats(struct Etudiant etudiants[], int nbEtudiants)
{
    int i;

    for (i = 0; i < nbEtudiants; i++)
    {
        if (etudiants[i].moyenne >= 10)
        {
            sprintf(etudiants[i].resultat, "%s", "ADM");
        }
        else
        {
            sprintf(etudiants[i].resultat, "%s", "AJN");
        }
    }

    // Avec l'utilisation des enum

    /**
     *  for (i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].moyenne >= 10) {
            etudiants[i].resultat = ADM;
        } else {
            etudiants[i].resultat = AJN;
        }
    }
    */
}

void afficherEtudiants(struct Etudiant etudiants[], int nbEtudiants)
{
    int i;

    printf("\n-----------------------------------------\n");
    for (i = 0; i < nbEtudiants; i++)
    {
        printf("\nEtudiant n°%d\n", i + 1);
        printf("Identifiant : %s\n", etudiants[i].id);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Age : %d\n", etudiants[i].age);
        printf("Moyenne : %.2f\n", etudiants[i].moyenne);
        printf("Resultat : %s\n", etudiants[i].resultat);
        //  printf("Resultat : %s\n", etudiants[i].resultat == ADM ? "ADM" : "AJN");
        printf("-----------------------------------------\n");
    }
}

float calculerMoyenneGenerale(struct Etudiant etudiants[], int nbEtudiants)
{
    int i;
    float sommeMoyennes = 0, moyenneGenerale = 0;

    for (i = 0; i < nbEtudiants; i++)
    {
        sommeMoyennes += etudiants[i].moyenne;
    }

    moyenneGenerale = sommeMoyennes / nbEtudiants;
    return moyenneGenerale;
}

int main()
{
    struct Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiants;
    float moyenneGenerale;

    // Saisie des informations concernant les étudiants
    printf("Combien d'etudiants voulez-vous saisir ? ");
    scanf("%d", &nbEtudiants);
    saisirEtudiants(etudiants, nbEtudiants);

    // Calcul des résultats pour chaque étudiant
    calculerResultats(etudiants, nbEtudiants);

    // Affichage des informations pour chaque étudiant
    afficherEtudiants(etudiants, nbEtudiants);

    // Calcul de la moyenne générale des étudiants
    moyenneGenerale = calculerMoyenneGenerale(etudiants, nbEtudiants);
    printf("\nMoyenne generale des etudiants : %.2f\n", moyenneGenerale);

    return 0;
}