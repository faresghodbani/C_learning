#include <stdio.h>

void affiche_tableau(int tab[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void question1(void) {
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    affiche_tableau(tab, 10);
}

void vider_buffer() {
    char c;
    while ( (c = getchar()) != '\n' && c != EOF);
}

int lire_entier() {
    int n = 0;
    char c;
    printf("entier> ");
    while ( (c = getchar()) != '\n' && c != EOF) {
        if ('0' <= c && c <= '9') {
            n = n*10 + (c-'0');
        } else {
            vider_buffer();
            return -1;
        }
    }
    return n;
}


/*int main(void) {
    question1();
    return 0;
}*/


int saisie_tab(int tableau[], int n) {
    int i = 0;
    int val;
    while (i < n) {
        val = lire_entier();
        if (val == -1) {
            break;
        }
        tableau[i++] = val;
    }
    return i;
}

int main(void) {
    int tableau[100];
    int n;
    int i;
    n = saisie_tab(tableau, 100);
    printf("Le tableau lu est [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("]\n");

    return 0;
}

