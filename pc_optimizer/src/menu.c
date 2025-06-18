#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "update.h"
#include "driver.h"
#include "scan.h"
#include "optimize.h"
#include "defrag.h"
#include "upgrade.h"

void show_menu() {
    int choix;
    do {
        printf("\n==== PC Optimizer Console ====\n");
        printf("1. Mettre à jour Windows\n");
        printf("2. Rechercher les pilotes manquants\n");
        printf("3. Scanner l'ordinateur\n");
        printf("4. Optimiser le PC\n");
        printf("5. Défragmenter le disque\n");
        printf("6. Upgrade vers Windows 11\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: update_function(); break;
            case 2: driver_function(); break;
            case 3: scan_function(); break;
            case 4: optimize_function(); break;
            case 5: defrag_function(); break;
            case 6: upgrade_to_windows11(); break;
            case 0: break;
            default: printf("Choix invalide\n");
        }
    } while (choix != 0);
}
