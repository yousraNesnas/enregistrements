#include <stdio.h>

// Définition d'une structure pour représenter un nombre complexe
typedef struct complexe
{
    float re; // partie réelle
    float im; // partie imaginaire
} complexe;

// Fonction pour saisir un nombre complexe
void saisi(complexe *z)
{
    printf("Entrez la partie réelle de z: ");
    scanf("%f", &z->re);
    printf("Entrez la partie imaginaire de z: ");
    scanf("%f", &z->im);
}

// Fonction pour afficher un nombre complexe
void affiche(complexe z)
{
    printf("%.2f + %.2fi", z.re, z.im);
}

// Fonction pour calculer la somme de deux nombres complexes
void addition(complexe z1, complexe z2)
{
    complexe somme;
    somme.re = z1.re + z2.re;
    somme.im = z1.im + z2.im;
    printf("La somme de ");
    affiche(z1);
    printf(" et ");
    affiche(z2);
    printf(" est : ");
    affiche(somme);
}

// Fonction pour calculer le produit de deux nombres complexes
void produit(complexe z1, complexe z2)
{
    complexe prod;
    prod.re = z1.re * z2.re - z1.im * z2.im;
    prod.im = z1.re * z2.im + z1.im * z2.re;
    printf("Le produit de ");
    affiche(z1);
    printf(" et ");
    affiche(z2);
    printf(" est : ");
    affiche(prod);
}

int main()
{
    complexe z1, z2;
    printf("Entrez le premier nombre complexe:\n");
    saisi(&z1);
    printf("Entrez le deuxième nombre complexe:\n");
    saisi(&z2);
    addition(z1, z2);
    produit(z1, z2);
    return 0;
}
