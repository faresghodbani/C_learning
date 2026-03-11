#include <stdio.h>
#include <stdlib.h>

/* fonction qui affiche un fichier ligne par ligne */
void numeroter(FILE *fichier, int *numero)
{
    char ligne[1024];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        fprintf(stdout, "%d:%s", *numero, ligne);
        (*numero)++;
    }
}

int main(int nbArguments, char *arguments[])
{
    FILE *fichier;
    int i;
    int numero = 1;

    /* aucun fichier → lecture entrée standard */
    if (nbArguments == 1)
    {
        numeroter(stdin, &numero);
    }
    else
    {
        for (i = 1; i < nbArguments; i++)
        {
            fichier = fopen(arguments[i], "r");
            if (fichier == NULL)
            {
                fprintf(stderr, "Erreur lecture %s\n", arguments[i]);
                return 1;
            }
            numeroter(fichier, &numero);
            fclose(fichier);
        }
    }
    return 0;
}
