#include "scan.h"
#include <stdio.h>
#include <stdlib.h>

void scan_function() {
    printf("\n[🔍] Lancement des scans système...\n");

    // Lancer SFC (System File Checker)
    printf("Exécution de sfc /scannow (vérification fichiers système)...\n");
    system("sfc /scannow");

    // Lancer CHKDSK (vérification disque, ici sans réparation automatique)
    printf("Exécution de chkdsk C: /scan (analyse disque)...\n");
    system("chkdsk C: /scan");

    // Pour réparation automatique, on pourrait demander redémarrage avec /f /r
    printf("\nSi des erreurs sont détectées, un redémarrage peut être nécessaire pour réparation.\n");
}
