#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char nom[20], prenom[20];
    bool dejeuner, diner, seul;
    int hotel;
} Participant;

void liste2Etoiles(Participant T[], int n);
int NbDej(Participant T[], int n);
void Montant(Participant p);
int main()
{
    int n;
    printf("Combien de participant voulez-vous enregistrer ? ");
    scanf("%d", &n);
    Participant TabPart[n];

    // Saisie des Participant
    printf("Saisie des Participant :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Participant %d :\n", i + 1);
        printf("Nom : ");
        scanf("%s", TabPart[i].nom);
        printf("Prenom : ");
        scanf("%s", TabPart[i].prenom);
        printf("Dejeuner : ");
        scanf("%d", &TabPart[i].dejeuner);
        printf("Numero : ");
        scanf("%d", &TabPart[i].diner);
        printf("Hotel : ");
        scanf("%d", TabPart[i].hotel);
        printf("Seul : ");
        scanf("%d", TabPart[i].seul);
    }

    // Affichage des participants avec hotel 2 etoiles
    printf("\nListe des participants qui ont réservés un hotel 2 étoiles :\n");
    liste2Etoiles(TabPart, n);

    // le nombre de partipants qui ont reservé pour le dejeuner
    int nbr_dej = NbDej(TabPart, n);
    printf("\nLe nombre de partipants qui ont reservé pour le dejeuner est : %d\n", nbr_dej);

    // le montant des participants
    printf("\nLmontant des participants");

    for (int i = 0; i < n; i++)
    {
        Montant(TabPart[i]);
    }
}

void liste2Etoiles(Participant T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (T[i].hotel == 2)
        {
            printf("%s %s\n", T[i].nom, T[i].prenom);
        }
    }
}

int NbDej(Participant T[], int n)
{
    int nbr_dej = 0;
    for (int i = 0; i < n; i++)
    {
        if (T[i].dejeuner)
        {
            nbr_dej++;
        }
    }

    return nbr_dej;
}

void Montant(Participant p)
{
    int montant = 0;
    if (p.dejeuner)
    {
        montant += 1500;
        if (!p.seul)
        {
            montant += 1500;
        }
    }
    if (p.diner)
    {
        montant += 3500;
        if (!p.seul)
        {
            montant += 3500;
        }
    }
    if (p.hotel == 2)
    {
        montant += 7500;
        if (!p.seul)
        {
            montant += 7500;
        }
    }
    else if (p.hotel == 3)
    {
        montant += 10000;
        if (!p.seul)
        {
            montant += 10000;
        }
    }

    printf("Le montant de %s %s est : %d\n", p.nom, p.prenom, montant);
}