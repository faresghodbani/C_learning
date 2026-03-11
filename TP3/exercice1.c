#include <stdio.h>

// 1. Fonction qui incrémente un entier pointé
void incremente(int *a) {
    (*a)++;
}

// 2. Fonction qui échange les valeurs pointées
void echange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. Fonction qui trie deux valeurs
// Met la plus petite dans a et la plus grande dans b
// Renvoie 1 si un échange a eu lieu, 0 sinon
int trier(int *a, int *b) {
    if (*a > *b) {
        echange(a, b);
        return 1; // échange effectué
    }
    return 0; // pas d'échange
}

// Fonction de test pour exo1
void test_exo1(void) {
    int x = 4, y = 3;

    printf("Avant incremente : x = %d\n", x);
    incremente(&x);
    printf("Après incremente : x = %d\n", x);

    printf("Avant echange : x = %d, y = %d\n", x, y);
    echange(&x, &y);
    printf("Après echange : x = %d, y = %d\n", x, y);

    int a = 10, b = 5;
    printf("Avant trier : a = %d, b = %d\n", a, b);
    int res = trier(&a, &b);
    printf("Après trier : a = %d, b = %d (échange = %d)\n", a, b, res);
}

int main(void) {
    test_exo1();
    return 0;
}
