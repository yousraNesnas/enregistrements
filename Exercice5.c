#include <stdio.h>
#include <string.h>

typedef struct Date
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct Adresse
{
    int numero;
    char rue[50];
    char ville[20];
    char wilaya[20];
} Adresse;

typedef struct Enseignant
{
    char nom[20];
    char prenom[20];
    Date date_naiss;
    Adresse residence;
    char grade[10];
    int annee_de_recrutement;
} Enseignant;

int main()
{
    int n;
    printf("Combien d'enseignants voulez-vous enregistrer ? ");
    scanf("%d", &n);
    Enseignant T[n];

    // Saisie des enseignants
    printf("Saisie des enseignants :\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnseignant %d :\n", i + 1);
        printf("Nom : ");
        scanf("%s", T[i].nom);
        printf("Prenom : ");
        scanf("%s", T[i].prenom);
        printf("Date de naissance (jj mm aaaa) : ");
        scanf("%d %d %d", &T[i].date_naiss.jour, &T[i].date_naiss.mois, &T[i].date_naiss.annee);
        printf("Adresse :\n");
        printf("Numero : ");
        scanf("%d", &T[i].residence.numero);
        printf("Rue : ");
        scanf("%s", T[i].residence.rue);
        printf("Ville : ");
        scanf("%s", T[i].residence.ville);
        printf("Wilaya : ");
        scanf("%s", T[i].residence.wilaya);
        printf("Grade : ");
        scanf("%s", T[i].grade);
        printf("Annee de recrutement : ");
        scanf("%d", &T[i].annee_de_recrutement);
    }

    // Affichage des enseignants nés avant une date donnée
    printf("\nListe des enseignants nes avant une date donnee :\n");
    Date date_limite;
    printf("Date limite (jj mm aaaa) : ");
    scanf("%d %d %d", &date_limite.jour, &date_limite.mois, &date_limite.annee);
    for (int i = 0; i < n; i++)
    {
        if (T[i].date_naiss.annee < date_limite.annee ||
            (T[i].date_naiss.annee == date_limite.annee && T[i].date_naiss.mois < date_limite.mois) ||
            (T[i].date_naiss.annee == date_limite.annee && T[i].date_naiss.mois == date_limite.mois && T[i].date_naiss.jour < date_limite.jour))
        {
            printf("%s %s, %s, %s %s\n", T[i].nom, T[i].prenom, T[i].residence.rue, T[i].residence.ville, T[i].residence.wilaya);
        }
    }

    // Affichage des enseignants résidents de la ville de 'Boudouaou' de la wilaya de 'Boumerdes'
    printf("\nListe des enseignants residents de Boudouaou, Boumerdes :\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(T[i].residence.wilaya, "Boumerdes") == 0 && strcmp(T[i].residence.ville, "Boudouaou") == 0)
        {
            printf("%s %s\n", T[i].nom, T[i].prenom);
        }
    }

    // Affichage du nombre des enseignants par année de recrutement depuis une année donnée

    int annee, nbr_ens = 0;
    printf("Année de recrutement : ");
    scanf("%d", &annee);
    for (int i = 0; i < n; i++)
    {
        if (T[i].annee_de_recrutement == annee)
        {
            nbr_ens++;
        }
    }

    printf("\nombre des enseignants par année de recrutement est: %d\n", nbr_ens);
}
