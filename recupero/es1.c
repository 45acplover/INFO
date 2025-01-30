#include <stdio.h>
#include <string.h>

#define N 10

typedef struct data{
    int giorno;
    char mese[15];
    int anno;
}data;

typedef struct persona{
    char cognome[20];
    data nascita;
    int voti[N];
}persona;



int main()
{
    persona dave, james;
    int cont=0;
    float media=0;
    int i;

    printf("inserire cognome");
    scanf("%s", dave.cognome);

    printf("inserire nascita");
    scanf("%d", &dave.nascita.giorno);
    scanf("%s", dave.nascita.mese);
    scanf("%d", &dave.nascita.anno);

    for(i=0; i<N; i++)
    {
        printf("inserisci voti");
        scanf("%d", &dave.voti[i]);
        cont+= dave.voti[i];
        media= cont/N;

    }

    printf("cognome: %s", dave.cognome);
    printf("%d %s %d", dave.nascita.giorno, dave.nascita.mese, dave.nascita.anno);
    printf("%f", media);

    int eta= 2025-dave.nascita.anno;
    printf("eta nel 2025: %d", eta);

    strcmp(dave.cognome,"rossi");
    dave.nascita.giorno = james.nascita.giorno;
    strcpy(dave.nascita.mese, james.nascita.mese);
    dave.nascita.anno = james.nascita.anno;


    
    


}