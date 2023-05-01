#include <stdio.h>
#include <stdlib.h> // This header file contains the abs() function

struct TEMPS
{
    int heures;
    int minutes;
    int secondes;
};

struct TEMPS lecture()
{
    struct TEMPS t;
    printf("Donnez les heures : ");
    scanf("%d", &t.heures);
    printf("Donnez les minutes : ");
    scanf("%d", &t.minutes);
    printf("Donnez les secondes : ");
    scanf("%d", &t.secondes);
    return t;
}

void affiche(struct TEMPS t)
{
    printf("%d:%d:%d\n", t.heures, t.minutes, t.secondes);
}

struct TEMPS decompos(int s)
{
    struct TEMPS t;
    t.heures = s / 3600;
    t.minutes = (s % 3600) / 60;
    t.secondes = s % 60;
    return t;
}

void diff(struct TEMPS start, struct TEMPS end, struct TEMPS *result)
{
    int total_secondes = 0;

    int s_start = start.heures * 3600 + start.minutes * 60 + start.secondes;
    int s_end = end.heures * 3600 + end.minutes * 60 + end.secondes;
    // Calcul de la différence en secondes entre le temps de début et le temps de fin en prenant la valeur absolue pour éviter les résultats négatifs
    int s_diff = abs(s_end - s_start);
    // Gestion des cas où le temps de fin est antérieur au temps de début
    if (s_diff < 0)
    {
        s_diff += 24 * 3600;
    }
    *result = decompos(s_diff);
}

int main()
{
    struct TEMPS t1, t2, diff_t;
    printf("Donnez le premier temps\n");
    t1 = lecture();
    printf("%d:%d:%d\n", t1.heures, t1.minutes, t1.secondes);
    printf("Donnez le deuxieme temps\n");
    t2 = lecture();
    printf("%d:%d:%d\n", t2.heures, t2.minutes, t2.secondes);
    diff(t1, t2, &diff_t);
    printf("Difference entre les deux temps ");
    affiche(diff_t);
    printf("Difference en secondes : %d\n", diff_t.heures * 3600 + diff_t.minutes * 60 + diff_t.secondes);
    return 0;
}
