#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "driver.h"
#include "optimize.h"
#include "scan.h"
#include "update.h"
#include "upgrade.h"
#include "defrag.h"
#include "repair.h"

void clear_screen() {
    system("cls"); // Pour Windows — remplace par "clear" si tu veux tester sous Linux
}

void wait_for_key() {
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar(); // Double getchar pour absorber '\n'
}

int main() {
    int choix;

    do {
        clear_screen();
        afficher_menu();

        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                install_updates();
                break;
            case 2:
                optimize_memory();
                optimize_startup();
                break;
            case 3:
                check_missing_drivers();
                download_manufacturer_drivers();
                break;
            case 4:
                scan_system();
                break;
            case 5:
                repair_system_files();
                break;
            case 6:
                defragment_disk();
                break;
            case 7:
                upgrade_windows_10_to_11();
                break;
            case 0:
                printf("\nFermeture de l'optimiseur...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        if (choix != 0)
            wait_for_key();

    } while (choix != 0);

    return 0;
}
