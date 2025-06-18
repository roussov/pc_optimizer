Outfile "PC_Optimizer_Installer.exe"
InstallDir "$PROGRAMFILES\\PC_Optimizer"
RequestExecutionLevel admin

Page directory
Page instfiles

Section "Installer"
  SetOutPath $INSTDIR
  File "..\\bin\\pc_optimizer.exe"
  File "..\\assets\\MediaCreationTool.bat"
  CreateShortcut "$DESKTOP\\PC Optimizer.lnk" "$INSTDIR\\pc_optimizer.exe"
  CreateDirectory "$SMPROGRAMS\\PC Optimizer"
  CreateShortcut "$SMPROGRAMS\\PC Optimizer\\PC Optimizer.lnk" "$INSTDIR\\pc_optimizer.exe"
SectionEnd

Section "Désinstaller"
  Delete "$INSTDIR\\pc_optimizer.exe"
  Delete "$INSTDIR\\MediaCreationTool.bat"
  Delete "$DESKTOP\\PC Optimizer.lnk"
  Delete "$SMPROGRAMS\\PC Optimizer\\PC Optimizer.lnk"
  RMDir "$SMPROGRAMS\\PC Optimizer"
  RMDir "$INSTDIR"
SectionEnd
