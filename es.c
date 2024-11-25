#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    char cognome[50];
    int voti[5]; // 5 voti per ogni studente
} Studente;

// Funzione per scrivere un file di N record
void scriviFile(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "wb");
    if (file == NULL) {
        perror("Errore apertura file");
        exit(1);
    }

    Studente studenti[N] = {
        {"Rossi", {8, 3, 7, 9, 6}},
        {"Bianchi", {8, 2, 9, 2, 4}},
        {"Verdi", {5, 7, 8, 4, 6}},
        {"Neri", {3, 5, 8, 6, 7}},
        {"Gialli", {3, 5, 4, 6, 7}},
        {"Blu", {2, 8, 7, 3, 4}},
        {"Viola", {9, 8, 7, 3, 3}},
        {"Arancioni", {9, 2, 7, 8, 3}},
        {"Grigi", {4, 6, 8, 9, 5}},
        {"Marroni", {8, 2, 5, 7, 9}}
    };

    fwrite(studenti, sizeof(Studente), N, file);
    fclose(file);
}

// Funzione per leggere e stampare i record dal file
void leggiFile(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "rb");
    if (file == NULL) {
        perror("Errore apertura file");
        exit(1);
    }

    Studente s;
    while (fread(&s, sizeof(Studente), 1, file) == 1) {
        printf("Cognome: %s\n", s.cognome);
        printf("Voti: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", s.voti[i]);
        }
        printf("\n\n");
    }

    fclose(file);
}

// Funzione per contare gli studenti con un dato cognome
int contaCognome(const char *nomeFile, const char *cognome) {
    FILE *file = fopen(nomeFile, "rb");
    if (file == NULL) {
        perror("Errore apertura file");
        exit(1);
    }

    Studente s;
    int count = 0;
    while (fread(&s, sizeof(Studente), 1, file) == 1) {
        if (strcmp(s.cognome, cognome) == 0) {
            count++;
        }
    }

    fclose(file);
    return count;
}

// Funzione per calcolare e visualizzare le statistiche per ogni studente
void visualizzaStatistiche(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "rb");
    if (file == NULL) {
        perror("Errore apertura file");
        exit(1);
    }

    Studente s;
    while (fread(&s, sizeof(Studente), 1, file) == 1) {
        int somma = 0, max = s.voti[0], min = s.voti[0];
        for (int i = 0; i < 5; i++) {
            somma += s.voti[i];
            if (s.voti[i] > max) max = s.voti[i];
            if (s.voti[i] < min) min = s.voti[i];
        }

        printf("Cognome: %s\n", s.cognome);
        printf("Media voti: %.2f\n", somma / 5.0);
        printf("Voto più alto: %d\n", max);
        printf("Voto più basso: %d\n\n", min);
    }

    fclose(file);
}

// Main per collaudare le funzioni
int main() {
    const char *nomeFile = "studenti.dat";

    scriviFile(nomeFile);
    printf("Contenuto del file:\n");
    leggiFile(nomeFile);

    const char *cognomeDaCercare = "Rossi";
    int count = contaCognome(nomeFile, cognomeDaCercare);
    printf("\nIl cognome '%s' è presente %d volte.\n", cognomeDaCercare, count);

    printf("\nStatistiche per ogni studente:\n");
    visualizzaStatistiche(nomeFile);

    return 0;
}