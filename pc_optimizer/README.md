# PC Optimizer Console - Outil de maintenance Windows

---

## Description

PC Optimizer Console est un utilitaire open-source développé en langage C pour Windows.
Il offre un ensemble complet de fonctionnalités pour :

- Installer les mises à jour Windows (y compris upgrade forcée de Windows 10 vers 11 sur matériel incompatible)
- Rechercher et installer automatiquement les pilotes manquants du constructeur
- Scanner l’intégrité du système avec les outils natifs (`sfc`, `chkdsk`)
- Optimiser le PC en nettoyant les fichiers temporaires et en désactivant les services inutiles
- Réparer et défragmenter le disque dur
- Fournir une interface menu simple en console pour accéder à toutes ces fonctions

L’objectif est de fournir un outil léger, facilement compilable, sans dépendances externes, fonctionnant en ligne de commande.

---

![Build](https://github.com/<roussov>/<pc_optimizer>/actions/workflows/build.yml/badge.svg)
![Release](https://github.com/<roussov>/<pc_optimizer>/actions/workflows/release.yml/badge.svg)

---

## Modules détaillés

- **update** : gestion des mises à jour Windows, y compris upgrade forcée 10→11 via script batch
- **driver** : recherche et installation des pilotes manquants via `pnputil`, ouverture Gestionnaire de périphériques, Windows Update
- **scan** : lance `sfc /scannow` et `chkdsk` pour vérifier l’intégrité du système et du disque
- **optimize** : nettoyage des fichiers temporaires, vidage corbeille, désactivation de services Windows jugés inutiles
- **defrag** : (à compléter) gestion de la défragmentation du disque via commandes Windows natives
- **upgrade** : script batch intégré pour forcer l’upgrade Windows 11 même sur matériel incompatible
- **menu** : interface texte simple, gestion du menu principal, appels aux autres modules

---

## Prérequis

- Environnement Windows 10 ou 11
- Compilateur GCC (MinGW-w64, MSYS2 ou similaire)
- PowerShell (préinstallé sur Windows modernes)
- NSIS (optionnel, pour générer l’installeur)

---

## Compilation

1. Ouvrir un terminal compatible (PowerShell, MSYS2 shell, CMD avec MinGW)
2. Placer le répertoire du projet
3. Utiliser les commandes Make :


make           # Compilation debug avec symboles
make release   # Compilation optimisée
make clean     # Nettoyage des fichiers objets et binaires
make run       # Compile puis lance le programme

---
## Affichage Console

========== PC Optimizer Console ==========
1. Installer les mises à jour Windows
2. Optimiser le système
3. Rechercher les pilotes manquants
4. Scanner l'ordinateur
5. Réparer les fichiers système
6. Défragmenter le disque
7. Mettre à jour vers Windows 11
0. Quitter

## Arborescence du projet

```text
pc_optimizer_console/
├── Makefile
├── README.md
├── include/
│   ├── update.h
│   ├── driver.h
│   ├── scan.h
│   ├── optimize.h
│   ├── defrag.h
│   ├── upgrade.h
│   └── menu.h
├── src/
│   ├── main.c
│   ├── update.c
│   ├── driver.c
│   ├── scan.c
│   ├── optimize.c
│   ├── defrag.c
│   ├── upgrade.c
│   └── menu.c
├── assets/
│   └── MediaCreationTool.bat
└── install/
    └── installer.nsi

# Dossiers créés à la compilation (exclure de la source, ajoutés par Makefile)
build/
├── obj/
│   └── *.o          # fichiers objets compilés
└── bin/
    └── pc_optimizer.exe
