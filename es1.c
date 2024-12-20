#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    int cateto1 = 3, cateto2 = 4;
    pid_t pid;

    
    pid = fork();

    if (pid < 0) {
        
        perror("Errore nel fork");
        exit(1);
    }

    if (pid == 0) {
        
        float ipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
        float perimetro = cateto1 + cateto2 + ipotenusa;
        printf("Processo figlio: Il perimetro del triangolo è: %.2f\n", perimetro);
    } else {
        
        float area = 0.5 * cateto1 * cateto2;
        printf("Processo padre: L'area del triangolo è: %.2f\n", area);

        wait(NULL);

        
        
    }

    return 0;
}