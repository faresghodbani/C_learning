#include <stdio.h>
#include <stdlib.h>

struct cellule {
    int contenu;
    struct cellule *suivant;
};

typedef struct cellule* liste_chainee;

liste_chainee nouvelle_lc()
{
    return NULL;
}

int est_vide(liste_chainee L)
{
    return L == NULL;
}

int head(liste_chainee L)
{
    return L->contenu;
}

liste_chainee tail(liste_chainee L)
{
    return L->suivant;
}

liste_chainee ajout_lc(int x, liste_chainee L)
{
    liste_chainee nouvelle = malloc(sizeof(struct cellule));

    nouvelle->contenu = x;
    nouvelle->suivant = L;

    return nouvelle;
}

void liberer_lc(liste_chainee L)
{
    if (L != NULL)
    {
        liberer_lc(L->suivant);
        free(L);
    }
}

int main()
{
    liste_chainee L = nouvelle_lc();

    L = ajout_lc(3, L);
    L = ajout_lc(2, L);
    L = ajout_lc(1, L);

    printf("Premier element: %d\n", head(L));
    printf("Premier element après tail: %d\n", head(tail(L)));
    liberer_lc(L);
    return 0;
}
