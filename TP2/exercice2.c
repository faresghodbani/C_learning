#include <stdio.h>
#include <stdlib.h>

struct horaire_struct{
    short heures;
    short minutes;
    short secondes;
};

typedef struct horaire_struct horaire;

horaire nouvel_horaire(short h, short m,short s) {
    horaire a;
    if(h>=0 && h<=24 && m<=60 && s>0 && s<=60) {
        a.heures = h;
        a.minutes = m;
        a.secondes = s;
        return a;
    }
    else{
        printf("IMPOSSIBLE !!!\n");
        exit(1);
    }
}

int main(void){
    nouvel_horaire(10,5,4);
    return 0;
}

