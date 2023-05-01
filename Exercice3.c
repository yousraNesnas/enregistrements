#include <stdio.h>

typedef struct
{
    int heure;
    int minute;
    int seconde;
} TEMPS;

// fonction somme_temps qui prend en entrée deux structures TEMPS (T1 et T2) et retourne une troisième structure TEMPS (T)
void somme_temps(TEMPS T1, TEMPS T2, TEMPS *T)
{
    // Calcul du nombre total de secondes correspondant à la somme des deux temps T1 et T2
    int total_secondes = T1.seconde + T2.seconde + (T1.minute + T2.minute) * 60 + (T1.heure + T2.heure) * 3600;

    // Calcul du nombre d'heures correspondant à la somme totale de secondes et stockage dans le champ heure de la structure T
    T->heure = total_secondes / 3600;

    // Calcul du nombre de minutes restantes après avoir soustrait les heures et stockage dans le champ minute de la structure T
    T->minute = (total_secondes % 3600) / 60;

    // Calcul du nombre de secondes restantes après avoir soustrait les heures et les minutes et stockage dans le champ seconde de la structure T
    T->seconde = total_secondes % 60;
}

// fonction transform qui prend en entrée une structure TEMPS et retourne le nombre total de secondes correspondant à cette structure
int transform(TEMPS T)
{ // Calcul et retourne du nombre total de secondes correspondant à la structure TEMPS T
    return T.seconde + T.minute * 60 + T.heure * 3600;
}
//procedure decompos qui prend en entrée un entier représentant un nombre total de secondes et retourne une structure TEMPS correspondant à ce nombre de secondes
void decompos(int S, TEMPS *T)
{
    T->heure = S / 3600;
    T->minute = (S % 3600) / 60;
    T->seconde = S % 60;
}

int main()
{
    // Exemple d'utilisation des fonctions
    TEMPS T1 = {2, 10, 37};
    TEMPS T2 = {1, 45, 12};
    TEMPS T3;
    somme_temps(T1, T2, &T3);
    printf("Temps 1 : %dh %dmin %dsec\n", T1.heure, T1.minute, T1.seconde);
    printf("Temps 2 : %dh %dmin %dsec\n", T2.heure, T2.minute, T2.seconde);
    printf("Temps total : %dh %dmin %dsec\n\n", T3.heure, T3.minute, T3.seconde);

    int S = transform(T1);
    printf("Temps 1 : %dh %dmin %dsec\n", T1.heure, T1.minute, T1.seconde);
    printf("Temps 1 en secondes : %d secondes\n\n", S);

    TEMPS T4;
    decompos(S, &T4);
    printf("Temps en secondes : %d secondes\n", S);
    printf("Temps décomposé : %dh %dmin %dsec\n", T4.heure, T4.minute, T4.seconde);

    return 0;
}
