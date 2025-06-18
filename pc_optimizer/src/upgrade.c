#include "upgrade.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void upgrade_to_windows11() {
    MessageBox(NULL, "Lancement de l'upgrade vers Windows 11 (même sur machine incompatible)...", "Mise à niveau", MB_OK | MB_ICONINFORMATION);

    // Télécharger le script MediaCreationTool.bat (ou l’inclure dans le projet)
    system("powershell -Command \"Invoke-WebRequest -Uri https://raw.githubusercontent.com/AveYo/MediaCreationTool.bat/main/MediaCreationTool.bat -OutFile %TEMP%\\MediaCreationTool.bat\"");

    // Lancer avec options d'upgrade forcée
    system("cmd /c %TEMP%\\MediaCreationTool.bat auto 11");

    // Attention : cela ouvre une fenêtre d’installation officielle
}
