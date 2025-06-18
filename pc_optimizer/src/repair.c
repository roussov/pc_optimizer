#include <stdio.h>
#include <stdlib.h>
#include "../include/repair.h"

int repair_system_files() {
    printf("[INFO] Lancement de la réparation du système...\n");

    printf("[SFC] Vérification de l'intégrité des fichiers système...\n");
    int sfc_result = system("sfc /scannow");

    if (sfc_result != 0) {
        printf("[DISM] SFC a échoué. Tentative de réparation via DISM...\n");
        int dism_result = system("DISM /Online /Cleanup-Image /RestoreHealth");

        if (dism_result != 0) {
            fprintf(stderr, "[ERREUR] La réparation DISM a échoué (%d)\n", dism_result);
            return 1;
        }

        printf("[OK] DISM terminé. Relance de SFC...\n");
        sfc_result = system("sfc /scannow");
        if (sfc_result != 0) {
            fprintf(stderr, "[ERREUR] SFC a échoué après DISM (%d)\n", sfc_result);
            return 1;
        }
    }

    printf("[OK] Réparation du système terminée avec succès.\n");
    return 0;
}
