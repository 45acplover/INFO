#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COGNOME 50
#define MAX_VOTI 8
#define MAX_DATA_NASCITA 11

// Struttura del record
typedef struct {
    char cognome[MAX_COGNOME];
    char dataNascita[MAX_DATA_NASCITA]; // formato: "gg/mm/aaaa"
    int voti[MAX_VOTI];
} Record;

// Funzione per inserire record nel file
void inserisciRecord(char fileName[], int numRecord) {
    FILE *file = fopen(fileName, "ab"); // "ab" per apertura in modalità append (crea il file se non esiste)
    if (file == NULL) {
        printf("Errore nell'aprire il file.\n");
        return;
    }

    Record nuovoRecord;
    for (int i = 0; i < numRecord; i++) {
        printf("Inserisci i dati per il record %d:\n", i + 1);

        // Inserimento cognome
        printf("Cognome: ");
        scanf("%s", nuovoRecord.cognome);

        // Inserimento data di nascita
        printf("Data di nascita (gg/mm/aaaa): ");
        scanf("%s", nuovoRecord.dataNascita);

        // Inserimento voti
        printf("Inserisci i 8 voti: ");
        for (int j = 0; j < MAX_VOTI; j++) {
            scanf("%d", &nuovoRecord.voti[j]);
        }

        fwrite(&nuovoRecord, sizeof(Record), 1, file); // Scrive il record nel file
    }

    fclose(file);
}

// Funzione per stampare tutti i record del file
void stampaFile(char fileName[]) {
    FILE *file = fopen(fileName, "rb"); // "rb" per apertura in modalità lettura binaria
    if (file == NULL) {
        printf("Il file non esiste.\n");
        return;
    }

    Record r;
    int count = 1;
    while (fread(&r, sizeof(Record), 1, file)) {
        printf("Record %d: %s, %s, Voti: ", count++, r.cognome, r.dataNascita);
        for (int i = 0; i < MAX_VOTI; i++) {
            printf("%d ", r.voti[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Funzione per calcolare l'età da una data di nascita
int calcolaEta(char dataNascita[]) {
    struct tm tm;
    time_t t = time(NULL);
    struct tm *oggi = localtime(&t);

    strptime(dataNascita, "%d/%m/%Y", &tm); // Converte la data in struct tm
    int eta = oggi->tm_year + 1900 - tm.tm_year;
    if (oggi->tm_mon + 1 < tm.tm_mon || (oggi->tm_mon + 1 == tm.tm_mon && oggi->tm_mday < tm.tm_mday)) {
        eta--; // Se non è ancora passata la data di compleanno
    }
    return eta;
}

// Funzione per calcolare la media dei voti
float calcolaMedia(int voti[]) {
    int somma = 0;
    for (int i = 0; i < MAX_VOTI; i++) {
        somma += voti[i];
    }
    return (float)somma / MAX_VOTI;
}

// Funzione per ricercare un record per cognome
int ricercaRecord(char fileName[], char cognome[]) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Il file non esiste.\n");
        return -1;
    }

    Record r;
    int posizione = 0;
    while (fread(&r, sizeof(Record), 1, file)) {
        if (strcmp(r.cognome, cognome) == 0) {
            printf("Record trovato: %s, Età: %d, Media voti: %.2f\n", r.cognome, calcolaEta(r.dataNascita), calcolaMedia(r.voti));
            fclose(file);
            return posizione;
        }
        posizione++;
    }

    printf("Record non trovato.\n");
    fclose(file);
    return -1;
}

// Funzione per stampare un record specifico dato un indice
int stampaRecord(char fileName[], int posizione) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Il file non esiste.\n");
        return -1;
    }

    Record r;
    fseek(file, posizione * sizeof(Record), SEEK_SET);
    if (fread(&r, sizeof(Record), 1, file)) {
        printf("Record %d: %s, %s, Voti: ", posizione + 1, r.cognome, r.dataNascita);
        for (int i = 0; i < MAX_VOTI; i++) {
            printf("%d ", r.voti[i]);
        }
        printf("\n");
        fclose(file);
        return 0;
    }

    fclose(file);
    return -1;
}

int main() {
    int scelta, numRecord, posizione;
    char fileName[] = "records.dat";
    char cognome[MAX_COGNOME];

    do {
        printf("\nMenu:\n");
        printf("1. Inserisci record\n");
        printf("2. Stampa file\n");
        printf("3. Ricerca record per cognome\n");
        printf("4. Stampa record per posizione\n");
        printf("5. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Quanti record vuoi inserire? ");
                scanf("%d", &numRecord);
                inserisciRecord(fileName, numRecord);
                break;

            case 2:
                stampaFile(fileName);
                break;

            case 3:
                printf("Inserisci il cognome da cercare: ");
                scanf("%s", cognome);
                posizione = ricercaRecord(fileName, cognome);
                if (posizione == -1) {
                    printf("Nessun record trovato.\n");
                }
                break;

            case 4:
                printf("Inserisci la posizione del record da stampare: ");
                scanf("%d", &posizione);
                if (stampaRecord(fileName, posizione) == -1) {
                    printf("Record non trovato.\n");
                }
                break;

            case 5:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Opzione non valida!\n");
        }
    } while (scelta != 5);

    return 0;
}