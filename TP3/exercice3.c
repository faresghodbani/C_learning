#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *notes;   /* pointeur vers le tableau de notes */
    int taille;   /* taille du tableau alloué en mémoire */
    int n;        /* nombre de notes réellement utilisées */
} bulletin;

bulletin nouveau(int taille) {
    bulletin b;              /* créer un bulletin */
    b.taille = taille;       /* taille du tableau */
    b.n = 0;                 /* aucune note pour l'instant */

    /* allocation dynamique du tableau de notes */
    b.notes = (int *)malloc(taille * sizeof(int));
    if (b.notes == NULL) {   /* vérifier l'allocation */
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    return b;
}

void liberer_memoire(bulletin b) {
    free(b.notes);
}

int ajout_simple(bulletin *b, int note) {
    /* Vérifier que la note est valide */
    if (note < 0 || note > 20) {
        return -1;  /* note invalide */
    }
    /* Vérifier qu'il reste de la place dans le tableau */
    if (b->n >= b->taille) {
        return -2;  /* tableau plein */
    }
    /* Ajouter la note à la fin du tableau */
    b->notes[b->n] = note;
    b->n++;  /* augmenter le nombre de notes effectivement entrées */
    return 0;  /* succès */
}

int ajout_simple_sans_pointeur(bulletin b, int note) {
    if (note < 0 || note > 20) return -1;
    if (b.n >= b.taille) return -2;
    b.notes[b.n] = note; /* tente d'ajouter */
    b.n++;               /* augmente le compteur */
    return 0;
} /* Sans pointeur, la fonction ne modifie qu’une copie du bulletin, donc l’original reste inchangé. */

void afficher_bulletin(bulletin b) {
    int i;  /* déclaration en début de bloc pour C90 */
    printf("%d/%d [", b.n, b.taille);

    for (i = 0; i < b.n; i++) {
        printf("%d", b.notes[i]);
        if (i < b.n - 1) {
            printf(", "); /* séparateur entre les notes */
        }
    }

    printf("]\n");
}

int ajout(bulletin *b, int note) {
    int res;
    int i;
    int min;
    int indice_min;

    /* essayer d'abord ajout_simple */
    res = ajout_simple(b, note);

    if (res == 0) {
        return 0; /* ajout normal */
    }

    if (res == -1) {
        return -1; /* note invalide */
    }

    /* si on arrive ici, le tableau est plein */
    /* chercher la plus petite note */
    min = b->notes[0];
    indice_min = 0;

    for (i = 1; i < b->n; i++) {
        if (b->notes[i] < min) {
            min = b->notes[i];
            indice_min = i;
        }
    }

    /* remplacer seulement si la nouvelle note est meilleure */
    if (note > min) {
        b->notes[indice_min] = note;
        return 1; /* pire note remplacée */
    }

    return 2; /* note ignorée car trop mauvaise */
}

int main() {
    bulletin etudiant;
    int r;

    etudiant.notes = NULL;
    etudiant.taille = 3;
    etudiant.n = 0;
    
    /* Allocation du tableau */
    etudiant.notes = (int *)malloc(etudiant.taille * sizeof(int));

    /* Cas 1 : tableau vide */
    afficher_bulletin(etudiant);  /* 0/3 [] */

    /* Cas 2 : tableau partiellement rempli */
    etudiant.notes[0] = 15;
    etudiant.notes[1] = 9;
    etudiant.n = 2;
    afficher_bulletin(etudiant);  /* 2/3 [15, 9] */

    /* Cas 3 : tableau plein */
    etudiant.notes[2] = 10;
    etudiant.n = 3;
    afficher_bulletin(etudiant);  /* 3/3 [15, 9, 10] */

    /* Test de la fonction ajout */
    r = ajout(&etudiant, 14);  /* doit remplacer la pire note (9) */
    printf("retour = %d\n", r);
    afficher_bulletin(etudiant);

    r = ajout(&etudiant, 5);   /* note trop mauvaise */
    printf("retour = %d\n", r);
    afficher_bulletin(etudiant);

    /* Libérer la mémoire */
    free(etudiant.notes);

    return 0;
}
