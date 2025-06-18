#include "optimize.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void optimize_function() {
    printf("\n[⚙️] Optimisation du PC en cours...\n");

    // Nettoyer les fichiers temporaires Windows
    printf("Suppression des fichiers temporaires...\n");
    system("del /q/f/s %TEMP%\\*");
    system("del /q/f/s C:\\Windows\\Temp\\*");

    // Nettoyage de la corbeille
    printf("Vidage de la corbeille...\n");
    system("PowerShell -Command Clear-RecycleBin -Force");

    // Désactivation de services inutiles (exemples)
    printf("Désactivation des services inutiles...\n");

    // Exemple : arrêt du service de fax (s'il existe)
    system("sc stop Fax");
    system("sc config Fax start= disabled");

    // Exemple : désactivation de Windows Search (indexation)
    system("sc stop WSearch");
    system("sc config WSearch start= disabled");

    printf("[✔️] Optimisation terminée.\n");
}
