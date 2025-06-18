#include <stdio.h>
#include <stdlib.h>
#include "../include/driver.h"

int check_missing_drivers() {
    printf("[INFO] Recherche des pilotes manquants...\n");

    // Affiche les périphériques sans pilotes à l'aide de pnputil
    int result = system("pnputil /enum-devices /problem:28");

    if (result != 0) {
        fprintf(stderr, "[ERREUR] Échec de la vérification des pilotes (%d)\n", result);
        return 1;
    }

    printf("[OK] Vérification des pilotes terminée.\n");
    return 0;
}

int download_manufacturer_drivers() {
    printf("[INFO] Lancement du téléchargement des pilotes du constructeur...\n");

    // Tentative d'ouvrir l'application constructeur (Dell, HP, Lenovo...)
    int result = 1;

    result = system("start ms-settings:windowsupdate"); // Solution générique

    // Essayons avec quelques outils connus (commentés, à personnaliser selon le constructeur du PC client)
    // result = system("start https://www.intel.com/content/www/us/en/support/intel-driver-support-assistant.html");
    // result = system("start https://www.nvidia.com/Download/index.aspx");
    // result = system("start https://support.hp.com/fr-fr/drivers");

    if (result != 0) {
        fprintf(stderr, "[ERREUR] Impossible d’ouvrir l’outil constructeur (%d)\n", result);
        return 1;
    }

    printf("[OK] Téléchargement des pilotes lancé (via navigateur ou application constructeur).\n");
    return 0;
}
