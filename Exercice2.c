#include <stdio.h>

#define MAX_ETUDIANTS 100

struct Etudiant
{
    char id[10];
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
    char resultat[4];
};

int main()
{
    struct Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiants, i;
    float sommeMoyennes = 0, moyenneGenerale = 0;

    // Saisie des informations concernant les étudiants
    printf("Combien d'etudiants voulez-vous saisir ? ");
    scanf("%d", &nbEtudiants);

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

        // Calcul du résultat (ADM ou AJN)
        if (etudiants[i].moyenne >= 10)
        {
            sprintf(etudiants[i].resultat, "%s", "ADM");
        }
        else
        {
            sprintf(etudiants[i].resultat, "%s", "AJN");
        }

        // Calcul de la moyenne générale
        sommeMoyennes += etudiants[i].moyenne;
    }

    // Affichage des informations et du résultat pour chaque étudiant
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
        printf("-----------------------------------------\n");
    }

    // Affichage de la moyenne générale
    moyenneGenerale = sommeMoyennes / nbEtudiants;
    printf("\nMoyenne generale : %.2f\n", moyenneGenerale);

    return 0;
}
