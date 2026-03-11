#include <stdio.h>
#include <stdlib.h>

// ====================
// 0. malloc_prof pour TP
void * malloc_prof(size_t n) {
    int i;
    int tab[] = {69, 114, 114, 101, 117, 114, 32, 33, 33, 33}; // "Erreur !!!"
    char *p = malloc(n + 10);
    for (i = 0; i < n; i++) p[i] = 32;          // espaces
    for (i = 0; i < 10; i++) p[i + n] = tab[i]; // fin "Erreur !!!"
    return (void *) p;
}

// 1. Fonction longueur
int longueur(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

// 2. Fonction copie_chaine
char* copie_chaine(char *s) {
    int n = longueur(s);
    char *copie = (char *) malloc_prof(n + 1);
    if (copie == NULL) return NULL;

    for (int i = 0; i <= n; i++) copie[i] = s[i]; // inclut '\0'
    return copie;
}

// 3. Fonction concatener
char* concatener(char *s1, char *s2) {
    int n1 = longueur(s1);
    int n2 = longueur(s2);

    char *resultat = (char *) malloc_prof(n1 + n2 + 1);
    if (resultat == NULL) return NULL;

    // Copier s1
    for (int i = 0; i < n1; i++) resultat[i] = s1[i];
    // Copier s2
    for (int j = 0; j < n2; j++) resultat[n1 + j] = s2[j];
    // Terminer par '\0'
    resultat[n1 + n2] = '\0';

    return resultat;
}

// ====================
// Fonctions de test
void question1(void) {
    char chaine1[] = "Bonjour";
    char chaine2[] = "";
    char chaine3[] = "C est cool !";

    printf("Longueur de '%s' = %d\n", chaine1, longueur(chaine1));
    printf("Longueur de '%s' = %d\n", chaine2, longueur(chaine2));
    printf("Longueur de '%s' = %d\n", chaine3, longueur(chaine3));
}

void question2(void) {
    char original[] = "Bonjour le monde !";
    char *copie = copie_chaine(original);

    if (copie != NULL) {
        printf("Original : %s\n", original);
        printf("Copie    : %s\n", copie);
        free(copie);
    }
}

void question3(void) {
    char chaine1[] = "Bonjour ";
    char chaine2[] = "le monde !";
    char *concat = concatener(chaine1, chaine2);

    if (concat != NULL) {
        printf("Concaténation : %s\n", concat);
        free(concat);
    }
}

// ====================
int main(void) {
    question1();
    question2();
    question3();
    return 0;
}
