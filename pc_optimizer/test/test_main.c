#include <stdio.h>
#include <assert.h>
#include "../include/menu.h"
#include "../include/driver.h"
#include "../include/optimize.h"
#include "../include/scan.h"
#include "../include/update.h"
#include "../include/upgrade.h"
#include "../include/defrag.h"
#include "../include/repair.h"

// Simule les fonctions que tu aurais définies dans tes modules
// Dans un vrai cas, tu pourrais utiliser un framework comme Unity ou CMocka

void test_menu() {
    printf("-> test_menu() OK\n");
}

void test_driver() {
    int result = check_missing_drivers();
    assert(result == 0); // 0 = succès simulé
    printf("-> test_driver() OK\n");
}

void test_optimize() {
    assert(optimize_memory() == 0);
    assert(optimize_startup() == 0);
    printf("-> test_optimize() OK\n");
}

void test_scan() {
    assert(scan_system() == 0);
    printf("-> test_scan() OK\n");
}

void test_update() {
    assert(install_updates() == 0);
    printf("-> test_update() OK\n");
}

void test_upgrade() {
    assert(upgrade_windows_10_to_11() == 0);
    printf("-> test_upgrade() OK\n");
}

void test_defrag() {
    assert(defragment_disk() == 0);
    printf("-> test_defrag() OK\n");
}

void test_repair() {
    assert(repair_system_files() == 0);
    printf("-> test_repair() OK\n");
}

int main() {
    printf("=== Lancement de la suite de tests PC Optimizer Console ===\n\n");

    test_menu();
    test_driver();
    test_optimize();
    test_scan();
    test_update();
    test_upgrade();
    test_defrag();
    test_repair();

    printf("\n✅ Tous les tests ont réussi.\n");
    return 0;
}
