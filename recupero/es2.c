#include<stdio.h>
#include<string.h>

#define N 10

typedef struct Persona
{
    char cognome[20];
    int voti[N]
}Persona;

void carica(Persona St[]);
void stampa(Persona St[]);  
int visualizzaMedia(Persona St[ ], char cog[ ]); 
int votoMassimo(Persona St[]);  
int indiceVotoMassimo (Persona St[]);  

int main()
{
    Persona pers;
    carica(Persona St[]);
    stampa(Persona St[]);
}