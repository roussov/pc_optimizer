#include "update.h"
#include <stdlib.h>

void check_windows_update() {
    system("powershell -Command \"Get-WindowsUpdate\"");
}

void install_pending_updates() {
    system("powershell -Command \"Install-WindowsUpdate -AcceptAll -AutoReboot\"");
}
